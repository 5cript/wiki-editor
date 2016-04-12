#include "table.hpp"

#include "wretched-css/rule_set/rule/property/value/color.hpp"

#include <QPainter>
#include <QStyleOptionFocusRect>
#include <QPalette>
#include <QStyle>
#include <QDebug>
#include <QFile>

#include <algorithm>
#include <string>

//-----------------------------------------------------------------------------------
WikiTableModel::WikiTableModel(QObject* parent, const WikiMarkup::Components::Table& table)
    : QAbstractTableModel(parent)
    , table_(table)
{
    parseStyle();
}
//-----------------------------------------------------------------------------------
int WikiTableModel::rowCount(QModelIndex const&) const
{
    return table_.rows.size();
}
//-----------------------------------------------------------------------------------
int WikiTableModel::columnCount(QModelIndex const&) const
{
    if (table_.rows.empty())
        return 0;
    return table_.rows.front().cells.size();
}
//-----------------------------------------------------------------------------------
QVariant WikiTableModel::data(QModelIndex const& index, int role) const
{
    int row = index.row();
    int col = index.column();

    auto cell = table_.rows[row].cells[col];

    bool hasCellCss = false;
    WretchedCss::RuleSet cellCss;

    try
    {
        if (cell.attributes.find("style") != cell.attributes.end())
        {
            cellCss.fromCss("#tableCell {" + cell.attributes.find("style")->second + "}");
            hasCellCss = true;
        }
    }
    catch (std::exception const& exc)
    {
        qWarning() << exc.what();
    }

    switch (role)
    {
        case(Qt::DisplayRole):
        {
            return QString::fromStdString(cell.data);
        }
        case(Qt::FontRole):
        {
            boost::optional <WretchedCss::Property> family;
            boost::optional <WretchedCss::Property> weight;
            boost::optional <WretchedCss::Property> size;

            if (hasCellCss)
            {
                qDebug() << "cellcss";

                family = cellCss["#tableCell"]["font-family"];
                weight = cellCss["#tableCell"]["font-weight"];
                size = cellCss["#tableCell"]["font-size"];
            }
            else if (cell.isHeaderCell)
            {
                qDebug() << "selector: " << tableWideStyle_[".wikitable.headers"].selector.selector.c_str();

                family = tableWideStyle_[".wikitable.headers"]["font-family"];
                weight = tableWideStyle_[".wikitable.headers"]["font-weight"];
                size = tableWideStyle_[".wikitable.headers"]["font-size"];
            }
            else
            {
                qDebug() << ".wikitable";

                family = tableWideStyle_[".wikitable"]["font-family"];
                weight = tableWideStyle_[".wikitable"]["font-weight"];
                size = tableWideStyle_[".wikitable"]["font-size"];
            }

            std::string fam = family ? family.get().values[0]->toString() : "Times";
            std::string wg = weight ? weight.get().values[0]->toString() : "normal";
            std::string sz = size ? size.get().values[0]->toString() : "100";
            std::transform(wg.begin(), wg.end(), wg.begin(), ::tolower);

            return QVariant{QFont(QString::fromStdString(fam), std::stol(sz), wg == "bold" ? QFont::Bold : QFont::Normal)};
        }
        case(Qt::BackgroundRole):
        {
            boost::optional <WretchedCss::Property> color;

            if (hasCellCss)
                color = cellCss["#tableCell"]["background-color"];
            else if (cell.isHeaderCell)
                color = tableWideStyle_[".wikitable.headers"]["background-color"];
            else
                color = tableWideStyle_[".wikitable"]["background-color"];

            if (color)
            {
                auto* actualColor = dynamic_cast <WretchedCss::ValueTypes::Color*> (color.get().values[0].get());
                return QVariant{QColor{
                    actualColor->r,
                    actualColor->g,
                    actualColor->b
                }};
            }

            //return QVariant(QColor(Qt::yellow));
            return QVariant();
        }
        case(Qt::TextAlignmentRole):
        {
            return QVariant();
        }
        case(Qt::CheckStateRole):
        {
            return QVariant();
        }
        default:
            return QVariant();
    }
}
//-----------------------------------------------------------------------------------
QVariant WikiTableModel::headerData(int, Qt::Orientation, int) const
{
    return QVariant(); // no header
}
//-----------------------------------------------------------------------------------
bool WikiTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::EditRole)
    {
        table_.rows[row].cells[col].data = value.toString().toStdString();
    }
    return true;
}
//-----------------------------------------------------------------------------------
Qt::ItemFlags WikiTableModel::flags(const QModelIndex &) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
//-----------------------------------------------------------------------------------
void WikiTableModel::parseStyle()
{
    std::string style = "";

    auto maybeClass = table_.attributes.find("class");
    if (maybeClass != std::end(table_.attributes))
    {
        QFile file(":/css/wikitable.css");
        file.open(QFile::ReadOnly);
        style += QString(QLatin1String(file.readAll())).toStdString();
        style.push_back('\n');
    }

    tableWideStyle_.fromCss(style);

    auto maybeStyle = table_.attributes.find("style");
    if (maybeStyle != std::end(table_.attributes))
    {
        tableWideStyle_.eraseRule(".wikitable");

        std::string customStyle = ".wikitable {\n\t";
        customStyle += maybeStyle->second;
        customStyle += "\n}\n";

        tableWideStyle_.addCss(customStyle);
    }
}
//-----------------------------------------------------------------------------------
void WikiTableModel::setTable(WikiMarkup::Components::Table const& table)
{
    table_ = table;

    parseStyle();
}
//-----------------------------------------------------------------------------------

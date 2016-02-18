#include "table.hpp"

#include <QPainter>
#include <QStyleOptionFocusRect>
#include <QPalette>
#include <QStyle>

//-----------------------------------------------------------------------------------
WikiTableModel::WikiTableModel(QObject* parent, const WikiMarkup::Components::Table& table)
    : QAbstractTableModel(parent)
    , table_(table)
{

}
//-----------------------------------------------------------------------------------
int WikiTableModel::rowCount(QModelIndex const&) const
{
    return table_.rows.size();
}
//-----------------------------------------------------------------------------------
int WikiTableModel::columnCount(QModelIndex const&) const
{
    std::size_t max = 0;
    for (auto const& i : table_.rows)
    {
        if (i.cells.size() > max)
            max = i.cells.size();
    }
    return max;
}
//-----------------------------------------------------------------------------------
QVariant WikiTableModel::data(QModelIndex const& index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role)
    {
        case(Qt::DisplayRole):
        {
            return QString::fromStdString(table_.rows[row].cells[col].data);
        }
        case(Qt::FontRole):
        {
            return QVariant();
        }
        case(Qt::BackgroundRole):
        {
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
QVariant WikiTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                    return QString("first");
                case 1:
                    return QString("second");
                case 2:
                    return QString("third");
            }
        }
    }
    return QVariant();
}
//-----------------------------------------------------------------------------------
bool WikiTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
    }
    return true;
}
//-----------------------------------------------------------------------------------
Qt::ItemFlags WikiTableModel::flags(const QModelIndex & index) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
//-----------------------------------------------------------------------------------
void WikiTableModel::setTable(WikiMarkup::Components::Table const& table)
{
    table_ = table;
}

//-----------------------------------------------------------------------------------

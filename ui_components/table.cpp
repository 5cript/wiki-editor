#include "table.hpp"

#include <QPainter>
#include <QStyleOptionFocusRect>
#include <QPalette>
#include <QStyle>
#include <QDebug>

//-----------------------------------------------------------------------------------
WikiTableModel::WikiTableModel(QObject* parent, const WikiMarkup::Components::Table& table)
    : QAbstractTableModel(parent)
    , table_(table)
{

}
//-----------------------------------------------------------------------------------
int WikiTableModel::rowCount(QModelIndex const&) const
{

}
//-----------------------------------------------------------------------------------
int WikiTableModel::columnCount(QModelIndex const&) const
{
    std::size_t max = 0;
    for (auto const& i : table_.rows)
    {
        std::size_t count = 0;
        for (auto const& cell : i.cells)
        {
            if (!cell.isHeaderCell)
                count++;
        }
        if (count > max)
            max = count;
    }
    qDebug() << max;
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
            return QString("H");
        }
    }
    return QVariant();
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

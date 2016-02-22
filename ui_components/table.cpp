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
            return QVariant(QColor(Qt::yellow));
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
void WikiTableModel::setTable(WikiMarkup::Components::Table const& table)
{
    table_ = table;
}
//-----------------------------------------------------------------------------------

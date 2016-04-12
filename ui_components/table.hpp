#ifndef TABLE_HPP
#define TABLE_HPP

#include <QTableView>

#include "wiki-markup/components/table.hpp"
#include "wretched-css/rule_set/rule_set.hpp"

using TableView = QTableView;

class WikiTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    WikiTableModel(QObject* parent = nullptr, WikiMarkup::Components::Table const& table = {});
    int rowCount(QModelIndex const& parent = QModelIndex()) const;
    int columnCount(QModelIndex const& = QModelIndex()) const;
    QVariant data(QModelIndex const& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

    void setTable(WikiMarkup::Components::Table const& table);
    void parseStyle();

private:
    WretchedCss::RuleSet tableWideStyle_;
    WikiMarkup::Components::Table table_;
    std::string tableStyle_;
};

#endif // TABLE_HPP

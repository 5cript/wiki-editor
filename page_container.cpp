#include "page_container.hpp"

//####################################################################################
WikiMarkup::Page& PageContainer::getPage()
{
    return page_;
}
//-----------------------------------------------------------------------------------
WikiMarkup::Page PageContainer::getPage() const
{
    return page_;
}
//-----------------------------------------------------------------------------------
WikiTableModel& PageContainer::createNewTable(WikiMarkup::Components::Table const& table)
{
    tables_.emplace_back(new WikiTableModel{nullptr, table});
    return *tables_.back().get();
}
//####################################################################################

#ifndef PAGECONTAINER_HPP
#define PAGECONTAINER_HPP

#include "wiki-markup/page.hpp"
#include "wiki-markup/components/components.hpp"

#include "ui_components/text.hpp"
#include "ui_components/header.hpp"
#include "ui_components/table.hpp"

#include <string>
#include <vector>
#include <memory>

class PageContainer
{
public:
    PageContainer() = default;
    ~PageContainer() = default;

    PageContainer(PageContainer const&) = delete;
    operator=(PageContainer const&) = delete;

    WikiMarkup::Page getPage() const;
    WikiMarkup::Page& getPage();
    WikiTableModel& createNewTable(WikiMarkup::Components::Table const& table);

private:
    WikiMarkup::Page page_;
    std::vector <std::unique_ptr <WikiTableModel>> tables_;
};

#endif // PAGECONTAINER_HPP

#ifndef COMPONENTBUILDER_H
#define COMPONENTBUILDER_H

#include "page_container.hpp"

#include <QWidget>
#include <QLabel>
#include <QLayout>

#include <string>
#include <vector>

class PageBuilder
{
public:
    /**
     * Loads markup from a string and generates a page.
     * Does not automatically generate ui elements.
     *
     * @param markup Some markup data.
     */
    void loadMarkup(std::string const& markup);

    /**
     * Converts the page into markup.
     *
     * @return Wiki markup.
     */
    std::string toMarkup() const;

    /**
     * Generates UiElements from a wiki page.
     *
     * @param parent A layout that shall contain all the controls.
     */
    void generateUiElements(QLayout* parent);

    PageBuilder();
    ~PageBuilder() = default;

    PageBuilder(PageBuilder const&) = delete;
    operator=(PageBuilder const&) = delete;

private:
    void addHeader(QLayout* parent, WikiMarkup::Components::Header const* component);
    void addText(QLayout* parent, WikiMarkup::Components::Text const* component);
    void addTable(QLayout* parent, WikiMarkup::Components::Table const* component);

private:
    PageContainer container_;
};

#endif // COMPONENTBUILDER_H

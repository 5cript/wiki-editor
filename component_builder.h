#ifndef COMPONENTBUILDER_H
#define COMPONENTBUILDER_H

#include "wiki-markup/page.hpp"
#include "wiki-markup/components/components.hpp"

#include <QWidget>
#include <QLabel>
#include <QLayout>

#include <string>

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

private:
    void addLabel(QLayout* parent, std::string const& text);
    void addTextSection(QLayout* parent, WikiMarkup::Components::IComponent const* component);
    void addHeader(QLayout* parent, WikiMarkup::Components::Header const* component);

private:
    WikiMarkup::Page page_;
};

#endif // COMPONENTBUILDER_H

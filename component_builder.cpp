#include "component_builder.h"

#include "wiki-markup/parser/page_parser.hpp"

#include "ui_components/text_section.h"
#include "ui_components/header.h"

#include <QDebug>

using namespace WikiMarkup::Components;

//####################################################################################
PageBuilder::PageBuilder()
{

}
//-----------------------------------------------------------------------------------
void PageBuilder::loadMarkup(std::string const& markup)
{
    using namespace WikiMarkup;
    using namespace Components;

    PageParser parser (markup);
    parser.parse();

    page_ = parser.getPage();
}
//-----------------------------------------------------------------------------------
std::string PageBuilder::toMarkup() const
{
    return page_.toMarkup();
}
//-----------------------------------------------------------------------------------
void PageBuilder::generateUiElements(QLayout *parent)
{
    auto& components = page_.getComponents();

    for (auto const& i : components)
    {
        auto* component = i.get();
        if (dynamic_cast <Header const*> (component))
            addHeader(parent, static_cast <Header const*> (component));
    }
}
//-----------------------------------------------------------------------------------
void PageBuilder::addLabel(QLayout *parent, std::string const& text)
{
    QLabel* label = new QLabel();
    label->setText(QString::fromStdString(text));
    parent->addWidget(label);
}
//-----------------------------------------------------------------------------------
void PageBuilder::addTextSection(QLayout *parent, WikiMarkup::Components::IComponent const* component)
{

}
//-----------------------------------------------------------------------------------
void PageBuilder::addHeader(QLayout *parent, WikiMarkup::Components::Header const* component)
{
    QLabel* label;
    switch (component->level)
    {
        case (1):
            label = new Header1;
            break;
        case (2):
            label = new Header2;
            break;
        case (3):
            label = new Header3;
            break;
        case (4):
            label = new Header4;
            break;
        case (5):
            label = new Header5;
            break;
        case (6):
            label = new Header6;
            break;
        default:
            label = new Header1;
            break;
    }

    label->setText(QString::fromStdString(component->data));
    parent->addWidget(label);
}
//####################################################################################

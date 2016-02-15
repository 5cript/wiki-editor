#include "component_builder.h"

#include "wiki-markup/parser/page_parser.hpp"

#include <QDebug>

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
        addLabel(parent, i->getMetaInfo().name);
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
void PageBuilder::addTextSection(QLayout *parent, WikiMarkup::Components::IComponent *component)
{

}
//-----------------------------------------------------------------------------------
void PageBuilder::addHeader(QLayout *parent, WikiMarkup::Components::Header *component)
{

}
//####################################################################################

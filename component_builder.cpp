#include "component_builder.hpp"

#include "wiki-markup/parser/page_parser.hpp"

#include <QDebug>
#include <QHeaderView>
#include <QFile>

#include <sstream>

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

    container_.getPage() = parser.getPage();
}
//-----------------------------------------------------------------------------------
std::string PageBuilder::toMarkup() const
{
    return container_.getPage().toMarkup();
}
//-----------------------------------------------------------------------------------
void PageBuilder::generateUiElements(QLayout *parent)
{
    auto& components = container_.getPage().getComponents();
    std::stringstream sstr;
    container_.getPage().dumpComponentNames(sstr);
    qDebug() << sstr.str().c_str();

    for (auto const& i : components)
    {
        auto* component = i.get();
        if (dynamic_cast <Header const*> (component))
            addHeader(parent, static_cast <Header const*> (component));
        else if (dynamic_cast <Text const*> (component))
            addText(parent, static_cast <Text const*> (component));
        else if (dynamic_cast <Table const*> (component))
            addTable(parent, static_cast <Table const*> (component));
    }
}
//-----------------------------------------------------------------------------------
void PageBuilder::addText(QLayout* parent, WikiMarkup::Components::Text const* component)
{
    auto* text = new TextField;
    text->setPlainText(QString::fromStdString(component->data));
    text->setObjectName("TextField");
    parent->addWidget(text);
}
//-----------------------------------------------------------------------------------
void PageBuilder::addTable(QLayout* parent, WikiMarkup::Components::Table const* component)
{
    auto* table = new TableView;

    std::string style = "";

    auto maybeClass = component->attributes.find("class");
    if (maybeClass != std::end(component->attributes))
    {
        QFile file(":/css/wikitable.css");
        file.open(QFile::ReadOnly);
        style += QString(QLatin1String(file.readAll())).toStdString();
        style.push_back('\n');
    }

    auto maybeStyle = component->attributes.find("style");
    if (maybeStyle != std::end(component->attributes))
    {
        style += "#table {\n\t";
        style += maybeStyle->second;
        style += "\n}\n";
    }

    qDebug() << style.c_str();

    table->setObjectName("TableView");
    table->setModel(&container_.createNewTable(*component));
    table->horizontalHeader()->hide();
    table->verticalHeader()->hide();
    parent->addWidget(table);
}
//-----------------------------------------------------------------------------------
void PageBuilder::addHeader(QLayout* parent, WikiMarkup::Components::Header const* component)
{
    auto* head = new QLineEdit;
    head->setObjectName(QString::fromStdString(std::string("Header") + std::to_string(component->level)));
    head->setText(QString::fromStdString(component->data));
    parent->addWidget(head);
}
//####################################################################################

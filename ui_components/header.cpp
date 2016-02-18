#include "header.h"

#include <QStyleOption>
#include <QPainter>

//####################################################################################
Header1::Header1(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header1::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################
Header2::Header2(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header2::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################
Header3::Header3(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header3::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################
Header4::Header4(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header4::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################
Header5::Header5(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header5::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################
Header6::Header6(QWidget* parent)
    : QLabel(parent)
{

}
//-----------------------------------------------------------------------------------
void Header6::paintEvent(QPaintEvent* e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QLabel::paintEvent(e);
}
//####################################################################################

#ifndef TEXTSECTION_H
#define TEXTSECTION_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>

class TextSection : public QTextEdit
{
public:
    TextSection();
    ~TextSection() = default;
};

#endif // TEXTSECTION_H

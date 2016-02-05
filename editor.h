#ifndef EDITOR_H
#define EDITOR_H

#include "component_builder.h"

#include <QMainWindow>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private slots:
    void on_action_LOAD_triggered();

private:
    PageBuilder builder_;
    Ui::Editor *ui;
};

#endif // EDITOR_H

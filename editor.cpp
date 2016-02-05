#include "editor.h"
#include "ui_editor.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include <fstream>

//####################################################################################
Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}
//-----------------------------------------------------------------------------------
Editor::~Editor()
{
    delete ui;
}
//-----------------------------------------------------------------------------------
void Editor::on_action_LOAD_triggered()
{
    qDebug() << "Hello";

    auto fileName = QFileDialog::getOpenFileName(this, "Open a markup file", ".", "Text (*.mu *.txt)");

    std::ifstream reader (fileName.toStdString(), std::ios_base::binary);

    if (!reader.good()) {
        QMessageBox::warning(this, "IO Error", "Could not load the file specified", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    std::string data;
    do {
        char buffer[4096];
        reader.read(buffer, 4096);
        data.append(buffer, reader.gcount());
    } while (reader.gcount() == 4096);

    qDebug() << QString::fromStdString(data);
    builder_.loadMarkup(data);
    builder_.generateUiElements(ui->viewPort->layout());
}
//####################################################################################

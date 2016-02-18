#include "editor.hpp"
#include "style_sheet_preprocessor.hpp"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // extract style sheet
    if (!QFile("./stylesheet.qss").exists())
        QFile::copy(":/styles/default.qss", "./stylesheet.qss");

    QFile file("stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString rawStyleSheet = QLatin1String(file.readAll());
    QString styleSheet = QString::fromStdString(preprocessStyleSheet(rawStyleSheet.toStdString()));

    a.setStyleSheet(styleSheet);

    // show main window and run app
    Editor w;
    w.show();

    return a.exec();
}

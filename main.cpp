#include "editor.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // extract style sheet
    if (!QFile("./stylesheet.qss").exists())
        QFile::copy(":/styles/default.qss", "./stylesheet.qss");

    QFile File("stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(StyleSheet);

    // show main window and run app
    Editor w;
    w.show();

    return a.exec();
}

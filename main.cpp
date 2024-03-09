#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setStyleSheet("background-color: lightblue;");
    w.setWindowTitle("ZM Music");
    w.setFixedSize(785,625);
    w.show();
    return a.exec();
}

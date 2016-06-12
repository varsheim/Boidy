#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(880, 600);
    w.setWindowTitle("Boidy");
    w.show();

    return a.exec();
}

#include "basewindow.h"
#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w->show();
    return QCoreApplication::exec();
}

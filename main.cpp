#include <QApplication>
#include <QFile>
#include <QPushButton>
#include "mainWindow.h"


int main(int argc, char *argv[])
{
    // Create the application object
    QApplication mainApp(argc, argv);

    mainWindow window;
    window.show();

    return mainApp.exec();
}

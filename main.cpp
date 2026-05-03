#include <QApplication>
#include <QFile>
#include <QPushButton>
#include "mainWindow.h"
//#include <string>


int main(int argc, char *argv[])
{
    // Create the application object
    // todo создать глобальные переменные для сохранения введенного текста на панели
    // todo создать историю
    QApplication mainApp(argc, argv);

    mainWindow window;
    window.show();

    return mainApp.exec();
}

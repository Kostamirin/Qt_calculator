#include "ProgramFiles/calculatorwindow.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    // Create the application object
    QApplication mainApp(argc, argv);

    // Load and apply styles from the QSS file
    QFile styleFile("main.ui");
    if (!styleFile.open(QFile::ReadOnly))
    {
        qWarning("Cannot open style file");
    }
    else
    {
        // Apply the stylesheet to the application
        QString styleSheet = QString::fromUtf8(styleFile.readAll());
        mainApp.setStyleSheet(styleSheet);
        styleFile.close();
    }

    // Create and display the main calculator window
    CalculatorWindow w;
    w.show();

    // Execute the application event loop
    return mainApp.exec();
}
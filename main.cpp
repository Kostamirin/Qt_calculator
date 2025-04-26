#include "calculatorwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    // Create the application object
    QApplication a(argc, argv);

    // Load and apply styles from the QSS file
    QFile styleFile(":/calculator.qss");
    if (!styleFile.open(QFile::ReadOnly)) {
        // Log a warning if the style file cannot be opened
        qWarning("Cannot open style file");
    } else {
        // Apply the stylesheet to the application
        QString styleSheet = QString::fromUtf8(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }

    // Create and display the main calculator window
    CalculatorWindow w;
    w.show();

    // Execute the application event loop
    return a.exec();
}
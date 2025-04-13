#include "calculatorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load and apply styles
    QFile styleFile(":/calculator.qss");
    if (!styleFile.open(QFile::ReadOnly)) {
        qWarning("Cannot open style file");
    } else {
        QString styleSheet = QString::fromUtf8(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }

    CalculatorWindow w;
    w.show();
    return a.exec();
}
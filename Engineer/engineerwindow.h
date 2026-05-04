// Created by kleymuner on 04.05.2026

#ifndef QT_GUI_PROJECT_ENGINEERWINDOW_H
#define QT_GUI_PROJECT_ENGINEERWINDOW_H

//#include "../Assets/basewindow.h"
#include "../mainWindow.h"
#include <qpushbutton.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class engineerWindow;
}

QT_END_NAMESPACE

class engineerWindow : mainWindow
{
    Q_OBJECT
public:
    engineerWindow();
    ~engineerWindow();

private slots:
    // something

private:
    void ini_buttons();
    void ini_functional();

    Ui::engineerWindow *ui;

    // create other buttons here
    QPushButton *button_sin;
    QPushButton *button_cos;
    QPushButton *button_tg;

}

#endif // QT_GUI_PROJECT_ENGINEERWINDOW_H

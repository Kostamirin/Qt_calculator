// Created by kleymuner on 04.05.2026

#ifndef QT_GUI_PROJECT_ENGINEERWINDOW_H
#define QT_GUI_PROJECT_ENGINEERWINDOW_H

#include "../mainWindow.h"
#include <QPushButton>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class engineerWindow;
}

QT_END_NAMESPACE

class engineerWindow : public mainWindow
{
    Q_OBJECT
public:
    engineerWindow();
    ~engineerWindow();

private slots:
    // Trigonometric functions
    void sinPressed();
    void cosPressed();
    void tanPressed();

    // Inverse trigonometric functions
    void asinPressed();
    void acosPressed();
    void atanPressed();

    // Hyperbolic functions
    void sinhPressed();
    void coshPressed();
    void tanhPressed();

    // Logarithmic functions
    void lnPressed();      // Natural logarithm
    void logPressed();     // Base 10 logarithm
    void log2Pressed();    // Base 2 logarithm

    // Power and root functions
    void sqrtPressed();    // Square root
    void cbrtPressed();    // Cube root
    void powerPressed();   // x^y
    void expPressed();     // e^x

    // Advanced functions
    void factorialPressed();  // n!
    void piPressed();         // π constant
    void ePressed();          // e constant
    void modPressed();        // Modulo
    void absPressed();        // Absolute value

    // Parentheses
    void leftParenPressed();
    void rightParenPressed();

    // Degree/Radian toggle
    void degreeRadianToggle();

private:
    void ini_buttons();
    void ini_functional();

    Ui::engineerWindow *ui;

    // Trigonometric buttons
    QPushButton *button_sin;
    QPushButton *button_cos;
    QPushButton *button_tg;

    // Inverse trigonometric buttons
    QPushButton *button_asin;
    QPushButton *button_acos;
    QPushButton *button_atg;

    // Hyperbolic buttons
    /*
     QPushButton *button_sinh;
     QPushButton *button_cosh;
     QPushButton *button_tgh;
     */

    // Logarithmic buttons
    QPushButton *button_ln;
    QPushButton *button_log;
    QPushButton *button_log2;

    // Power and root buttons
    QPushButton *button_sqrt;
    QPushButton *button_cbrt;
    QPushButton *button_power;
    QPushButton *button_exp;

    // Advanced function buttons
    QPushButton *button_factorial;
    QPushButton *button_pi;
    QPushButton *button_e;
    QPushButton *button_mod;
    QPushButton *button_abs;

    // Parentheses buttons
    QPushButton *button_left_paren;
    QPushButton *button_right_paren;

    // Toggle button
    QPushButton *button_deg_rad;

    bool isRadianMode = true;  // true for radians, false for degrees
};

#endif // QT_GUI_PROJECT_ENGINEERWINDOW_H

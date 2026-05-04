// Created by kleymuner on 04.05.2026

#include "engineerwindow.h"
#include "ui_engineerwindow.h"
#include <cmath>
#include <QString>

engineerWindow::engineerWindow(QWidget *parent)
    : mainWindow(parent)
{
    ui->setupUi(this);
    ini_buttons();
    ini_functional();
    setWindowTitle("Engineer Calculator");
}

engineerWindow::~engineerWindow()
{
    delete ui;
}

void engineerWindow::ini_buttons()
{
    // Trigonometric buttons
    button_sin = ui->pushButton_sin;
    button_cos = ui->pushButton_cos;
    button_tan = ui->pushButton_tan;
    
    // Inverse trigonometric buttons
    button_asin = ui->pushButton_asin;
    button_acos = ui->pushButton_acos;
    button_atan = ui->pushButton_atan;
    
    // Hyperbolic buttons
    button_sinh = ui->pushButton_sinh;
    button_cosh = ui->pushButton_cosh;
    button_tanh = ui->pushButton_tanh;
    
    // Logarithmic buttons
    button_ln = ui->pushButton_ln;
    button_log = ui->pushButton_log;
    button_log2 = ui->pushButton_log2;
    
    // Power and root buttons
    button_sqrt = ui->pushButton_sqrt;
    button_cbrt = ui->pushButton_cbrt;
    button_power = ui->pushButton_power;
    button_exp = ui->pushButton_exp;
    
    // Advanced function buttons
    button_factorial = ui->pushButton_factorial;
    button_pi = ui->pushButton_pi;
    button_e = ui->pushButton_e;
    button_mod = ui->pushButton_mod;
    button_abs = ui->pushButton_abs;
    
    // Parentheses buttons
    button_left_paren = ui->pushButton_left_paren;
    button_right_paren = ui->pushButton_right_paren;
    
    // Toggle button
    button_deg_rad = ui->pushButton_deg_rad;
}

void engineerWindow::ini_functional()
{
    // Connect trigonometric buttons
    connect(button_sin, &QPushButton::clicked, this, &engineerWindow::sinPressed);
    connect(button_cos, &QPushButton::clicked, this, &engineerWindow::cosPressed);
    connect(button_tan, &QPushButton::clicked, this, &engineerWindow::tanPressed);
    
    // Connect inverse trigonometric buttons
    connect(button_asin, &QPushButton::clicked, this, &engineerWindow::asinPressed);
    connect(button_acos, &QPushButton::clicked, this, &engineerWindow::acosPressed);
    connect(button_atan, &QPushButton::clicked, this, &engineerWindow::atanPressed);
    
    // Connect hyperbolic buttons
    connect(button_sinh, &QPushButton::clicked, this, &engineerWindow::sinhPressed);
    connect(button_cosh, &QPushButton::clicked, this, &engineerWindow::coshPressed);
    connect(button_tanh, &QPushButton::clicked, this, &engineerWindow::tanhPressed);
    
    // Connect logarithmic buttons
    connect(button_ln, &QPushButton::clicked, this, &engineerWindow::lnPressed);
    connect(button_log, &QPushButton::clicked, this, &engineerWindow::logPressed);
    connect(button_log2, &QPushButton::clicked, this, &engineerWindow::log2Pressed);
    
    // Connect power and root buttons
    connect(button_sqrt, &QPushButton::clicked, this, &engineerWindow::sqrtPressed);
    connect(button_cbrt, &QPushButton::clicked, this, &engineerWindow::cbrtPressed);
    connect(button_power, &QPushButton::clicked, this, &engineerWindow::powerPressed);
    connect(button_exp, &QPushButton::clicked, this, &engineerWindow::expPressed);
    
    // Connect advanced function buttons
    connect(button_factorial, &QPushButton::clicked, this, &engineerWindow::factorialPressed);
    connect(button_pi, &QPushButton::clicked, this, &engineerWindow::piPressed);
    connect(button_e, &QPushButton::clicked, this, &engineerWindow::ePressed);
    connect(button_mod, &QPushButton::clicked, this, &engineerWindow::modPressed);
    connect(button_abs, &QPushButton::clicked, this, &engineerWindow::absPressed);
    
    // Connect parentheses buttons
    connect(button_left_paren, &QPushButton::clicked, this, &engineerWindow::leftParenPressed);
    connect(button_right_paren, &QPushButton::clicked, this, &engineerWindow::rightParenPressed);
    
    // Connect toggle button
    connect(button_deg_rad, &QPushButton::clicked, this, &engineerWindow::degreeRadianToggle);
}

// Trigonometric functions
void engineerWindow::sinPressed() 
{ 
    display->setText(display->text() + "sin(");
}

void engineerWindow::cosPressed() 
{ 
    display->setText(display->text() + "cos(");
}

void engineerWindow::tanPressed() 
{ 
    display->setText(display->text() + "tan(");
}

// Inverse trigonometric functions
void engineerWindow::asinPressed() 
{ 
    display->setText(display->text() + "asin(");
}

void engineerWindow::acosPressed() 
{ 
    display->setText(display->text() + "acos(");
}

void engineerWindow::atanPressed() 
{ 
    display->setText(display->text() + "atan(");
}

// Hyperbolic functions
void engineerWindow::sinhPressed() 
{ 
    display->setText(display->text() + "sinh(");
}

void engineerWindow::coshPressed() 
{ 
    display->setText(display->text() + "cosh(");
}

void engineerWindow::tanhPressed() 
{ 
    display->setText(display->text() + "tanh(");
}

// Logarithmic functions
void engineerWindow::lnPressed() 
{ 
    display->setText(display->text() + "ln(");
}

void engineerWindow::logPressed() 
{ 
    display->setText(display->text() + "log(");
}

void engineerWindow::log2Pressed() 
{ 
    display->setText(display->text() + "log2(");
}

// Power and root functions
void engineerWindow::sqrtPressed() 
{ 
    display->setText(display->text() + "√(");
}

void engineerWindow::cbrtPressed() 
{ 
    display->setText(display->text() + "∛(");
}

void engineerWindow::powerPressed() 
{ 
    display->setText(display->text() + "^");
}

void engineerWindow::expPressed() 
{ 
    display->setText(display->text() + "exp(");
}

// Advanced functions
void engineerWindow::factorialPressed() 
{ 
    display->setText(display->text() + "!");
}

void engineerWindow::piPressed() 
{ 
    display->setText(display->text() + "π");
}

void engineerWindow::ePressed() 
{ 
    display->setText(display->text() + "e");
}

void engineerWindow::modPressed() 
{ 
    display->setText(display->text() + "mod");
}

void engineerWindow::absPressed() 
{ 
    display->setText(display->text() + "abs(");
}

// Parentheses
void engineerWindow::leftParenPressed() 
{ 
    display->setText(display->text() + "(");
}

void engineerWindow::rightParenPressed() 
{ 
    display->setText(display->text() + ")");
}

// Degree/Radian toggle
void engineerWindow::degreeRadianToggle()
{
    isRadianMode = !isRadianMode;
    if (isRadianMode) {
        button_deg_rad->setText("RAD");
        button_deg_rad->setStyleSheet("background-color: lightblue;");
    } else {
        button_deg_rad->setText("DEG");
        button_deg_rad->setStyleSheet("background-color: lightcoral;");
    }
}

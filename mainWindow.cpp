// Created by kleymuner on 26.03.2026.

#include "mainWindow.h"
#include "ui_mainwindow.h"
// #include "main.ui"



mainWindow::mainWindow (QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ini_buttons();
    ini_fuctional();
}

mainWindow::~mainWindow()
{
    return;
}


void mainWindow::ini_buttons()
{
    // Связываем удобные имена с объектами из .ui файла
    button_1 = ui->pushButton_1;
    button_2 = ui->pushButton_2;
    button_3 = ui->pushButton_3;
    button_4 = ui->pushButton_4;
    button_5 = ui->pushButton_5;
    button_6 = ui->pushButton_6;
    button_7 = ui->pushButton_7;
    button_8 = ui->pushButton_8;
    button_9 = ui->pushButton_9;
    button_0 = ui->pushButton_0;
    button_dot = ui->pushButton_dot;
    button_percent = ui->pushButton_percent;

    // Добавленны позже
    button_plus = ui->pushButton_plus;
    button_minus = ui->pushButton_minus;
    button_multiply = ui->pushButton_multiply;
    button_divide = ui->pushButton_divide;
    button_equals = ui->pushButton_equals;
    button_clear = ui->pushButton_clear;

    display = ui->lineEdit;
}

void mainWindow::ini_fuctional()
{
    // Подключение ФУНКЦИОНАЛА к    -- числам
    connect(button_0, &QPushButton::clicked, this, &mainWindow::num0Pressed);
    connect(button_1, &QPushButton::clicked, this, &mainWindow::num1Pressed);
    connect(button_2, &QPushButton::clicked, this, &mainWindow::num2Pressed);
    connect(button_3, &QPushButton::clicked, this, &mainWindow::num3Pressed);
    connect(button_4, &QPushButton::clicked, this, &mainWindow::num4Pressed);
    connect(button_5, &QPushButton::clicked, this, &mainWindow::num5Pressed);
    connect(button_6, &QPushButton::clicked, this, &mainWindow::num6Pressed);
    connect(button_7, &QPushButton::clicked, this, &mainWindow::num7Pressed);
    connect(button_8, &QPushButton::clicked, this, &mainWindow::num8Pressed);
    connect(button_9, &QPushButton::clicked, this, &mainWindow::num9Pressed);

    // Подключение функционала к     -- символам
    connect(button_dot, &QPushButton::clicked, this, &mainWindow::dotPressed);
    connect(button_percent, &QPushButton::clicked, this, &mainWindow::percentPressed);
    connect(button_plus, &QPushButton::clicked, this, &mainWindow::plusPressed);
    connect(button_minus, &QPushButton::clicked, this, &mainWindow::minusPressed);
    connect(button_multiply, &QPushButton::clicked, this, &mainWindow::multiplyPressed);
    connect(button_divide, &QPushButton::clicked, this, &mainWindow::dividePressed);
    connect(button_equals, &QPushButton::clicked, this, &mainWindow::equalsPressed);
    connect(button_clear, &QPushButton::clicked, this, &mainWindow::clearPressed);
}

void mainWindow::num0Pressed() { display->setText(display->text() + "0"); }
void mainWindow::num1Pressed() { display->setText(display->text() + "1"); }
void mainWindow::num2Pressed() { display->setText(display->text() + "2"); }
void mainWindow::num3Pressed() { display->setText(display->text() + "3"); }
void mainWindow::num4Pressed() { display->setText(display->text() + "4"); }
void mainWindow::num5Pressed() { display->setText(display->text() + "5"); }
void mainWindow::num6Pressed() { display->setText(display->text() + "6"); }
void mainWindow::num7Pressed() { display->setText(display->text() + "7"); }
void mainWindow::num8Pressed() { display->setText(display->text() + "8"); }
void mainWindow::num9Pressed() { display->setText(display->text() + "9"); }

void mainWindow::dotPressed() { display->setText(display->text() + "."); }
void mainWindow::percentPressed() { display->setText(display->text() + "%"); }
void mainWindow::plusPressed() {}
void mainWindow::minusPressed() {}
void mainWindow::multiplyPressed() {}
void mainWindow::dividePressed() {}
void mainWindow::equalsPressed() {}
void mainWindow::clearPressed() { display->clear(); }
void mainWindow::clearallPressed() { display->clear(); }

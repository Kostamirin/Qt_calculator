// Created by kleymuner on 26.03.2026.

#include "mainWindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow (QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ini_buttons();
    ini_fuctional();
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

    display = ui->lineEdit;
}

void mainWindow::ini_fuctional()
{
    // Подключение ФУНКЦИОНАЛА к кнопкам
    connect(button_1, &QPushButton::clicked, this, &mainWindow::num1Pressed);
    connect(button_2, &QPushButton::clicked, this, &mainWindow::num2Pressed);

}

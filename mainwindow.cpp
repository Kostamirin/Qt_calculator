// Created by kleymuner on 26.03.2026.

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ProgramFiles/head.h"
//#include "Progressions/secondwindow.h"
// #include "main.ui"

// head head;


mainWindow::mainWindow(QWidget *parent)
{
    //ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    return;
}



void mainWindow::on_pushButton_0_clicked()
{
    display->setText(display->text()+"0");
}


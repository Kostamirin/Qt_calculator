// Created by kleymuner on 26.03.2026.

#include "mainWindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow (QWidget *parent) :
    QMainWindow(parent), ui(new Ui:mainWindow)
{
    ui->setupUi(this);
}


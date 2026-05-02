//
// Created by kleymuner on 27.03.2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_baseWindow.h" resolved

#include "basewindow.h"
#include "ui_baseWindow.h"


baseWindow::baseWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::baseWindow)
{
    ui->setupUi(this);
}

baseWindow::~baseWindow()
{
    delete ui;
}

baseWindow::switchToCalculator(int type)
{
    return;
}
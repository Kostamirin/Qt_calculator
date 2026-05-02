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
    ini_buttons();

    connect(toggle_basic, &QAction::triggered, this, switchToCalculator(0));
    connect(toggle_engineer, &QAction::triggered, this, switchToCalculator(1));
}

baseWindow::~baseWindow()
{
    delete ui;
}

baseWindow::ini_buttons()
{
    toggle_basic = ui->actionBasic;
    toggle_engineer = ui->actionEngineer;
}

baseWindow::switchToCalculator(int type)
{
    return;
}
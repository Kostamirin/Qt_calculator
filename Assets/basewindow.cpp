// Created by kleymuner on 27.03.2026.

// You may need to build the project (run Qt uic code generator) to get "ui_baseWindow.h" resolved

#include "basewindow.h"
#include "ui_baseWindow.h"
#include <iostream>


baseWindow::baseWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::baseWindow)
{
    ui->setupUi(this);
    ini_buttons();

    connect(toggle_basic, &QAction::triggered, this, switchToCalculator("basic"));
    connect(toggle_engineer, &QAction::triggered, this, switchToCalculator("engineer"));
}

baseWindow::~baseWindow()
{
    delete ui;
}

void baseWindow::ini_buttons()
{
    toggle_basic = ui->actionBasic;
    toggle_engineer = ui->actionEngineer;
}

void baseWindow::switchToCalculator(std::string type)
{
    if (type == "basic")
    {
        toggle_basic_window();
    }
    else if (type == "engineer")
    {
        toggle_engineer_window();
    }
    else
    {
        std::cout <<"What a hell? - basewindow.cpp __ line 45";
    }

}

// Created by kleymuner on 27.03.2026.


#include <iostream>
#include "basewindow.h"
#include "ui_basewindow.h"


baseWindow::baseWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::baseWindow)
{

}

baseWindow::~baseWindow()
{
    //delete ui;
}
/*
void baseWindow::ini_buttons()
{
    toggle_basic = ui->actionBasic;
    toggle_engineer = ui->actionEngineer;
}
*/
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

void baseWindow::on_actionBasic_triggered()
{
    switchToCalculator("basic");
}


void baseWindow::on_actionEngineer_triggered()
{
    switchToCalculator("engineer");
}


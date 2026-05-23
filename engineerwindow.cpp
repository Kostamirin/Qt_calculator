#include "engineerwindow.h"
#include "ui_engineerwindow.h"

engineerwindow::engineerwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::engineerwindow)
{
    ui->setupUi(this);
}

engineerwindow::~engineerwindow()
{
    delete ui;
}

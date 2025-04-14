// Created by kleymuner2131 on 14.04.25.
#include "arithmetic_progression.h"
#include <QWidget>
#include <QBoxLayout>
#include <QApplication>

arithmeticProgressionWindow::arithmeticProgressionWindow(QWidget *parent) : QWidget(parent) {
    // Set up the layout for the arithmetic progression window
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new arithmeticProgression());
}

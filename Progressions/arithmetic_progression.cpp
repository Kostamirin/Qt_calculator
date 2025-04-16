// Created by kleymuner2131 on 14.04.25.
#include "arithmetic_progression.h"
#include <QWidget>
#include <QWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QApplication>

arithmeticProgressionWindow::arithmeticProgressionWindow(QWidget *parent) : QWindow(parent) {
    // Set up the layout for the arithmetic progression window
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    // Create horizontal layout for each parameter
    QHBoxLayout *firstLayout = new QHBoxLayout();
    QLabel *firstLabel = new QLabel("First Term (a_1):");
    firstInput_ = new QLineEdit();
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput_);

    QHBoxLayout *differenceLayout = new QHBoxLayout();
    QLabel *differenceLabel = new QLabel("Common Difference (d):");
    differenceInput_ = new QLineEdit();
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput_);

    QHBoxLayout *termsLayout = new QHBoxLayout();
    QLabel *termsLabel = new QLabel("Number of Terms (n):");
    termsInput_ = new QLineEdit();
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput_);

    QHBoxLayout *lastTermLayout = new QHBoxLayout();
    QLabel *lastTermLabel = new QLabel("Last Term (a_n):");
    lastTermInput_ = new QLineEdit();
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput_);

    QHBoxLayout *sumLayout = new QHBoxLayout();
    QLabel *sumLabel = new QLabel("Sum of Terms (S_n):");
    sumInput_ = new QLineEdit();
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput_);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);
}
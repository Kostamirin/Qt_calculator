// Created by kleymuner2131 on 14.04.25.
#include "arithmetic_progression.h"
#include <QWidget>
#include <QWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QApplication>

arithmetic_progression::arithmetic_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set up the layout for the arithmetic progression window
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);


    // Create horizontal layout for each parameter
    QHBoxLayout *firstLayout = new QHBoxLayout();
    QLabel *firstLabel = new QLabel("First Term (a_1):");
    QLineEdit *firstInput = new QLineEdit();
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    QHBoxLayout *differenceLayout = new QHBoxLayout();
    QLabel *differenceLabel = new QLabel("Common Difference (d):");
    QLineEdit *differenceInput = new QLineEdit();
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput);

    QHBoxLayout *termsLayout = new QHBoxLayout();
    QLabel *termsLabel = new QLabel("Number of Terms (n):");
    QLineEdit *termsInput = new QLineEdit();
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    QHBoxLayout *lastTermLayout = new QHBoxLayout();
    QLabel *lastTermLabel = new QLabel("Last Term (a_n):");
    QLineEdit *lastTermInput = new QLineEdit();
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    QHBoxLayout *sumLayout = new QHBoxLayout();
    QLabel *sumLabel = new QLabel("Sum of Terms (S_n):");
    QLineEdit *sumInput = new QLineEdit();
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);
}
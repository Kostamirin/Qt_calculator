// Created by kleymuner2131 on 21.04.25.

#include "geometric_progression.h"
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

geometric_progression::geometric_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    centralWidget = new QWidget(this); // Присваиваем члену класса
    setCentralWidget(centralWidget);

    // Set up the layout for the arithmetic progression window
    mainLayout = new QVBoxLayout(centralWidget); // Присваиваем члену класса

    // Create horizontal layout for each parameter
    // Теперь все виджеты создаются с new и присваиваются членам класса
    firstLayout = new QHBoxLayout();
    firstLabel = new QLabel("First Term (b_1):");
    firstInput = new QLineEdit();
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    differenceLayout = new QHBoxLayout();
    differenceLabel = new QLabel("Common Difference (q):");
    differenceInput = new QLineEdit();
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput);

    termsLayout = new QHBoxLayout();
    termsLabel = new QLabel("Number of Terms (n):");
    termsInput = new QLineEdit();
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    lastTermLayout = new QHBoxLayout();
    lastTermLabel = new QLabel("Last Term (b_n):");
    lastTermInput = new QLineEdit();
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    sumLayout = new QHBoxLayout();
    sumLabel = new QLabel("Sum of Terms (S_n):");
    sumInput = new QLineEdit();
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);

    // Добавляется кнопка
    calculationButton = new QPushButton("Calculate"); // Создаем с new
    connect(calculationButton, &QPushButton::clicked, this, &geometric_progression::calculation_button_clicked);
    mainLayout->addWidget(calculationButton);
}

void geometric_progression::~geometric_progression()
{
    //
    //
}

void geometric_progression::calculation_button_clicked() {

    float a1 = UNKNOWN_FLOAT;
    float d = UNKNOWN_FLOAT;
    int n = UNKNOWN_INT;
    float an = UNKNOWN_FLOAT;
    float sn = UNKNOWN_FLOAT;
    int known_count = 0;



}

void geometric_progression::calculate(float &firstTerm, float &difference, int &termNumber, float &lastTerm, float& sum)
{

}



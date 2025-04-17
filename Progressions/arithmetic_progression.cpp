// Created by kleymuner2131 on 14.04.25.
//#include <QApplication> // Needed only if using QApplication:: stuff directly, often only needed in main.cpp
// #include <QWindow> // Not directly needed here
#include "arithmetic_progression.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

arithmetic_progression::arithmetic_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set up the layout for the arithmetic progression window
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);


    // Create horizontal layout for each parameter
    QPushButton calculation_trigger_button("Calculate");
    connect(&calculation_trigger_button, &QPushButton::clicked, this, &arithmetic_progression::calculation_button_clicked);
    QHBoxLayout *firstLayout = new QHBoxLayout();
    QLabel *firstLabel = new QLabel("First Term (a_1):");
    firstInput = new QLineEdit(); // Assign to member variable
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    QHBoxLayout *differenceLayout = new QHBoxLayout();
    QLabel *differenceLabel = new QLabel("Common Difference (d):");
    differenceInput = new QLineEdit(); // Assign to member variable
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput);

    QHBoxLayout *termsLayout = new QHBoxLayout();
    QLabel *termsLabel = new QLabel("Number of Terms (n):");
    termsInput = new QLineEdit(); // Assign to member variable
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    QHBoxLayout *lastTermLayout = new QHBoxLayout();
    QLabel *lastTermLabel = new QLabel("Last Term (a_n):");
    lastTermInput = new QLineEdit(); // Assign to member variable
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    QHBoxLayout *sumLayout = new QHBoxLayout();
    QLabel *sumLabel = new QLabel("Sum of Terms (S_n):");
    sumInput = new QLineEdit(); // Assign to member variable
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Добавление кнопки
    mainLayout->addWidget(&calculation_trigger_button);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);

    // TODO: Add a button to trigger calculations
    // TODO: Connect button's clicked() signal to a slot (e.g., startButtonClicked)
}

void arithmetic_progression::calculation_button_clicked()
{
    // TODO: Implement calculation logic
    float a1 = firstInput->text().toFloat();
    float d = differenceInput->text().toFloat();
    int n = termsInput->text().toInt();
    float an = lastTermInput->text().toFloat();
    float sn = sumInput->text().toFloat();
    // Call the appropriate function or method to calculate the arithmetic progression
    float result = calculateArithmeticProgression(a1, d, n, an, sn);
    // Display the result
    QMessageBox::information(this, "Result", "The result is: " + QString::number(result));

}

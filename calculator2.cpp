// Created by kleymuner2131 on 25.03.25.
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QTextBlock>
#include <QGridLayout>
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include <cmath>
#include <QMainWindow>


//! Код арифметической прогрессии
int main2(int argc, char* argv[])
{
    int firstTerm = -1;   // a_1
    int step_int = -1;        // Difference d
    int termNumber = -1;  // Term number n
    int termValue = -1;   // Value of n-th term a_n
    int sumOfTerms = -1;  // Sum of first n terms S_n

    QWidget window;
    QApplication progression_win(argc, argv, '0');
    window.setWindowTitle("Progression Calculator");

    QLineEdit *display = new QLineEdit();
    display->setReadOnly(false);
    display->setAlignment(Qt::AlignRight);


    QTextBlock *first_term = new QTextBlock();
    QTextBlock *step = new QTextBlock();
    QTextBlock *term_number = new QTextBlock();
    QTextBlock *term_value = new QTextBlock();
    QTextBlock *sum_of_terms = new QTextBlock();

    QGridLayout *layout_base = new QGridLayout();
    QGridLayout *layout_left = new QGridLayout();
    QGridLayout *layout_right = new QGridLayout();

    layout_left->addWidget(new QLabel("a_1"), 0, 0);
    layout_left->addWidget(new QLabel("d"), 1, 0);
    layout_left->addWidget(new QLabel("n"), 2, 0);
    layout_left->addWidget(new QLabel("a_n"), 3, 0);
    layout_left->addWidget(new QLabel("S_n"), 4, 0);

    layout_base->addLayout(layout_left, 0, 0, 6, 1);
    layout_base->addLayout(layout_right, 0, 1, 6, 1);

    window.setLayout(layout_base);

    window.show();
    return progression_win.exec();
}

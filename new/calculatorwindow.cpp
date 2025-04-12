#include "calculatorwindow.h"
#include "head.cpp"
#include "secondwindow.h" // Include header for the second window

#include <iostream>
#include <string>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QApplication>

std::string main_string = "";
CalculatorWindow::CalculatorWindow(QWidget *parent):QMainWindow(parent)
{
    // Basic window setup
    setWindowTitle("Calculator");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QGridLayout *layout = new QGridLayout(centralWidget);

    // Display
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    layout->addWidget(display, 0, 0, 1, 5); // Span across 4 columns

    QPushButton *one = new QPushButton("1");
    connect(one, &QPushButton::clicked, this, &CalculatorWindow::oneButtonClicked);
    QPushButton *two = new QPushButton("2");
    connect(two, &QPushButton::clicked, this, &CalculatorWindow::twoButtonClicked);
    QPushButton *three = new QPushButton("3");
    connect(three, &QPushButton::clicked, this, &CalculatorWindow::threeButtonClicked);
    QPushButton *four = new QPushButton("4");
    connect(four, &QPushButton::clicked, this, &CalculatorWindow::fourButtonClicked);
    QPushButton *five = new QPushButton("5");
    connect(five, &QPushButton::clicked, this, &CalculatorWindow::fiveButtonClicked);
    QPushButton *six = new QPushButton("6");
    connect(six, &QPushButton::clicked, this, &CalculatorWindow::sixButtonClicked);
    QPushButton *seven = new QPushButton("7");
    connect(seven, &QPushButton::clicked, this, &CalculatorWindow::sevenButtonClicked);
    QPushButton *eight = new QPushButton("8");
    connect(eight, &QPushButton::clicked, this, &CalculatorWindow::eightButtonClicked);
    QPushButton *nine = new QPushButton("9");
    connect(nine, &QPushButton::clicked, this, &CalculatorWindow::nineButtonClicked);
    QPushButton *zero = new QPushButton("0");
    connect(zero, &QPushButton::clicked, this, &CalculatorWindow::zeroButtonClicked);
    QPushButton *add = new QPushButton("+");
    connect(add, &QPushButton::clicked, this, &CalculatorWindow::sumClicked);
    QPushButton *sub = new QPushButton("-");
    connect(sub, &QPushButton::clicked, this, &CalculatorWindow::subClicked);
    QPushButton *mul = new QPushButton("*");
    connect(mul, &QPushButton::clicked, this, &CalculatorWindow::mulClicked);
    QPushButton *div = new QPushButton("/");
    connect(div, &QPushButton::clicked, this, &CalculatorWindow::divClicked);
    QPushButton *equal = new QPushButton("=");
    connect(equal, &QPushButton::clicked, this, &CalculatorWindow::equalClicked);
    QPushButton *clear = new QPushButton("Cl");
    connect(clear, &QPushButton::clicked, this, &CalculatorWindow::clearClicked);
    QPushButton *second = new QPushButton("2nd");
    connect(second, &QPushButton::clicked, this, &CalculatorWindow::secondButtonClicked);
    QPushButton *open = new QPushButton("("); //todo: Создать функционал для этих скобок
    connect(open, &QPushButton::clicked, this, &CalculatorWindow::openButtonClicked);
    QPushButton *close = new QPushButton(")");


    // --- Placeholder for buttons ---
    // We will add buttons in the next step
    layout->addWidget(one, 1, 0);
    layout->addWidget(two, 1, 1);
    layout->addWidget(three, 1, 2);
    layout->addWidget(add, 1, 3);
    layout->addWidget(sub, 1, 4);
    layout->addWidget(four, 2, 0);
    layout->addWidget(five, 2, 1);
    layout->addWidget(six, 2, 2);
    layout->addWidget(mul, 2, 3);
    layout->addWidget(div, 2, 4);
    layout->addWidget(seven, 3, 0);
    layout->addWidget(eight, 3, 1);
    layout->addWidget(nine, 3, 2);
    layout->addWidget(open, 3, 3); //!     (
    layout->addWidget(close, 3, 4); //!    )
    layout->addWidget(second, 4, 0);
    layout->addWidget(equal, 4, 3, 1,2);
    layout->addWidget(zero, 4, 1);
    layout->addWidget(clear, 4, 2);
}

CalculatorWindow::~CalculatorWindow()
{
    // Destructor - Qt handles child widgets automatically
}
void CalculatorWindow::secondButtonClicked()
{
    SecondWindow *second_win = new SecondWindow(this);
    second_win->show();
    second_win->exec();
    delete second_win;
}
void CalculatorWindow::sumClicked() //! Functional button S
{
    if (main_string[main_string.size()-1] != '+')
    {
        main_string += "+";
        display->setText(display->text()+="+");
    }
    else{NULL;}
}
void CalculatorWindow::subClicked()
{
    if (main_string[main_string.size()-1] != '-')
    {
        main_string += "-";
        display->setText(display->text()+="-");
    }
    else{NULL;}
}
void CalculatorWindow::mulClicked()
{
    if (main_string[main_string.size()-1] != '*')
    {
        main_string += "*";
        display->setText(display->text()+="*");
    }
    else{NULL;}
}
void CalculatorWindow::divClicked()
{
    if (main_string[main_string.size()-1] != '/')
    {
        main_string += "/";
        display->setText(display->text()+="/");
    }
    else{NULL;}
}

void CalculatorWindow::clearClicked() //! Functional button E
{ //todo: Добавить некий таймер, за который все еще возможно ничего не делать,
  //todo:чтобы не произошло очистки -- добавить ожидание второго нажатия
    display->setText("");
}
void CalculatorWindow::oneButtonClicked() //! Numbers button S
{
    main_string += "1";
    display->setText(display->text()+= "1");
}
void CalculatorWindow::twoButtonClicked()
{
    main_string += "2";
    display->setText(display->text()+= "2");
}
void CalculatorWindow::threeButtonClicked()
{
    main_string += "3";
    display->setText(display->text()+= "3");
}
void CalculatorWindow::fourButtonClicked()
{
    main_string += "4";
    display->setText(display->text()+= "4");
}
void CalculatorWindow::fiveButtonClicked()
{
    main_string += "5";
    display->setText(display->text()+= "5");
}
void CalculatorWindow::sixButtonClicked()
{
    main_string += "6";
    display->setText(display->text()+= "6");
}
void CalculatorWindow::sevenButtonClicked()
{
    main_string += "7";
    display->setText(display->text()+= "7");
}
void CalculatorWindow::eightButtonClicked()
{
    main_string += "8";
    display->setText(display->text()+= "8");
}
void CalculatorWindow::nineButtonClicked()
{
    main_string += "9";
    display->setText(display->text()+= "9");
}
void CalculatorWindow::zeroButtonClicked() //! Numbers button E
{
    main_string += "0";
    display->setText(display->text()+= "0");
}

void CalculatorWindow::equalClicked() //! Equal button
{
    if (is_this_balanced(main_string) == false)
    {
        display->setText("Error: Not balanced");
        // Return from function because of error
        // This is because the input string is not balanced
        // i.e. the number of opening and closing brackets do not match
        // This would cause an error in the calculation of the answer
        return;
    }
    double answer = answer_function(main_string);

    display->setText(QString::number(answer));
}


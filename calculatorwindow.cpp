#include "calculatorwindow.h"
#include "head.h"
#include "Progressions/secondwindow.h"

#include <iostream>
#include <string>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QFile>

CalculatorWindow::CalculatorWindow(QWidget *parent):QMainWindow(parent)
{
    // Basic window setup
    setWindowTitle("Calculator");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QGridLayout *layout = new QGridLayout(centralWidget);
    
    // Set spacing between buttons
    layout->setSpacing(6);
    layout->setContentsMargins(10, 10, 10, 10);

    // Display
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    layout->addWidget(display, 0, 0, 1, 5); // Span across 4 columns

    currentExpression = "";

    // Number buttons
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
    //Functional buttons
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
    QPushButton *open = new QPushButton("(");
    connect(open, &QPushButton::clicked, this, &CalculatorWindow::openButtonClicked);
    QPushButton *close = new QPushButton(")");
    connect(close, &QPushButton::clicked, this, &CalculatorWindow::closeButtonClicked);
    QPushButton *dot = new QPushButton(".");
    connect(dot, &QPushButton::clicked, this, &CalculatorWindow::dotButtonClicked);


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
    layout->addWidget(open, 3, 3);
    layout->addWidget(close, 3, 4);
    layout->addWidget(second, 4, 0);
    layout->addWidget(zero, 4, 1);
    layout->addWidget(dot, 4, 2);
    layout->addWidget(equal, 4, 3);
    layout->addWidget(clear, 4, 4);

}

CalculatorWindow::~CalculatorWindow()
{
    // Destructor - Qt handles child widgets automatically
}
void CalculatorWindow::secondButtonClicked()
{
    SecondWindow *second_win = new SecondWindow(this); // Устанавливаем родителя
    second_win->setAttribute(Qt::WA_DeleteOnClose); // Автоматическое удаление при закрытии
    second_win->setModal(true); // Делаем окно модальным
    second_win->show();
    // second_win->exec(); // exec() не нужен для модальных окон, открытых через show()
    // delete second_win; // Удаление не нужно из-за WA_DeleteOnClose и родителя
}
void CalculatorWindow::openButtonClicked()
{
    currentExpression += "(";
    display->setText(display->text()+"(");
}
void CalculatorWindow::closeButtonClicked()
{
    currentExpression += ")";
    display->setText(display->text()+")");

}
void CalculatorWindow::sumClicked() //! Functional button S
{
    if (!currentExpression.empty() && currentExpression.back() != '+') // Проверка на пустоту и последний символ
    {
        currentExpression += "+";
        display->setText(display->text()+="+");
    }
    // else{NULL;} // Удаляем бессмысленный else
}
void CalculatorWindow::subClicked()
{
    if (!currentExpression.empty() && currentExpression.back() != '-') // Проверка на пустоту и последний символ
    {
        currentExpression += "-";
        display->setText(display->text()+="-");
    }
    // else{NULL;}
}
void CalculatorWindow::mulClicked()
{
    if (!currentExpression.empty() && currentExpression.back() != '*') // Проверка на пустоту и последний символ
    {
        currentExpression += "*";
        display->setText(display->text()+="*");
    }
    // else{NULL;}
}
void CalculatorWindow::divClicked()
{
    if (!currentExpression.empty() && currentExpression.back() != '/') // Проверка на пустоту и последний символ
    {
        currentExpression += "/";
        display->setText(display->text()+="/");
    }
    // else{NULL;}
}

void CalculatorWindow::clearClicked() //! Functional button E
{ //todo: Добавить некий таймер, за который все еще возможно ничего не делать,
  //todo:чтобы не произошло очистки -- добавить ожидание второго нажатия
    display->setText("");
    currentExpression = "";
}
void CalculatorWindow::oneButtonClicked() //! Numbers button S
{
    currentExpression += "1";
    display->setText(display->text()+= "1");
}
void CalculatorWindow::twoButtonClicked()
{
    currentExpression += "2";
    display->setText(display->text()+= "2");
}
void CalculatorWindow::threeButtonClicked()
{
    currentExpression += "3";
    display->setText(display->text()+= "3");
}
void CalculatorWindow::fourButtonClicked()
{
    currentExpression += "4";
    display->setText(display->text()+= "4");
}
void CalculatorWindow::fiveButtonClicked()
{
    currentExpression += "5";
    display->setText(display->text()+= "5");
}
void CalculatorWindow::sixButtonClicked()
{
    currentExpression += "6";
    display->setText(display->text()+= "6");
}
void CalculatorWindow::sevenButtonClicked()
{
    currentExpression += "7";
    display->setText(display->text()+= "7");
}
void CalculatorWindow::eightButtonClicked()
{
    currentExpression += "8";
    display->setText(display->text()+= "8");
}
void CalculatorWindow::nineButtonClicked()
{
    currentExpression += "9";
    display->setText(display->text()+= "9");
}
void CalculatorWindow::zeroButtonClicked() //! Numbers button E
{
    currentExpression += "0";
    display->setText(display->text()+= "0");
}

void CalculatorWindow::dotButtonClicked()
{
    // Проверка, что строка не пуста и последний символ не точка
    // И что в последнем введенном числе еще нет точки
    if (!currentExpression.empty() && currentExpression.back() != '.')
    {
        size_t last_op = currentExpression.find_last_of("+-*/(");
        std::string last_num = (last_op == std::string::npos) ? currentExpression :
                               currentExpression.substr(last_op + 1);
        if (last_num.find('.') == std::string::npos)
        {
            currentExpression += ".";
            display->setText(display->text()+=".");
        }
    }
    else if (currentExpression.empty()) // Позволяем начать ввод с точки (например, .5)
    {
        currentExpression += "0."; // Добавляем 0 для корректности
        display->setText(display->text()+="0.");
    }
}

void CalculatorWindow::equalClicked()
{
    try {
        double result = answer_function(currentExpression);
        if (std::isnan(result))
        {
            QMessageBox::warning(this, "Error", "Calculation resulted in NaN (e.g., division by zero)");
            display->setText("Error");
            currentExpression = "";
        }
        else if (std::isinf(result))
        {
            QMessageBox::warning(this, "Error", "Calculation resulted in infinity");
            display->setText("Infinity");
            currentExpression = "";
        }
        else
        {
             // Используем QString::number с 'g' для общей точности и представления
             QString resultStr = QString::number(result, 'g', 15); // 15 значащих цифр
             display->setText(resultStr);
             currentExpression = resultStr.toStdString(); // Обновляем строку выражения результатом
        }
    }
    catch (const std::exception& e)
    {
        QMessageBox::critical(this, "Error", QString("Calculation error: %1").arg(e.what()));
        display->setText("Error");
        currentExpression = "";
    }
    catch (...)
    {
        QMessageBox::critical(this, "Unknown Error", "An unexpected error occurred during calculation.");
        display->setText("Error");
        currentExpression = "";
    }
}

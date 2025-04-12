// Created by kleymuner2131 on 26.03.25.
int main_choose(int argc, char* argv[]);
#include "calculator.h"
//#include "calculator2.cpp"
//#include "progression_main.cpp"
#include <iostream>
#include <string>
#include <cmath>

#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLayout>
#include <QTimer>



int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    std::string main;
    QWidget window;
    window.setWindowTitle("Calculator");

    QLineEdit *display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);

    // Создаем кнопки
    QPushButton *one = new QPushButton("1");
    QPushButton *two = new QPushButton("2");
    QPushButton *three = new QPushButton("3");
    QPushButton *four = new QPushButton("4");
    QPushButton *five = new QPushButton("5");
    QPushButton *six = new QPushButton("6");
    QPushButton *seven = new QPushButton("7");
    QPushButton *eight = new QPushButton("8");
    QPushButton *nine = new QPushButton("9");
    QPushButton *zero = new QPushButton("0");
    QPushButton *add = new QPushButton("+");
    QPushButton *sub = new QPushButton("-");
    QPushButton *mul = new QPushButton("*");
    QPushButton *div = new QPushButton("/");
    QPushButton *equal = new QPushButton("=");
    QPushButton *clear = new QPushButton("Cl");
    QPushButton *second = new QPushButton("2nd");
    QPushButton *open = new QPushButton("(");
    QPushButton *close = new QPushButton(")");

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(display, 0, 0, 1, 5);
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
    layout->addWidget(equal, 4, 3, 1,2);
    layout->addWidget(zero, 4, 1);
    layout->addWidget(clear, 4, 2);

    window.setLayout(layout);

    QObject::connect(one, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "1");
        main += "1";
    });
    QObject::connect(two, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "2");
        main += "2";
    });
    QObject::connect(three, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "3");
        main+="3";
    });
    QObject::connect(four, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "4");
        main += "4";
    });
    QObject::connect(five, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "5");
        main += "5";
    });
    QObject::connect(six, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "6");
        main += "6";
    });
    QObject::connect(seven, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "7");
        main += "7";
    });
    QObject::connect(eight, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "8");
        main += "8";
    });
    QObject::connect(nine, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "9");
        main += "9";
    });
    QObject::connect(zero, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "0");
        main += "0";
    });

    QObject::connect(add, &QPushButton::clicked, [&]()
    {
        if (main.back() == '+' || main.back() == '-' || main.back() == '*' || main.back() == '/')
        {
            main.pop_back();
        }
        display->setText(display->text() + "+");
        main += "+";
    });
    QObject::connect(sub, &QPushButton::clicked, [&]()
    {
        if (main.back() == '+' || main.back() == '-' || main.back() == '*' || main.back() == '/')
        {
            main.pop_back();
        }
        display->setText(display->text() + "-");
        main += "-";
    });
    QObject::connect(mul, &QPushButton::clicked, [&]()
    {
        if (main.back() == '+' || main.back() == '-' || main.back() == '*' || main.back() == '/')
        {
            main.pop_back();
        }
        display->setText(display->text() + "*");
    });
    QObject::connect(div, &QPushButton::clicked, [&]()
    {
        if (main.back() == '+' || main.back() == '-' || main.back() == '*' || main.back() == '/')
        {
            main.pop_back();
        }
        display->deleteLater();
        display->setText(display->text() + "/");
        main += "/";
    });

    QObject::connect(clear, &QPushButton::clicked, [&]()
    {
        display->setText("");
        main = "";
    });
    QObject::connect(open, &QPushButton::clicked, [&]()
    {
        display->setText(display->text() + "(");
        main += "(";
    });
    QObject::connect(close, &QPushButton::clicked, [&]()
    {
        display -> setText(display->text() + ")");
        main += ")";
    });

    QObject::connect(equal, &QPushButton::clicked, [&]()
    {
        if (main.back() == '+' || main.back() == '-' || main.back() == '*' || main.back() == '/')
        {
            main.pop_back();
        }
        if (bracketsBalanced(main) == false)
        {
            display->setText("Error: brackets are not balanced");
            display->setStyleSheet("QLineEdit { color: red; }"); // Highlight the message in red for better visibility.
            QTimer::singleShot(5000, [&]()
            {
                display->setStyleSheet(""); // Reset text color.
                display->setText(QString::fromStdString(main));// Clear the error message after 5 seconds and show the existing input.
            });
        }
        else
        {
            std::string result = std::to_string(answer(main));
            display->setText(display->text() + "=" + QString::fromStdString(result));
        }
    });

    QObject::connect(second, &QPushButton::clicked, [&]()
    {
        main_choose(0, nullptr);
    });

    window.show();
    return app.exec();
}

int main_choose(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Progression Calculator");
    window.resize(300, 100);

    QVBoxLayout layout(&window);

    QLabel label("Choose one of the options below:");
    layout.addWidget(&label);

    QHBoxLayout buttons;
    layout.addLayout(&buttons);

    QPushButton arithmetic("Arithmetic Progression");
    QPushButton geometric("Geometric Progression");
    QPushButton manual("Manual");
    QPushButton exit("Exit to Calculator");

    buttons.addWidget(&arithmetic);
    buttons.addWidget(&geometric);
    buttons.addWidget(&manual);
    buttons.addWidget(&exit);

    QObject::connect(&arithmetic, &QPushButton::clicked, [](){});

    QObject::connect(&geometric, &QPushButton::clicked, [](){});

    QObject::connect(&manual, &QPushButton::clicked, [](){});

    QObject::connect(&exit, &QPushButton::clicked, [](){});

    window.show();

    return app.exec();
}

// Created by kleymuner2131 on 25.03.25.
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <string>
#include <cmath>
#include <QMainWindow>
#include "helper.h"
#include "math_expression_evaluator.cpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    std::string main;
    // Главное окно
    QWidget window;
    window.setWindowTitle("Калькулятор");

    // Поле ввода
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

    // Создаем макет
    QGridLayout *layout = new QGridLayout();

    // Располагаем кнопки в макете
    layout->addWidget(display, 0, 0, 1, 4); // Поле ввода занимает всю первую строку
    layout->addWidget(seven, 1, 0);
    layout->addWidget(eight, 1, 1);
    layout->addWidget(nine, 1, 2);
    layout->addWidget(div, 1, 3);

    layout->addWidget(four, 2, 0);
    layout->addWidget(five, 2, 1);
    layout->addWidget(six, 2, 2);
    layout->addWidget(mul, 2, 3);

    layout->addWidget(one, 3, 0);
    layout->addWidget(two, 3, 1);
    layout->addWidget(three, 3, 2);
    layout->addWidget(sub, 3, 3);

    layout->addWidget(clear, 4, 0);
    layout->addWidget(zero, 4, 1);
    layout->addWidget(equal, 4, 2);
    layout->addWidget(add, 4, 3);

    // Устанавливаем макет на окно
    window.setLayout(layout);

    // Подключаем действия кнопок
    QObject::connect(clear, &QPushButton::clicked, [&]() {
        display->clear();
    });

    QObject::connect(one, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "1");
        main += "1";
    });
    QObject::connect(two, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "2");
        main += "2";
    });
    QObject::connect(three, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "3");
        main += "3";
    });
    QObject::connect(four, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "4");
        main += "4";
    });
    QObject::connect(five, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "5");
        main += "5";
    });
    QObject::connect(six, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "6");
        main += "6";
    });
    QObject::connect(seven, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "7");
        main += "7";
    });
    QObject::connect(eight, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "8");
        main += "8";
    });
    QObject::connect(nine, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "9");
        main += "9";
    });
    QObject::connect(zero, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "0");
        main += "0";
    });

    QObject::connect(add, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "+");
        main += "+";
    });
    QObject::connect(sub, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "-");
        main += "-";
    });
    QObject::connect(mul, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "*");
        main += "*";
    });
    QObject::connect(div, &QPushButton::clicked, [&]() {
        display->setText(display->text() + "/");
        main += "/";
    });
    QObject::connect(equal, &QPushButton::clicked, [&]() {
    try {
        // Анализируем введенное выражение
        double result = evaluateMathExpression(main);

        // Отображаем результат в поле ввода
        display->setText(QString::number(result));
        main.clear(); // Очищаем строку, если нужно
    } catch (const std::exception& e) {
        // Если произошла ошибка при анализе
        display->setText("Error");
        main.clear(); // Очищаем строку
    }
});

    // Показываем окно
    window.show();
    return app.exec();
}

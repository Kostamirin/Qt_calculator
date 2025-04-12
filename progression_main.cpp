// Created by kleymuner2131 on 18.03.25.
#include <iostream>
#include "calculator2.cpp"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

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
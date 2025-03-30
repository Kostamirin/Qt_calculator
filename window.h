// Created by kleymuner2131 on 26.03.25.
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <string>
#include <cmath>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLayout>


class window
{
    public:
    void answer(int argc, char* argv[])
    {
        QApplication app(argc,argv);
        QWidget window;
        QLineEdit *display_ans = new QLineEdit();
        display_ans->setReadOnly(true);
        display_ans->setAlignment(Qt::AlignRight);
        window.setWindowTitle("Here's your answer:");
        QGridLayout *layout = new QGridLayout();
        //layout->( , 0, 0, 1, 5);
        layout->addWidget(display_ans, 1, 0, 1, 5);

        window.show();
        //return app.exec();
    }
};

#endif //WINDOW_H

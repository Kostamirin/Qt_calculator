// Created by kleymuner2131 on 14.04.25.
#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <QLineEdit>
#include <QMainWindow>
#include <QWindow>
#include <QWidget>

namespace Ui
{
    class arithmetic_progression;
}

class arithmetic_progression : public QMainWindow
{
    Q_OBJECT

public:
    explicit arithmetic_progression(QWidget *parent = nullptr);
    arithmetic_progression();

private slots:
    void startButtonClicked();

private:


};



#endif //ARITHMETIC_PROGRESSION_H

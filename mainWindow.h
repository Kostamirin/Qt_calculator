//
// Created by kleymuner on 26.03.2026.
//

#ifndef QT_GUI_PROJECT_MAINWINDOW_H
#define QT_GUI_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

namespace Ui { class mainWindow; }

class mainWindow : public QMainWindow
{
    Q_OBJECT
public:

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:

    // Numbers
    void num0Pressed();
    void num1Pressed();
    void num2Pressed();
    void num3Pressed();
    void num4Pressed();
    void num5Pressed();
    void num6Pressed();
    void num7Pressed();
    void num8Pressed();
    void num9Pressed();

    // Characters
    void dotPressed();
    void percentPressed();
    void plusPressed();
    void minusPressed();
    void multiplyPressed();
    void dividePressed();
    void equalsPressed();
    void clearPressed();


private:

    void ini_buttons();
    void ini_fuctional();

    Ui::mainWindow *ui; // Указатель на UI

    // Указатели на кнопки (инициализируются в конструкторе)
    QPushButton * button_1;
    QPushButton * button_2;
    QPushButton * button_3;
    QPushButton * button_4;
    QPushButton * button_5;
    QPushButton * button_6;
    QPushButton * button_7;
    QPushButton * button_8;
    QPushButton * button_9;
    QPushButton * button_0;
    QPushButton * button_dot;
    QPushButton * button_percent;

    QLineEdit * display;  // Дисплей калькулятора
};



#endif //QT_GUI_PROJECT_MAINWINDOW_H
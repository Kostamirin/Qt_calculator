//
// Created by kleymuner on 26.03.2026.
//

#ifndef QT_GUI_PROJECT_MAINWINDOW_H
#define QT_GUI_PROJECT_MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class mainWindow; }

class mainWindow : public QMainWindow
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void num1Pressed();
    void num2Pressed();
    // ...

private:
    Ui::mainWindow *ui; // Указатель на UI

};


#endif //QT_GUI_PROJECT_MAINWINDOW_H
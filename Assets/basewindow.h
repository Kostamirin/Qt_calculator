// Created by kleymuner on 27.03.2026.

#ifndef QT_GUI_PROJECT_BASEWINDOW_H
#define QT_GUI_PROJECT_BASEWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
//#include <map>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class baseWindow;
}

QT_END_NAMESPACE

class baseWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit baseWindow(QWidget* parent = nullptr);
    ~baseWindow() override;

    QAction *toggle_basic;
    QAction *toggle_engineer;

private:
    Ui::baseWindow* ui;
    void ini_buttons();
    void switchToCalculator(std::string type);
    void toggle_basic_window();
    void toggle_engineer_window();
};


#endif //QT_GUI_PROJECT_BASEWINDOW_H

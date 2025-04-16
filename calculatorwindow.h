#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
//#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CalculatorWindow;

}
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    //Functional buttons
    void secondButtonClicked();
    void sumClicked();
    void subClicked();
    void mulClicked();
    void divClicked();
    void equalClicked();
    void clearClicked();
    //Number buttons
    void oneButtonClicked();
    void twoButtonClicked();
    void threeButtonClicked();
    void fourButtonClicked();
    void fiveButtonClicked();
    void sixButtonClicked();
    void sevenButtonClicked();
    void eightButtonClicked();
    void nineButtonClicked();
    void zeroButtonClicked();
    void openButtonClicked();
    void closeButtonClicked();
    void dotButtonClicked();

private:
    QLineEdit *display;
    // Add button members later
    // Add calculation logic members later
};
#endif // CALCULATORWINDOW_H

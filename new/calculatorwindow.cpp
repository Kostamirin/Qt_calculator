#include "calculatorwindow.h"
#include "secondwindow.h" // Include header for the second window
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

CalculatorWindow::CalculatorWindow(QWidget *parent):QMainWindow(parent)
{
    // Basic window setup
    setWindowTitle("Calculator");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QGridLayout *layout = new QGridLayout(centralWidget);

    // Display
    display = new QLineEdit("0");
    display->setReadOnly(false);
    display->setAlignment(Qt::AlignRight);
    layout->addWidget(display, 0, 0, 1, 5); // Span across 4 columns

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
    QPushButton *close = new QPushButton(")");


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
    layout->addWidget(equal, 4, 3, 1,2);
    layout->addWidget(zero, 4, 1);
    layout->addWidget(clear, 4, 2);
}

CalculatorWindow::~CalculatorWindow()
{
    // Destructor - Qt handles child widgets automatically
}
void secondButtonClicked()
{
    QDebug(secondwindow) <<"Second button clicked";
    SecondWindow *secondWindow = new SecondWindow(this);
    secondWindow->show();
    secondWindow.exec();
    delete secondWindow;
}
void sumClicked();
void subClicked();
void mulClicked();
void divClicked();
void equalClicked();
void clearClicked();
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


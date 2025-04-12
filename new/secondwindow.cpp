#include "secondwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox> // For Help dialog
#include <QDebug>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent)
    // , ui(new Ui::SecondWindow) // If using Qt Designer
{
    // ui->setupUi(this); // If using Qt Designer
    setWindowTitle("Second Menu");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *btnArithmetic = new QPushButton("1. Arithmetic Progression");
    QPushButton *btnGeometric = new QPushButton("2. Geometric Progression");
    QPushButton *btnHelp = new QPushButton("3. Help");
    QPushButton *btnExit = new QPushButton("4. Exit (Back to Calculator)");

    layout->addWidget(btnArithmetic);
    layout->addWidget(btnGeometric);
    layout->addWidget(btnHelp);
    layout->addWidget(btnExit);

    connect(btnArithmetic, &QPushButton::clicked, this, &SecondWindow::handleArithmeticProgression);
    connect(btnGeometric, &QPushButton::clicked, this, &SecondWindow::handleGeometricProgression);
    connect(btnHelp, &QPushButton::clicked, this, &SecondWindow::handleHelp);
    // Connect Exit button to close the dialog
    connect(btnExit, &QPushButton::clicked, this, &QDialog::accept); // or reject(), or close()

    setLayout(layout);
}

SecondWindow::~SecondWindow()
{
    // delete ui; // If using Qt Designer
    qDebug() << "SecondWindow destroyed";
}

void SecondWindow::handleArithmeticProgression()
{
    qDebug() << "Arithmetic Progression clicked (Placeholder)";
    // TODO: Implement Arithmetic Progression functionality or window
    QMessageBox::information(this, "WIP", "Arithmetic Progression - Not Implemented Yet");
    // Potentially close this dialog after showing the new one/doing the work
    // accept();
}

void SecondWindow::handleGeometricProgression()
{
    qDebug() << "Geometric Progression clicked (Placeholder)";
    // TODO: Implement Geometric Progression functionality or window
    QMessageBox::information(this, "WIP", "Geometric Progression - Not Implemented Yet");
    // accept();
}

void SecondWindow::handleHelp()
{
    qDebug() << "Help clicked";
    // Show a simple help message box
    QMessageBox::information(this, "Help", "This is the secondary menu.\n1. Arithmetic Progression: (Not Implemented)\n2. Geometric Progression: (Not Implemented)\n3. Help: Shows this message.\n4. Exit: Returns to the main calculator.");
    // Do not close the dialog after showing help
}

// No separate handleExit needed as we connected the button directly to accept()

#include "secondwindow.h"
#include "arithmetic_progression.h"
#include "geometric_progression.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
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
    arithmetic_progression *window = new arithmetic_progression(this); // Keep 'this' as parent for now
    // delete this; // DANGEROUS: Do not delete the current window here
    window->setAttribute(Qt::WA_DeleteOnClose); // Ensure the window is deleted when closed
    window->show(); // Show the window non-modally
}

void SecondWindow::handleGeometricProgression()
{
    geometric_progression *window = new geometric_progression(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}

void SecondWindow::handleHelp()
{
    qDebug() << "Help clicked";
    // Show a simple help message box
    QMessageBox::information(this, "Help", "This is the secondary menu.\n1. Arithmetic Progression: Calculate values for arithmetic progressions.\n2. Geometric Progression: Calculate values for geometric progressions.\n3. Help: Shows this message.\n4. Exit: Returns to the main calculator.");
    // Do not close the dialog after showing help
}

// No separate handleExit needed as we connected the button directly to accept()



// Created by kleymuner2131 on 14.04.25.
#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <QMainWindow> 
#include <QDebug> 

// Forward declarations if needed, though likely handled by includes
QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class arithmetic_progression : public QMainWindow {
    Q_OBJECT

public:
    explicit arithmetic_progression(QWidget *parent = nullptr);

// signals:
    // void calculationRequested(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms);

private slots:
    void on_calculateButton_clicked();
    // void on_resetButton_clicked();

private:
    // Function to calculate arithmetic progression
    // void calculateArithmeticProgression(); // This was likely a member function placeholder, the free function is separate

    // UI elements
    QLineEdit *firstTermInput;
    QLineEdit *stepInput;
    QLineEdit *termNumberInput;
    QLineEdit *termValueInput;
    QLineEdit *sumOfTermsInput;
    QLabel *resultLabel;
    // QLabel *firstLabel;
    // ... other labels
    // QHBoxLayout *firstLayout;
    // ... other layouts
    // QVBoxLayout *mainLayout;
};

// Declaration of the standalone function
float calculateArithmeticProgression(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms);

#endif // ARITHMETIC_PROGRESSION_H

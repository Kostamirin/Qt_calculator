// Created by kleymuner2131 on 14.04.25.
#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <QMainWindow> 
#include <QDebug>
#include <QVBoxLayout>

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
    void calculation_button_clicked();
    void calculateArithmeticProgression(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms);
    ~arithmetic_progression();  // деструктор для очистки элементов пользовательского интерфейса

    inline bool arithmetic_progression::isUnknown(float val);
    inline bool arithmetic_progression::isUnknown(int val);

    // void on_resetButton_clicked();

private:
    QVBoxLayout *mainLayout;
    // UI elements
    QLineEdit *firstInput;
    QLineEdit *differenceInput;
    QLineEdit *termsInput;
    QLineEdit *lastTermInput;
    QLineEdit *sumInput;
    QLabel *resultLabel;
    QPushButton *calculation_trigger_button;

    // UI labels
    QLabel *firstLabel;
    QLabel *differenceLabel;
    QLabel *termsLabel;
    QLabel *lastTermLabel;
    QLabel *sumLabel;
    QWidget *centralWidget;

    // UI layouts
    QHBoxLayout *firstLayout;
    QHBoxLayout *differenceLayout;
    QHBoxLayout *termsLayout;
    QHBoxLayout *lastTermLayout;
    QHBoxLayout *sumLayout;
};

// Declaration of the standalone function
float calculateArithmeticProgression(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms);

#endif // ARITHMETIC_PROGRESSION_H

// Created by kleymuner2131 on 14.04.25.
#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <QLineEdit>
#include <QMainWindow>
#include <QWidget>
#include <QDebug>

class QLabel;
class QVBoxLayout;
class QHBoxLayout;

namespace Ui
{
    class arithmetic_progression;
}

class arithmetic_progression : public QMainWindow
{
    Q_OBJECT

public:
    explicit arithmetic_progression(QWidget *parent = nullptr);

private slots:
    void calculation_button_clicked();

private:
    QLineEdit *firstInput;
    QLineEdit *differenceInput;
    QLineEdit *termsInput;
    QLineEdit *lastTermInput;
    QLineEdit *sumInput;

    // QLabel *firstLabel;
    // ... other labels
    // QHBoxLayout *firstLayout;
    // ... other layouts
    // QVBoxLayout *mainLayout;
};

float calculateArithmeticProgression(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms)
{
    if (sumOfTerms != -1 && firstTerm != -1 && termValue != -1 && termNumber == -1)
        {
            termNumber = (2 * sumOfTerms) / (firstTerm + termValue);
            qDebug() << "Calculated term number (n): " << termNumber << "\n";
        }
        // Case 2: Calculate n if S_n, a_1 and d are known
        else if (sumOfTerms != -1 && firstTerm != -1 && step != -1 && termNumber == -1)
        {
            // Quadratic equation: n = [-1 ± sqrt(1 + 8*S_n/d)] / 2
            double discriminant = 1 + 8.0 * sumOfTerms / step;
            if (discriminant >= 0)
            {
                termNumber = (-1 + static_cast<int>(std::sqrt(discriminant))) / 2; // Taking the positive result
                qDebug() << "Calculated term number (n): " << termNumber << "\n";
            }
            else
            {
                qDebug << "Error: Cannot calculate term number (n), negative discriminant.\n";
            }
        }
        // Case 3: Find a_n if a_1, n, and S_n are known
        else if (sumOfTerms != -1 && firstTerm != -1 && termNumber != -1 && termValue == -1)
        {
            termValue = (2 * sumOfTerms / termNumber) - firstTerm;
            qDebug << "Value of " << termNumber << "-th term (a_" << termNumber << "): " << termValue << "\n";
        }
        // Case 4: Find d if a_n and a_1 are known
        else if (termValue != -1 && firstTerm != -1 && termNumber != -1 && step == -1)
        {
            step = (termValue - firstTerm) / (termNumber - 1);
            qDebug << "Calculated step of progression (d): " << step << "\n";
        }
        // Case 5: Calculate a_n and/or S_n if n, a_1 and d are known
        else if (termValue == -1 && termNumber != -1 && firstTerm != -1 && step != -1)
        {
            termValue = firstTerm + (termNumber - 1) * step;
            qDebug << "Value of " << termNumber << "-th term (a_" << termNumber << "): " << termValue << "\n";

            // Calculate S_n = n/2 * (a_1 + a_n)
            sumOfTerms = termNumber * (firstTerm + termValue) / 2;
            qDebug << "Sum of first " << termNumber << " terms (S_" << termNumber << "): " << sumOfTerms << "\n";
        }
        else
        {
            qDebug << "Error: Not enough data to proceed with calculations.\n";
        }
}

#endif //ARITHMETIC_PROGRESSION_H

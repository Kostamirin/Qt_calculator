// Created by kleymuner2131 on 14.04.25.
//#include <QApplication> // Needed only if using QApplication:: stuff directly, often only needed in main.cpp
// #include <QWindow> // Not directly needed here
#include "arithmetic_progression.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <cmath> // For std::sqrt, std::isnan, std::round, std::fmod
#include <limits> // For std::numeric_limits

arithmetic_progression::arithmetic_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set up the layout for the arithmetic progression window
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);


    // Create horizontal layout for each parameter
    QPushButton calculation_trigger_button("Calculate");
    connect(&calculation_trigger_button, &QPushButton::clicked, this, &arithmetic_progression::calculation_button_clicked);
    QHBoxLayout *firstLayout = new QHBoxLayout();
    QLabel *firstLabel = new QLabel("First Term (a_1):");
    firstInput = new QLineEdit(); // Assign to member variable
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    QHBoxLayout *differenceLayout = new QHBoxLayout();
    QLabel *differenceLabel = new QLabel("Common Difference (d):");
    differenceInput = new QLineEdit(); // Assign to member variable
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput);

    QHBoxLayout *termsLayout = new QHBoxLayout();
    QLabel *termsLabel = new QLabel("Number of Terms (n):");
    termsInput = new QLineEdit(); // Assign to member variable
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    QHBoxLayout *lastTermLayout = new QHBoxLayout();
    QLabel *lastTermLabel = new QLabel("Last Term (a_n):");
    lastTermInput = new QLineEdit(); // Assign to member variable
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    QHBoxLayout *sumLayout = new QHBoxLayout();
    QLabel *sumLabel = new QLabel("Sum of Terms (S_n):");
    sumInput = new QLineEdit(); // Assign to member variable
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Добавление кнопки
    mainLayout->addWidget(&calculation_trigger_button);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);

    // TODO: Add a button to trigger calculations
    // TODO: Connect button's clicked() signal to a slot (e.g., startButtonClicked)
}

void arithmetic_progression::calculation_button_clicked()
{
    // TODO: Implement calculation logic
    float a1 = firstInput->text().toFloat();
    float d = differenceInput->text().toFloat();
    int n = termsInput->text().toInt();
    float an = lastTermInput->text().toFloat();
    float sn = sumInput->text().toFloat();
    // Call the appropriate function or method to calculate the arithmetic progression
    float result = calculateArithmeticProgression(a1, d, n, an, sn);
    // Display the result

}

// Define sentinel values for unknown inputs
const float UNKNOWN_FLOAT = std::numeric_limits<float>::quiet_NaN();
const int   UNKNOWN_INT   = std::numeric_limits<int>::min();

// Helper function to check if a float value represents an unknown input
inline bool isUnknown(float val) {
    return std::isnan(val);
}

// Helper function to check if an int value represents an unknown input
inline bool isUnknown(int val) {
    return val == UNKNOWN_INT;
}

float arithmetic_progression::calculateArithmeticProgression(float firstTerm, float step, int termNumber, float termValue, float sumOfTerms)
{
    int originalTermNumber = termNumber; // Store originals to know what was calculated
    float originalTermValue = termValue;
    float originalStep = step;
    float originalSumOfTerms = sumOfTerms;

    // Case 1: Calculate n if S_n, a_1 and a_n are known
    if (!isUnknown(sumOfTerms) && !isUnknown(firstTerm) && !isUnknown(termValue) && isUnknown(termNumber))
    {
        if (firstTerm + termValue != 0) { // Avoid division by zero
            double n_calc = (2.0 * sumOfTerms) / (firstTerm + termValue);
            // Check if result is a positive integer
            if (n_calc > 0 && std::round(n_calc) == n_calc) {
                termNumber = static_cast<int>(std::round(n_calc));
                qDebug() << "Calculated term number (n) from S_n, a_1, a_n: " << termNumber;
            } else {
                 qDebug() << "Error: Calculation resulted in non-positive or non-integer term number (n).";
                 // termNumber remains UNKNOWN_INT
            }
        } else {
            qDebug() << "Error: Cannot calculate term number (n) - division by zero (a_1 + a_n = 0).";
            // termNumber remains UNKNOWN_INT
        }
    }
    // Case 2: Calculate n if S_n, a_1 and d are known
    else if (!isUnknown(sumOfTerms) && !isUnknown(firstTerm) && !isUnknown(step) && isUnknown(termNumber))
    {
        if (step == 0) {
            if (sumOfTerms == 0 && firstTerm == 0) {
                 qDebug() << "Cannot determine n: Progression is all zeros.";
                 // termNumber remains UNKNOWN_INT
            } else if (firstTerm != 0 && sumOfTerms / firstTerm > 0 && std::fmod(sumOfTerms, firstTerm) == 0 ) {
                 termNumber = static_cast<int>(sumOfTerms / firstTerm);
                 qDebug() << "Calculated term number (n) for constant progression: " << termNumber;
            } else {
                 qDebug() << "Error: Cannot determine n for constant progression with given sum.";
                 // termNumber remains UNKNOWN_INT
            }
        }
        else {
            // Quadratic equation derived from S_n = n/2 * [2a_1 + (n-1)d]
            // => 2*S_n = n * (2a_1 + nd - d)
            // => 2*S_n = 2a_1*n + d*n^2 - d*n
            // => d*n^2 + (2a_1 - d)*n - 2*S_n = 0
            // Using quadratic formula: n = [-b ± sqrt(b^2 - 4ac)] / 2a
            // where a = d, b = 2a_1 - d, c = -2*S_n
            double b_term = 2 * firstTerm - step;
            double discriminant = b_term * b_term - 4 * step * (-2 * sumOfTerms);

            if (discriminant >= 0)
            {
                double sqrt_discriminant = std::sqrt(discriminant);
                // Calculate both possible solutions for n
                double n1 = (-b_term + sqrt_discriminant) / (2 * step);
                double n2 = (-b_term - sqrt_discriminant) / (2 * step);

                // Choose the valid positive integer solution for n
                if (n1 > 0 && std::round(n1) == n1) {
                    termNumber = static_cast<int>(std::round(n1));
                    qDebug() << "Calculated term number (n) from S_n, a_1, d (solution 1): " << termNumber;
                } else if (n2 > 0 && std::round(n2) == n2) {
                    termNumber = static_cast<int>(std::round(n2));
                    qDebug() << "Calculated term number (n) from S_n, a_1, d (solution 2): " << termNumber;
                } else {
                    qDebug() << "Error: No valid positive integer term number (n) found.";
                    // termNumber remains UNKNOWN_INT
                }
            }
            else
            {
                qDebug() << "Error: Cannot calculate term number (n), negative discriminant in quadratic formula.";
                // termNumber remains UNKNOWN_INT
            }
        }
    }
    // Case 3: Find a_n if a_1, n, and S_n are known
    else if (isUnknown(termValue) && !isUnknown(firstTerm) && !isUnknown(termNumber) && !isUnknown(sumOfTerms))
    {
        if (!isUnknown(termNumber) && termNumber != 0) { // Avoid division by zero
             termValue = (2.0 * sumOfTerms / termNumber) - firstTerm;
             qDebug() << "Calculated value of " << termNumber << "-th term (a_n) from S_n, a_1, n: " << termValue;
        } else {
             qDebug() << "Error: Cannot calculate a_n - term number (n) is zero or unknown.";
             // termValue remains UNKNOWN_FLOAT (NaN)
        }
    }
    // Case 4: Find d if a_n, a_1 and n are known
    else if (isUnknown(step) && !isUnknown(termValue) && !isUnknown(firstTerm) && !isUnknown(termNumber))
    {
        if (!isUnknown(termNumber) && termNumber > 1) {
            step = (termValue - firstTerm) / (termNumber - 1);
            qDebug() << "Calculated step of progression (d) from a_n, a_1, n: " << step;
        } else if (!isUnknown(termNumber) && termNumber == 1) {
             if (termValue == firstTerm) {
                 qDebug() << "Step (d) is indeterminate when n=1 (any d is possible).";
                 // step remains UNKNOWN_FLOAT (NaN)
             } else {
                 qDebug() << "Error: Inconsistent data - a_n != a_1 when n=1.";
                 // step remains UNKNOWN_FLOAT (NaN)
             }
         } else {
              qDebug() << "Error: Cannot calculate step (d) - term number (n) must be > 1.";
              // step remains UNKNOWN_FLOAT (NaN)
         }
     }
     // Case 5: Calculate a_n and/or S_n if n, a_1 and d are known
     else if (!isUnknown(termNumber) && !isUnknown(firstTerm) && !isUnknown(step))
     {
         // Calculate a_n only if it wasn't provided
         if (isUnknown(termValue)) {
             termValue = firstTerm + (termNumber - 1) * step;
             qDebug() << "Calculated value of " << termNumber << "-th term (a_n) from a_1, n, d: " << termValue;
         }
         // Calculate S_n only if it wasn't provided
         if (isUnknown(sumOfTerms)) {
             // Use the calculated or provided a_n
             if (!isUnknown(termValue)) { // Ensure a_n is known before calculating S_n
                  sumOfTerms = termNumber * (firstTerm + termValue) / 2.0;
                  qDebug() << "Calculated sum of first " << termNumber << " terms (S_n) from a_1, n, a_n: " << sumOfTerms;
             } else {
                  qDebug() << "Cannot calculate S_n because a_n could not be determined or wasn't provided.";
                  // sumOfTerms remains UNKNOWN_FLOAT (NaN)
             }
         }
     }

     // --- Return logic ---
     // The function should ideally return the value that was calculated.
     // We check which variable was originally unknown and is now known.
     if (isUnknown(originalTermNumber) && !isUnknown(termNumber)) {
         return static_cast<float>(termNumber);
     }
     if (isUnknown(originalTermValue) && !isUnknown(termValue)) {
         return termValue;
     }
     if (isUnknown(originalStep) && !isUnknown(step)) {
         return step;
     }
     if (isUnknown(originalSumOfTerms) && !isUnknown(sumOfTerms)) {
         return sumOfTerms;
     }

     // If no specific value was calculated (e.g., ambiguous input, error, or nothing was unknown)
     // return NaN to indicate failure or no result.
     return std::numeric_limits<float>::quiet_NaN(); // Return NaN if nothing specific was calculated
}

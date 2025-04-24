// Created by kleymuner2131 on 21.04.25.

#include "geometric_progression.h"
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <cmath>
#include <limits>

geometric_progression::geometric_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    setWindowTitle("Geometric Progression Calculator");

    // Set up the layout for the geometric progression window
    mainLayout = new QVBoxLayout(centralWidget);

    // Create horizontal layout for each parameter
    firstLayout = new QHBoxLayout();
    firstLabel = new QLabel("First Term (b₁):");
    firstInput = new QLineEdit();
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    ratioLayout = new QHBoxLayout();
    ratioLabel = new QLabel("Common Ratio (q):");
    ratioInput = new QLineEdit();
    ratioLayout->addWidget(ratioLabel);
    ratioLayout->addWidget(ratioInput);

    termsLayout = new QHBoxLayout();
    termsLabel = new QLabel("Number of Terms (n):");
    termsInput = new QLineEdit();
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    lastTermLayout = new QHBoxLayout();
    lastTermLabel = new QLabel("Last Term (bₙ):");
    lastTermInput = new QLineEdit();
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    sumLayout = new QHBoxLayout();
    sumLabel = new QLabel("Sum of Terms (Sₙ):");
    sumInput = new QLineEdit();
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(ratioLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);

    // Add calculation button
    calculationButton = new QPushButton("Calculate");
    connect(calculationButton, &QPushButton::clicked, this, &geometric_progression::calculation_button_clicked);
    mainLayout->addWidget(calculationButton);
}

geometric_progression::~geometric_progression()
{
    // Qt automatically cleans up child widgets and layouts
}

void geometric_progression::calculation_button_clicked()
{
    // Read and process each input: if empty, treat as unknown; otherwise, convert.
    float b1 = UNKNOWN_FLOAT;
    float q = UNKNOWN_FLOAT;
    int n = UNKNOWN_INT;
    float bn = UNKNOWN_FLOAT;
    float sn = UNKNOWN_FLOAT;
    int known_count = 0;

    // Helper lambda for parsing float
    auto parseFloat = [&](QLineEdit* input, float& value) {
        QString text = input->text().trimmed();
        if (!text.isEmpty()) {
            bool ok = false;
            value = text.toFloat(&ok);
            if (!ok) {
                value = UNKNOWN_FLOAT;
                QMessageBox::warning(this, "Input Error", "Invalid float value in field: " + input->objectName());
                return false; // Parsing error
            } else {
                known_count++;
            }
        }
        return true; // Success or field is empty
    };

    // Helper lambda for parsing int
    auto parseInt = [&](QLineEdit* input, int& value) {
        QString text = input->text().trimmed();
        if (!text.isEmpty()) {
            bool ok = false;
            value = text.toInt(&ok);
            if (!ok || value <= 0) { // Term number must be positive
                if (!ok) QMessageBox::warning(this, "Input Error", "Invalid integer value in field: " + input->objectName());
                else QMessageBox::warning(this, "Input Error", "Number of terms (n) must be positive: " + input->objectName());
                value = UNKNOWN_INT;
                return false; // Parsing error
            }
            else {
                known_count++;
            }
        }
        return true; // Success or field is empty
    };

    // Set objectName for input fields for informative error messages
    firstInput->setObjectName("First Term (b₁)");
    ratioInput->setObjectName("Common Ratio (q)");
    termsInput->setObjectName("Number of Terms (n)");
    lastTermInput->setObjectName("Last Term (bₙ)");
    sumInput->setObjectName("Sum of Terms (Sₙ)");

    if (!parseFloat(firstInput, b1)) return;
    if (!parseFloat(ratioInput, q)) return;
    if (!parseInt(termsInput, n)) return;
    if (!parseFloat(lastTermInput, bn)) return;
    if (!parseFloat(sumInput, sn)) return;

    // Check if we have enough data to calculate (usually need 3)
    if (known_count < 3) {
        QMessageBox::information(this, "Insufficient Data", "Please provide at least three known values to calculate the others.");
        return;
    }

    // Save copies for checking what changed
    float b1_orig = b1, q_orig = q, bn_orig = bn, sn_orig = sn;
    int n_orig = n;

    // Call the calculation function
    try {
        calculate(b1, q, n, bn, sn);
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Calculation Error", QString("Error during calculation: %1").arg(e.what()));
        return;
    }

    // Update output fields if values were calculated
    if (isUnknown(b1_orig) && !isUnknown(b1)) firstInput->setText(QString::number(b1, 'g', 10));
    if (isUnknown(q_orig) && !isUnknown(q)) ratioInput->setText(QString::number(q, 'g', 10));
    if (isUnknown(n_orig) && !isUnknown(n)) termsInput->setText(QString::number(n));
    if (isUnknown(bn_orig) && !isUnknown(bn)) lastTermInput->setText(QString::number(bn, 'g', 10));
    if (isUnknown(sn_orig) && !isUnknown(sn)) sumInput->setText(QString::number(sn, 'g', 10));

    // Check if there are still unknowns after calculation attempt
    int unknown_count_after = 0;
    if (isUnknown(b1)) unknown_count_after++;
    if (isUnknown(q)) unknown_count_after++;
    if (isUnknown(n)) unknown_count_after++;
    if (isUnknown(bn)) unknown_count_after++;
    if (isUnknown(sn)) unknown_count_after++;

    if (unknown_count_after > 0 && known_count + (5 - unknown_count_after) < 5) {
        // If not everything was calculated and there were fewer than 5 initial data points
        QMessageBox::warning(this, "Calculation Incomplete", "Could not determine all unknown values with the provided data.");
    } else if (unknown_count_after == 0) {
        QMessageBox::information(this, "Calculation Complete", "All values calculated successfully.");
    }

void geometric_progression::calculate(float &firstTerm, float &ratio, int &termNumber, float &lastTerm, float& sum)
{
    // Implementation of geometric progression calculations
    int calculated_count = 0; // Counter for successfully calculated values per iteration
    const int MAX_ITERATIONS = 5; // Prevent infinite loop
    int iterations = 0;

    do {
        calculated_count = 0;
        iterations++;

        // Case 1: Calculate lastTerm if firstTerm, ratio, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(ratio) && !isUnknown(termNumber) && isUnknown(lastTerm)) {
            if (termNumber >= 1) {
                // bₙ = b₁ * q^(n-1)
                lastTerm = firstTerm * std::pow(ratio, termNumber - 1);
                calculated_count++;
                qDebug() << "Calculated last term (bₙ) from b₁, q, n: " << lastTerm;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating last term (bₙ).";
            }
        }

        // Case 2: Calculate firstTerm if lastTerm, ratio, and termNumber are known
        if (isUnknown(firstTerm) && !isUnknown(lastTerm) && !isUnknown(ratio) && !isUnknown(termNumber)) {
            if (termNumber >= 1) {
                if (ratio != 0) {
                    // b₁ = bₙ / q^(n-1)
                    firstTerm = lastTerm / std::pow(ratio, termNumber - 1);
                    calculated_count++;
                    qDebug() << "Calculated first term (b₁) from bₙ, q, n: " << firstTerm;
                } else {
                    qDebug() << "Error: Cannot calculate first term with ratio = 0.";
                }
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating first term (b₁).";
            }
        }

        // Case 3: Calculate ratio if firstTerm, lastTerm, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(lastTerm) && isUnknown(ratio) && !isUnknown(termNumber)) {
            if (termNumber > 1) {
                if (firstTerm != 0) {
                    // q = (bₙ/b₁)^(1/(n-1))
                    ratio = std::pow(lastTerm / firstTerm, 1.0 / (termNumber - 1));
                    calculated_count++;
                    qDebug() << "Calculated ratio (q) from b₁, bₙ, n: " << ratio;
                } else {
                    qDebug() << "Error: Cannot calculate ratio with first term = 0.";
                }
            } else if (termNumber == 1) {
                if (lastTerm == firstTerm) {
                    qDebug() << "Cannot determine ratio (q): Only one term (n=1). Ratio can be any value.";
                } else {
                    qDebug() << "Error: Inconsistent data for n=1. bₙ must equal b₁.";
                }
            } else {
                qDebug() << "Error: Invalid term number (n <= 0) for calculating ratio (q).";
            }
        }

        // Case 4: Calculate termNumber if firstTerm, lastTerm, and ratio are known
        if (!isUnknown(firstTerm) && !isUnknown(lastTerm) && !isUnknown(ratio) && isUnknown(termNumber)) {
            if (firstTerm != 0 && ratio > 0) {
                // n = log(bₙ/b₁)/log(q) + 1
                double n_calc = std::log(lastTerm / firstTerm) / std::log(ratio) + 1;
                if (n_calc > 0 && std::abs(n_calc - std::round(n_calc)) < 1e-10) {
                    termNumber = static_cast<int>(std::round(n_calc));
                    calculated_count++;
                    qDebug() << "Calculated term number (n) from b₁, bₙ, q: " << termNumber;
                } else {
                    qDebug() << "Error: Calculation resulted in non-positive or non-integer term number (n).";
                }
            } else {
                qDebug() << "Error: Cannot calculate term number with given values.";
            }
        }

        // Case 5: Calculate sum if firstTerm, ratio, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(ratio) && !isUnknown(termNumber) && isUnknown(sum)) {
            if (termNumber >= 1) {
                if (std::abs(ratio - 1.0) < 1e-10) {
                    // Sum = n * b₁ when q = 1
                    sum = termNumber * firstTerm;
                } else {
                    // Sum = b₁ * (1 - q^n) / (1 - q)
                    sum = firstTerm * (1 - std::pow(ratio, termNumber)) / (1 - ratio);
                }
                calculated_count++;
                qDebug() << "Calculated sum (Sₙ) from b₁, q, n: " << sum;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating sum (Sₙ).";
            }
        }

        // Case 6: Calculate firstTerm if sum, ratio, and termNumber are known
        if (isUnknown(firstTerm) && !isUnknown(sum) && !isUnknown(ratio) && !isUnknown(termNumber)) {
            if (termNumber >= 1) {
                if (std::abs(ratio - 1.0) < 1e-10) {
                    // b₁ = Sₙ / n when q = 1
                    firstTerm = sum / termNumber;
                } else {
                    // b₁ = Sₙ * (1 - q) / (1 - q^n)
                    double denominator = 1 - std::pow(ratio, termNumber);
                    if (std::abs(denominator) > 1e-10) {
                        firstTerm = sum * (1 - ratio) / denominator;
                    } else {
                        qDebug() << "Error: Division by zero when calculating first term.";
                        continue;
                    }
                }
                calculated_count++;
                qDebug() << "Calculated first term (b₁) from Sₙ, q, n: " << firstTerm;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating first term (b₁).";
            }
        }

        // Case 7: Calculate ratio if firstTerm, sum, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(sum) && isUnknown(ratio) && !isUnknown(termNumber)) {
            if (termNumber > 1 && firstTerm != 0) {
                // This requires solving a polynomial equation, which is complex
                // For now, we'll use a numerical approach for common cases
                if (sum == termNumber * firstTerm) {
                    // If sum = n * b₁, then q = 1
                    ratio = 1.0;
                    calculated_count++;
                    qDebug() << "Calculated ratio (q=1) from b₁, Sₙ, n: " << ratio;
                } else {
                    // Try to solve for q using the formula: Sₙ = b₁ * (1 - q^n) / (1 - q)
                    // This is a complex equation to solve directly
                    qDebug() << "Cannot directly solve for ratio (q) from b₁, Sₙ, n. Need additional information.";
                }
            } else if (termNumber == 1) {
                if (sum == firstTerm) {
                    qDebug() << "Cannot determine ratio (q): Only one term (n=1). Ratio can be any value.";
                } else {
                    qDebug() << "Error: Inconsistent data for n=1. Sₙ must equal b₁.";
                }
            } else {
                qDebug() << "Error: Invalid parameters for calculating ratio (q).";
            }
        }

        // Case 8: Calculate termNumber if firstTerm, sum, and ratio are known
        if (!isUnknown(firstTerm) && !isUnknown(sum) && !isUnknown(ratio) && isUnknown(termNumber)) {
            if (firstTerm != 0) {
                if (std::abs(ratio - 1.0) < 1e-10) {
                    // If q = 1, then n = Sₙ / b₁
                    double n_calc = sum / firstTerm;
                    if (n_calc > 0 && std::abs(n_calc - std::round(n_calc)) < 1e-10) {
                        termNumber = static_cast<int>(std::round(n_calc));
                        calculated_count++;
                        qDebug() << "Calculated term number (n) from b₁, Sₙ, q=1: " << termNumber;
                    } else {
                        qDebug() << "Error: Calculation resulted in non-positive or non-integer term number (n).";
                    }
                } else {
                    // For q ≠ 1, solve: Sₙ = b₁ * (1 - q^n) / (1 - q)
                    // Rearranging: q^n = 1 - Sₙ * (1 - q) / b₁
                    // n = log(1 - Sₙ * (1 - q) / b₁) / log(q)
                    double numerator = 1 - sum * (1 - ratio) / firstTerm;
                    if (numerator > 0 && ratio > 0) {
                        double n_calc = std::log(numerator) / std::log(ratio);
                        if (n_calc > 0 && std::abs(n_calc - std::round(n_calc)) < 1e-10) {
                            termNumber = static_cast<int>(std::round(n_calc));
                            calculated_count++;
                            qDebug() << "Calculated term number (n) from b₁, Sₙ, q: " << termNumber;
                        } else {
                            qDebug() << "Error: Calculation resulted in non-positive or non-integer term number (n).";
                        }
                    } else {
                        qDebug() << "Error: Cannot calculate term number with given values.";
                    }
                }
            } else {
                qDebug() << "Error: Cannot calculate term number with first term = 0.";
            }
        }

        // Case 9: Calculate sum if firstTerm, lastTerm, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(lastTerm) && !isUnknown(termNumber) && isUnknown(sum)) {
            if (termNumber >= 1) {
                if (termNumber == 1) {
                    sum = firstTerm; // Only one term
                } else {
                    // For geometric progression, if b₁ and bₙ are known:
                    // Calculate q first: q = (bₙ/b₁)^(1/(n-1))
                    double q_calc = std::pow(lastTerm / firstTerm, 1.0 / (termNumber - 1));
                    
                    if (std::abs(q_calc - 1.0) < 1e-10) {
                        // If q = 1, then Sₙ = n * b₁
                        sum = termNumber * firstTerm;
                    } else {
                        // Otherwise, Sₙ = b₁ * (1 - q^n) / (1 - q)
                        sum = firstTerm * (1 - std::pow(q_calc, termNumber)) / (1 - q_calc);
                    }
                }
                calculated_count++;
                qDebug() << "Calculated sum (Sₙ) from b₁, bₙ, n: " << sum;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating sum (Sₙ).";
            }
        }

        // Case 10: Calculate lastTerm if firstTerm, sum, and termNumber are known
        if (!isUnknown(firstTerm) && !isUnknown(sum) && !isUnknown(termNumber) && isUnknown(lastTerm)) {
            if (termNumber >= 1) {
                if (termNumber == 1) {
                    lastTerm = firstTerm; // Only one term
                    calculated_count++;
                    qDebug() << "Calculated last term (bₙ) for n=1: " << lastTerm;
                } else {
                    // This is complex to solve directly
                    // We need to find q first, which requires solving a polynomial equation
                    // For now, we'll handle the simple case where q = 1
                    if (sum == termNumber * firstTerm) {
                        // If sum = n * b₁, then q = 1, and bₙ = b₁
                        lastTerm = firstTerm;
                        calculated_count++;
                        qDebug() << "Calculated last term (bₙ) for q=1: " << lastTerm;
                    } else {
                        qDebug() << "Cannot directly calculate last term from b₁, Sₙ, n. Need additional information.";
                    }
                }
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating last term (bₙ).";
            }
        }

    } while (calculated_count > 0 && iterations < MAX_ITERATIONS);

    if (iterations >= MAX_ITERATIONS) {
        qDebug() << "Warning: Calculation stopped after maximum iterations.";
    }
}

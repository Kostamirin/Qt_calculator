    // Created by kleymuner2131 on 14.04.25.
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

// Инициализация статических констант
const float UNKNOWN_FLOAT = std::numeric_limits<float>::quiet_NaN();
const int   UNKNOWN_INT   = std::numeric_limits<int>::min();

arithmetic_progression::arithmetic_progression(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget and set it as the main window's central widget
    centralWidget = new QWidget(this); // Присваиваем члену класса
    setCentralWidget(centralWidget);

    // Set up the layout for the arithmetic progression window
    mainLayout = new QVBoxLayout(centralWidget); // Присваиваем члену класса

    // Create horizontal layout for each parameter
    // Теперь все виджеты создаются с new и присваиваются членам класса
    firstLayout = new QHBoxLayout();
    firstLabel = new QLabel("First Term (a_1):");
    firstInput = new QLineEdit();
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstInput);

    differenceLayout = new QHBoxLayout();
    differenceLabel = new QLabel("Common Difference (d):");
    differenceInput = new QLineEdit();
    differenceLayout->addWidget(differenceLabel);
    differenceLayout->addWidget(differenceInput);

    termsLayout = new QHBoxLayout();
    termsLabel = new QLabel("Number of Terms (n):");
    termsInput = new QLineEdit();
    termsLayout->addWidget(termsLabel);
    termsLayout->addWidget(termsInput);

    lastTermLayout = new QHBoxLayout();
    lastTermLabel = new QLabel("Last Term (a_n):");
    lastTermInput = new QLineEdit();
    lastTermLayout->addWidget(lastTermLabel);
    lastTermLayout->addWidget(lastTermInput);

    sumLayout = new QHBoxLayout();
    sumLabel = new QLabel("Sum of Terms (S_n):");
    sumInput = new QLineEdit();
    sumLayout->addWidget(sumLabel);
    sumLayout->addWidget(sumInput);

    // Add horizontal layouts to the main layout
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(differenceLayout);
    mainLayout->addLayout(termsLayout);
    mainLayout->addLayout(lastTermLayout);
    mainLayout->addLayout(sumLayout);

    // Добавляется кнопка
    calculation_trigger_button = new QPushButton("Calculate"); // Создаем с new
    connect(calculation_trigger_button, &QPushButton::clicked, this, &arithmetic_progression::calculation_button_clicked);
    mainLayout->addWidget(calculation_trigger_button);
}

arithmetic_progression::~arithmetic_progression()
{
    // Qt автоматически удалит дочерние виджеты и макеты,
    // поэтому явный delete для них не нужен, если centralWidget
    // установлен как родитель (что делается через `new QWidget(this)`
    // и `new QVBoxLayout(centralWidget)`).
    // delete calculation_trigger_button; // Не нужно, если добавлен в макет
    // ... и т.д.
}



// Define sentinel values for unknown inputs - Перенесено в .h как статические константы
//const float UNKNOWN_FLOAT = std::numeric_limits<float>::quiet_NaN();
//const int   UNKNOWN_INT   = std::numeric_limits<int>::min();

void arithmetic_progression::calculation_button_clicked()
{
    // Read and process each input: if empty, treat as unknown; otherwise, convert.
    float a1 = UNKNOWN_FLOAT;
    float d = UNKNOWN_FLOAT;
    int n = UNKNOWN_INT;
    float an = UNKNOWN_FLOAT;
    float sn = UNKNOWN_FLOAT;
    int known_count = 0;

    // Вспомогательная лямбда для парсинга float
    auto parseFloat = [&](QLineEdit* input, float& value) {
        QString text = input->text().trimmed();
        if (!text.isEmpty()) {
            bool ok = false;
            value = text.toFloat(&ok);
            if (!ok) {
                value = UNKNOWN_FLOAT;
                QMessageBox::warning(this, "Input Error", "Invalid float value in field: " + input->objectName()); // Указываем поле
                return false; // Ошибка парсинга
            } else {
                known_count++;
            }
        }
        return true; // Успех или поле пустое
    };

    // Вспомогательная лямбда для парсинга int
    auto parseInt = [&](QLineEdit* input, int& value) {
        QString text = input->text().trimmed();
        if (!text.isEmpty()) {
            bool ok = false;
            value = text.toInt(&ok);
            if (!ok || value <= 0) { // Номер члена должен быть положительным
                 if (!ok) QMessageBox::warning(this, "Input Error", "Invalid integer value in field: " + input->objectName());
                 else QMessageBox::warning(this, "Input Error", "Number of terms (n) must be positive: " + input->objectName());
                 value = UNKNOWN_INT;
                 return false; // Ошибка парсинга
            }
            else {
                known_count++;
            }
        }
        return true; // Успех или поле пустое
    };

    // Устанавливаем objectName для полей ввода для информативных сообщений об ошибках
    firstInput->setObjectName("First Term (a_1)");
    differenceInput->setObjectName("Common Difference (d)");
    termsInput->setObjectName("Number of Terms (n)");
    lastTermInput->setObjectName("Last Term (a_n)");
    sumInput->setObjectName("Sum of Terms (S_n)");

    if (!parseFloat(firstInput, a1)) return;
    if (!parseFloat(differenceInput, d)) return;
    if (!parseInt(termsInput, n)) return;
    if (!parseFloat(lastTermInput, an)) return;
    if (!parseFloat(sumInput, sn)) return;

    // Проверяем, достаточно ли данных для вычисления (обычно нужно 3)
    if (known_count < 3) {
        QMessageBox::information(this, "Insufficient Data", "Please provide at least three known values to calculate the others.");
        return;
    }

    // Сохраняем копии для проверки, что изменилось
    float a1_orig = a1, d_orig = d, an_orig = an, sn_orig = sn;
    int n_orig = n;

    // Вызываем функцию вычислений
    try {
        calculateArithmeticProgression(a1, d, n, an, sn);
    }
    catch (const std::exception& e) {
         QMessageBox::critical(this, "Calculation Error", QString("Error during calculation: %1").arg(e.what()));
         return;
    }

    // Обновляем поля вывода, если значения были вычислены
    if (isUnknown(a1_orig) && !isUnknown(a1)) firstInput->setText(QString::number(a1, 'g', 10));
    if (isUnknown(d_orig) && !isUnknown(d)) differenceInput->setText(QString::number(d, 'g', 10));
    if (isUnknown(n_orig) && !isUnknown(n)) termsInput->setText(QString::number(n));
    if (isUnknown(an_orig) && !isUnknown(an)) lastTermInput->setText(QString::number(an, 'g', 10));
    if (isUnknown(sn_orig) && !isUnknown(sn)) sumInput->setText(QString::number(sn, 'g', 10));

    // Проверяем, остались ли неизвестные после попытки вычисления
    int unknown_count_after = 0;
    if (isUnknown(a1)) unknown_count_after++;
    if (isUnknown(d)) unknown_count_after++;
    if (isUnknown(n)) unknown_count_after++;
    if (isUnknown(an)) unknown_count_after++;
    if (isUnknown(sn)) unknown_count_after++;

    if (unknown_count_after > 0 && known_count + (5 - unknown_count_after) < 5) {
         // Если не все вычислено и исходных данных было меньше 5
         QMessageBox::warning(this, "Calculation Incomplete", "Could not determine all unknown values with the provided data.");
    } else if (unknown_count_after == 0) {
        QMessageBox::information(this, "Calculation Complete", "All values calculated successfully.");
    }
}


// Helper function to check if a float value represents an unknown input
inline bool arithmetic_progression::isUnknown(float val) {
    return std::isnan(val);
}

// Helper function to check if an int value represents an unknown input
inline bool arithmetic_progression::isUnknown(int val) {
    return val == UNKNOWN_INT;
}

// Функция теперь статический член класса и принимает ссылки
void arithmetic_progression::calculateArithmeticProgression(float &firstTerm, float &step, int &termNumber,float &termValue, float &sumOfTerms)
{
    // --- Начало существующей логики функции calculateArithmeticProgression ---
    // Заменяем qDebug на выброс исключений или возврат кода ошибки,
    // или просто позволяем значениям оставаться UNKNOWN.

    int calculated_count = 0; // Счетчик успешно вычисленных значений за итерацию
    const int MAX_ITERATIONS = 5; // Предотвращение бесконечного цикла
    int iterations = 0;

    do {
        calculated_count = 0;
        iterations++;

        // Case 1: Calculate n if S_n, a_1 and a_n are known
        if (!isUnknown(sumOfTerms) && !isUnknown(firstTerm) && !isUnknown(termValue) && isUnknown(termNumber))
        {
            if (firstTerm + termValue != 0) { // Avoid division by zero
                double n_calc = (2.0 * sumOfTerms) / (firstTerm + termValue);
                if (n_calc > 0 && std::round(n_calc) == n_calc) {
                    termNumber = static_cast<int>(std::round(n_calc));
                    calculated_count++;
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
                } else if (firstTerm != 0 && sumOfTerms / firstTerm > 0 && std::fmod(sumOfTerms, firstTerm) == 0 ) {
                    termNumber = static_cast<int>(sumOfTerms / firstTerm);
                    calculated_count++;
                    qDebug() << "Calculated term number (n) for constant progression: " << termNumber;
                } else {
                    qDebug() << "Error: Cannot determine n for constant progression with given sum.";
                }
            }
            else {
                double b_term = 2 * firstTerm - step;
                double discriminant = b_term * b_term - 4 * step * (-2 * sumOfTerms);

                if (discriminant >= 0)
                {
                    double sqrt_discriminant = std::sqrt(discriminant);
                    double n1 = (-b_term + sqrt_discriminant) / (2 * step);
                    double n2 = (-b_term - sqrt_discriminant) / (2 * step);

                    int valid_n = UNKNOWN_INT;
                    if (n1 > 0 && std::round(n1) == n1) valid_n = static_cast<int>(std::round(n1));
                    // Check n2 only if n1 is not a valid solution
                    if (valid_n == UNKNOWN_INT && n2 > 0 && std::round(n2) == n2) valid_n = static_cast<int>(std::round(n2));
                    // If both are valid positive integers, there might be ambiguity or specific context needed.
                    // For now, we prioritize the first valid one found.
                    // If one is valid and the other is not, use the valid one.
                    if (n1 > 0 && std::round(n1) == n1 && (n2 <= 0 || std::round(n2) != n2)) {
                        valid_n = static_cast<int>(std::round(n1));
                    } else if (n2 > 0 && std::round(n2) == n2 && (n1 <= 0 || std::round(n1) != n1)) {
                         valid_n = static_cast<int>(std::round(n2));
                    } else if (n1 > 0 && std::round(n1) == n1 && n2 > 0 && std::round(n2) == n2) {
                         // Both are valid positive integers. This case might need clarification.
                         // Let's pick the smaller one for now, assuming n represents a count.
                         valid_n = static_cast<int>(std::round(std::min(n1, n2)));
                         qDebug() << "Warning: Two valid positive integer solutions for n found (" << n1 << ", " << n2 << "). Using the smaller one: " << valid_n;
                    }


                    if (valid_n != UNKNOWN_INT) {
                        termNumber = valid_n;
                        calculated_count++;
                        qDebug() << "Calculated term number (n) from S_n, a_1, d: " << termNumber;
                    } else {
                        qDebug() << "Error: Quadratic equation solutions for n are not valid positive integers (" << n1 << ", " << n2 << ").";
                    }
                } else {
                     qDebug() << "Error: Discriminant is negative, no real solutions for term number (n).";
                }
            }
        }

        // Case 3: Calculate d if a_n, a_1 and n are known
        if (!isUnknown(termValue) && !isUnknown(firstTerm) && !isUnknown(termNumber) && isUnknown(step))
        {
            if (termNumber > 1) {
                step = (termValue - firstTerm) / (termNumber - 1);
                calculated_count++;
                 qDebug() << "Calculated step (d) from a_n, a_1, n: " << step;
            } else if (termNumber == 1) {
                if (termValue == firstTerm) {
                     qDebug() << "Cannot determine step (d): Only one term (n=1). Step can be any value.";
                     // step remains UNKNOWN_FLOAT
                } else {
                     qDebug() << "Error: Inconsistent data for n=1. a_n must equal a_1.";
                     // Indicate inconsistency? Or leave step unknown?
                     // throw std::runtime_error("Inconsistent data: a_n != a_1 for n=1");
                }
            } else { // n <= 0, which should have been caught earlier
                 qDebug() << "Error: Invalid term number (n <= 0) for calculating step (d).";
            }
        }

        // Case 4: Calculate a_n if a_1, d and n are known
        if (!isUnknown(firstTerm) && !isUnknown(step) && !isUnknown(termNumber) && isUnknown(termValue))
        {
            if (termNumber >= 1) {
                termValue = firstTerm + (termNumber - 1) * step;
                calculated_count++;
                qDebug() << "Calculated term value (a_n) from a_1, d, n: " << termValue;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating term value (a_n).";
            }
        }

        // Case 5: Calculate a_1 if a_n, d and n are known
        if (!isUnknown(termValue) && !isUnknown(step) && !isUnknown(termNumber) && isUnknown(firstTerm))
        {
             if (termNumber >= 1) {
                 firstTerm = termValue - (termNumber - 1) * step;
                 calculated_count++;
                 qDebug() << "Calculated first term (a_1) from a_n, d, n: " << firstTerm;
            } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating first term (a_1).";
            }
        }

        // Case 6: Calculate S_n if n, a_1 and a_n are known
        if (!isUnknown(termNumber) && !isUnknown(firstTerm) && !isUnknown(termValue) && isUnknown(sumOfTerms))
        {
            if (termNumber >= 1) {
                sumOfTerms = termNumber * (firstTerm + termValue) / 2.0;
                calculated_count++;
                qDebug() << "Calculated sum (S_n) from n, a_1, a_n: " << sumOfTerms;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating sum (S_n).";
            }
        }

        // Case 7: Calculate S_n if n, a_1 and d are known
        if (!isUnknown(termNumber) && !isUnknown(firstTerm) && !isUnknown(step) && isUnknown(sumOfTerms))
        {
            if (termNumber >= 1) {
                sumOfTerms = termNumber / 2.0 * (2 * firstTerm + (termNumber - 1) * step);
                calculated_count++;
                qDebug() << "Calculated sum (S_n) from n, a_1, d: " << sumOfTerms;
            } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating sum (S_n).";
            }
        }

        // --- Дополнительные случаи (выводятся из предыдущих) ---

         // Calculate a_1 if S_n, n, a_n are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(termValue) && isUnknown(firstTerm)) {
            if (termNumber >= 1) {
                firstTerm = (2.0 * sumOfTerms / termNumber) - termValue;
                calculated_count++;
                qDebug() << "Calculated first term (a_1) from S_n, n, a_n: " << firstTerm;
            } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating first term (a_1).";
            }
        }

        // Calculate a_n if S_n, n, a_1 are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(firstTerm) && isUnknown(termValue)) {
             if (termNumber >= 1) {
                termValue = (2.0 * sumOfTerms / termNumber) - firstTerm;
                calculated_count++;
                qDebug() << "Calculated term value (a_n) from S_n, n, a_1: " << termValue;
            } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating term value (a_n).";
            }
        }

        // Calculate a_1 if S_n, n, d are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(step) && isUnknown(firstTerm)) {
             if (termNumber >= 1) {
                // S_n = n/2 * (2a_1 + (n-1)d)
                // 2S_n / n = 2a_1 + (n-1)d
                // 2a_1 = (2S_n / n) - (n-1)d
                // a_1 = (S_n / n) - (n-1)d / 2
                firstTerm = (sumOfTerms / termNumber) - (termNumber - 1) * step / 2.0;
                calculated_count++;
                qDebug() << "Calculated first term (a_1) from S_n, n, d: " << firstTerm;
            } else {
                qDebug() << "Error: Invalid term number (n < 1) for calculating first term (a_1).";
            }
        }

        // Calculate d if S_n, n, a_1 are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(firstTerm) && isUnknown(step)) {
             if (termNumber > 1) {
                // 2a_1 = (2S_n / n) - (n-1)d
                // (n-1)d = (2S_n / n) - 2a_1
                // d = ((2S_n / n) - 2a_1) / (n-1)
                 step = ((2.0 * sumOfTerms / termNumber) - 2.0 * firstTerm) / (termNumber - 1);
                 calculated_count++;
                 qDebug() << "Calculated step (d) from S_n, n, a_1: " << step;
             } else if (termNumber == 1) {
                 if (sumOfTerms == firstTerm) {
                     qDebug() << "Cannot determine step (d): Only one term (n=1).";
                 } else {
                     qDebug() << "Error: Inconsistent data for n=1. S_n must equal a_1.";
                     // throw std::runtime_error("Inconsistent data: S_n != a_1 for n=1");
                 }
             } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating step (d).";
            }
        }

        // Calculate d if S_n, n, a_n are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(termValue) && isUnknown(step)) {
             if (termNumber > 1) {
                 // a_n = a_1 + (n-1)d => a_1 = a_n - (n-1)d
                 // S_n = n/2 * (a_1 + a_n)
                 // S_n = n/2 * (a_n - (n-1)d + a_n)
                 // S_n = n/2 * (2a_n - (n-1)d)
                 // 2S_n / n = 2a_n - (n-1)d
                 // (n-1)d = 2a_n - 2S_n / n
                 // d = (2a_n - 2S_n/n) / (n-1)
                 step = (2.0 * termValue - 2.0 * sumOfTerms / termNumber) / (termNumber - 1);
                 calculated_count++;
                 qDebug() << "Calculated step (d) from S_n, n, a_n: " << step;
            } else if (termNumber == 1) {
                 if (sumOfTerms == termValue) {
                      qDebug() << "Cannot determine step (d): Only one term (n=1).";
                 } else {
                      qDebug() << "Error: Inconsistent data for n=1. S_n must equal a_n.";
                     // throw std::runtime_error("Inconsistent data: S_n != a_n for n=1");
                 }
             } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating step (d).";
            }
        }

         // Calculate a_n if S_n, n, d are known
        if (!isUnknown(sumOfTerms) && !isUnknown(termNumber) && !isUnknown(step) && isUnknown(termValue)) {
             if (termNumber >= 1) {
                 // (n-1)d = 2a_n - 2S_n / n
                 // 2a_n = (n-1)d + 2S_n / n
                 // a_n = (n-1)d/2 + S_n/n
                 termValue = (termNumber - 1) * step / 2.0 + sumOfTerms / termNumber;
                 calculated_count++;
                 qDebug() << "Calculated term value (a_n) from S_n, n, d: " << termValue;
             } else {
                 qDebug() << "Error: Invalid term number (n < 1) for calculating term value (a_n).";
            }
        }

    // Проверяем, были ли сделаны вычисления и не превышен ли лимит итераций
    } while (calculated_count > 0 && iterations < MAX_ITERATIONS);

     if (iterations >= MAX_ITERATIONS) {
         qDebug() << "Warning: Calculation stopped after maximum iterations.";
     }

}

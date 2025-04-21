//
// Created by kleymuner2131 on 21.04.25.
//

#ifndef GEOMETRIC_PROGRESSION_H
#define GEOMETRIC_PROGRESSION_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

class geometric_progression : public QMainWindow {
    QOBJECT_H

public:
    explicit geometric_progression(QWidget *parent = nullptr);
    ~geometric_progression();

    const float UNKNOWN_FLOAT = std::numeric_limits<float>::quiet_NaN();
    const int   UNKNOWN_INT   = std::numeric_limits<int>::quiet_NaN();

private slots:
    void calculation_button_clicked();
    void calculate(float &firstTerm, float &difference, int &termNumber, float &lastTerm, float& sum);

private:
    QWidget *centralWidget;
    // UI elements
    QVBoxLayout *mainLayout;
    QHBoxLayout *firstLayout;
    QLabel *firstLabel;
    QLineEdit *firstInput;

    QHBoxLayout *differenceLayout;
    QLabel *differenceLabel;
    QLineEdit *differenceInput;

    QHBoxLayout *termsLayout;
    QLabel *termsLabel;
    QLineEdit *termsInput;

    QHBoxLayout *lastTermLayout;
    QLabel *lastTermLabel;
    QLineEdit *lastTermInput;

    QHBoxLayout *sumLayout;
    QLabel *sumLabel;
    QLineEdit *sumInput;

    QPushButton *calculationButton;
};



#endif //GEOMETRIC_PROGRESSION_H

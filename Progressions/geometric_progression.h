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
#include <QVBoxLayout>
#include <limits>
#include <cmath>

class geometric_progression : public QMainWindow {
    Q_OBJECT

public:
    explicit geometric_progression(QWidget *parent = nullptr);
    ~geometric_progression();

    const float UNKNOWN_FLOAT = std::numeric_limits<float>::quiet_NaN();
    const int   UNKNOWN_INT   = std::numeric_limits<int>::min();

private slots:
    void calculation_button_clicked();
    void calculate(float &firstTerm, float &ratio, int &termNumber, float &lastTerm, float& sum);

private:
    // Helper methods
    inline bool isUnknown(float val) { return std::isnan(val); }
    inline bool isUnknown(int val) { return val == UNKNOWN_INT; }

    QWidget *centralWidget;
    // UI elements
    QVBoxLayout *mainLayout;
    QHBoxLayout *firstLayout;
    QLabel *firstLabel;
    QLineEdit *firstInput;

    QHBoxLayout *ratioLayout;
    QLabel *ratioLabel;
    QLineEdit *ratioInput;

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


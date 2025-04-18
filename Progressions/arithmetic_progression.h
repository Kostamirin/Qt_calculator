// Created by kleymuner2131 on 14.04.25.
#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <QMainWindow>
#include <QDebug>
#include <limits>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
QT_END_NAMESPACE

class arithmetic_progression : public QMainWindow {
    Q_OBJECT

public:
    explicit arithmetic_progression(QWidget *parent = nullptr);
    ~arithmetic_progression();

private slots:
    void calculation_button_clicked();

private:
    static inline bool isUnknown(float val);
    static inline bool isUnknown(int val);

    static void calculateArithmeticProgression(float &firstTerm, float &step, int &termNumber, float &termValue, float &sumOfTerms);

    static const float UNKNOWN_FLOAT;
    static const int   UNKNOWN_INT;

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    QLineEdit *firstInput;
    QLineEdit *differenceInput;
    QLineEdit *termsInput;
    QLineEdit *lastTermInput;
    QLineEdit *sumInput;

    QLabel *firstLabel;
    QLabel *differenceLabel;
    QLabel *termsLabel;
    QLabel *lastTermLabel;
    QLabel *sumLabel;

    QPushButton *calculation_trigger_button;

    QHBoxLayout *firstLayout;
    QHBoxLayout *differenceLayout;
    QHBoxLayout *termsLayout;
    QHBoxLayout *lastTermLayout;
    QHBoxLayout *sumLayout;
};

#endif // ARITHMETIC_PROGRESSION_H

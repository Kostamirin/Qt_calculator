#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void handleArithmeticProgression();
    void handleGeometricProgression();
    void handleHelp();
    // Exit is handled by QDialog's accept/reject or close

private:
    // Ui::SecondWindow *ui; // If using Qt Designer
    // Add button members if not using Qt Designer
};

#endif // SECONDWINDOW_H

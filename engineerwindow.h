#ifndef ENGINEERWINDOW_H
#define ENGINEERWINDOW_H

#include <QWidget>

namespace Ui {
class engineerwindow;
}

class engineerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit engineerwindow(QWidget *parent = nullptr);
    ~engineerwindow();

private:
    Ui::engineerwindow *ui;
};

#endif // ENGINEERWINDOW_H

#ifndef STUDENTMS_H
#define STUDENTMS_H

#include <QMainWindow>

namespace Ui {
class StudentMS;
}

class StudentMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMS(QWidget *parent = nullptr);
    ~StudentMS();

private:
    Ui::StudentMS *ui;
};

#endif // STUDENTMS_H

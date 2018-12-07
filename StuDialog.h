#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>
#include <QVector>

namespace Ui {
class StuDialog;
}

class StuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuDialog(QWidget *parent = nullptr);
    ~StuDialog();
    QString getID();
    QVector<QString> getInput();


private:
    Ui::StuDialog *ui;

};

#endif // STUDIALOG_H

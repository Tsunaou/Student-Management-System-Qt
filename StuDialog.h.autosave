#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>
#include <QVector>
#include <QDate>
#include "StuInfoTemplate.h"

#include <iostream>
using namespace  std;

namespace Ui {
class StuDialog;
}

//学生信息输入和修改的对话框
class StuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuDialog(QWidget *parent = nullptr);
    ~StuDialog();
    StuInfoTemplate& getStuInfo();          //
    QVector<QString> getInput();            //
    void setByStuInfo(StuInfoTemplate info);//


private:
    Ui::StuDialog *ui;
    StuInfoTemplate stuInfo;
};

#endif // STUDIALOG_H

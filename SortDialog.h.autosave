#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class SortDialog;
}

//用户排序的对话框
class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    ~SortDialog();
    int getSortTarget();    //得到排序的对象
    int getSortOrder();     //得到排序的方式（升序/降序）

private:
    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H

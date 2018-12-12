#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

namespace Ui {
class FilterDialog;
}

//用户筛选的对话框
class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();
    QString getKey();       //得到查询的关键字
    QString getTarget();    //得到查询的目标
    int getTargetIndex();   //得到查询目标的序号（可以映射到表格）
    QString getType();      //得到查询的模式
    bool isRegex();         //是否正则匹配
    bool isWild();          //是否使用通配符
    bool isCaseSensitive(); //是否大小写敏感

private:
    Ui::FilterDialog *ui;
};

#endif // FILTERDIALOG_H

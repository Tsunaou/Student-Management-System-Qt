#ifndef STUSUBWINDOW_H
#define STUSUBWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QDebug>

#include "StuDialog.h"

namespace Ui {
class StuSubWindow;
}

class StuSubWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StuSubWindow(QWidget *parent = nullptr);
    ~StuSubWindow();
    void addLine();                             //增加一行数据
    void alterLine();                           //修改一行数据
    void deleteLine();                          //删除一行数据
    StuInfoTemplate getTableForRow(int row);    //得到表格某一行的数据

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::StuSubWindow *ui;
    QTableWidget* tb;       //当前窗口的表格
    QList<StuInfoTemplate> tableLines;  //原计划存储表格

};

#endif // STUSUBWINDOW_H

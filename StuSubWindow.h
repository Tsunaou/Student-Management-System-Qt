#ifndef STUSUBWINDOW_H
#define STUSUBWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QDebug>
#include <QFileDialog>
#include <QCloseEvent>

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
    void addLine();     //增加一行数据
    void alterLine();   //修改一行数据
    void deleteLine();  //删除一行数据
    void sortByID();    //按照ID排序
    void sortByName();  //按照姓名排序
    void closeFile();   //关闭文件
    void saveFile();    //保存
    void saveFileAs();  //另存为
    void importFile(QString fileName);    //导入文件内容

    StuInfoTemplate getTableForRow(int row);    //得到表格某一行的数据

     void closeEvent(QCloseEvent *event);


private slots:
     void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::StuSubWindow *ui;
    QTableWidget* tb;       //当前窗口的表格
    QString filePath;       //文件路径
    bool flagModified;      //是否被修改过

    //QList<StuInfoTemplate> tableLines;  //原计划存储表格，目前来看貌似没什么用


};

#endif // STUSUBWINDOW_H

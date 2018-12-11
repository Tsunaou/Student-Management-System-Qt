#ifndef STUDENTMS_H
#define STUDENTMS_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QVector>
#include <QMap>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QLabel>
#include <QTimer>

#include "StuSubWindow.h"
#include "StuDialog.h"
#include "LoginDialog.h"

namespace Ui {
class StudentMS;
}

class StudentMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMS(QWidget *parent = nullptr);
    ~StudentMS();
    int getActiveTalbeIndex();
    void showLoginBox();
    void timeUpdate();

protected:
     void closeEvent(QCloseEvent *event);

private slots:
    //文件
    void on_actionNew_triggered();      //新建窗口
    void on_actionClose_triggered();    //关闭当前窗口
    void on_actionSave_triggered();     //保存当前窗口内容
    void on_actionSaveAs_triggered();
    void on_actionOpen_triggered();     //打开一条记录

    //编辑
    void on_actionAdd_triggered();      //增加一条记录
    void on_actionAlter_triggered();    //修改一条记录
    void on_actionDelete_triggered();   //删除一条记录
    void on_actionSortID_triggered();   //按照ID排序
    void on_actionSortName_triggered(); //按照姓名排序
    void on_actionSort_triggered();     //广义上的排序
    void on_actionFilter_triggered();   //筛选表格数据


    //窗口
    void on_actionTabBar_triggered();
    void on_actionWindow_triggered();
    void on_actionTileSubWindows_triggered();
    void on_actionSascadeSubWindows_triggered();

    //相关
    void on_actionAbout_triggered();    //相关信息





    void on_actionToolbar_toggled(bool arg1);

    void on_actionStatus_toggled(bool arg1);

private:
    Ui::StudentMS *ui;
    QVector<StuSubWindow*> subWnds;
    QMap<QMdiSubWindow*,int> WindMap;   //存储当前活动的窗口
    QMap<QString,int> OpenMap;          //存储当前打开的文件(后期扩展可以防止打开同一个窗口)
    int tableIndex;
    QLabel* currentTimeLabel;

};

#endif // STUDENTMS_H

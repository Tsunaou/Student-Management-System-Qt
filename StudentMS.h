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
#include "StyleSelector.h"

namespace Ui {
class StudentMS;
}

//程序的主体
class StudentMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMS(QWidget *parent = nullptr);
    ~StudentMS();
    int getActiveTalbeIndex();  //得到当前活跃窗口的序号
    bool showLoginBox();        //展示登录框
    void timeUpdate();          //时间更新（实际上没用）

protected:
     void closeEvent(QCloseEvent *event);   //自定义关闭事件，提示保存

private slots:
    //文件
    void on_actionNew_triggered();      //新建窗口
    void on_actionClose_triggered();    //关闭当前窗口
    void on_actionSave_triggered();     //保存当前窗口内容
    void on_actionSaveAs_triggered();   //文件另存为
    void on_actionOpen_triggered();     //打开一条记录
    void on_actionPrint_triggered();    //打印（因为没有打印机，所以没有实现）


    //编辑
    void on_actionAdd_triggered();      //增加一条记录
    void on_actionAlter_triggered();    //修改一条记录
    void on_actionDelete_triggered();   //删除一条记录
    void on_actionSortID_triggered();   //按照ID排序
    void on_actionSortName_triggered(); //按照姓名排序
    void on_actionSort_triggered();     //广义上的排序
    void on_actionFilter_triggered();   //筛选表格数据

    //查看
    void on_actionToolbar_toggled(bool arg1);   //查看工具栏
    void on_actionStatus_toggled(bool arg1);    //查看状态栏


    //窗口
    void on_actionTabBar_triggered();           //窗口标签模式
    void on_actionWindow_triggered();           //窗口窗口模式
    void on_actionTileSubWindows_triggered();   //窗口紧密堆叠
    void on_actionSascadeSubWindows_triggered();//窗口整齐排列

    //相关
    void on_actionAbout_triggered();    //相关信息

    //皮肤
    void on_actionOriginQss_triggered();    //原始样式
    void on_actionQssBlue_triggered();      //蓝色样式

private:
    Ui::StudentMS *ui;
    QVector<StuSubWindow*> subWnds;     //维护子窗口
    QMap<QMdiSubWindow*,int> WindMap;   //存储当前活动的窗口
    QMap<QString,int> OpenMap;          //存储当前打开的文件(后期扩展可以防止打开同一个窗口)
    int tableIndex;                     //子窗口的数目
    QLabel* currentTimeLabel;           //时间戳（没用到）

};

#endif // STUDENTMS_H

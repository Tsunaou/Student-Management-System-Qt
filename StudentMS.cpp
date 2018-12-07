#include "StudentMS.h"
#include "ui_StudentMS.h"

#include <QTableWidget>
#include <QMdiSubWindow>


StudentMS::StudentMS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMS)
{
    ui->setupUi(this);
    setWindowTitle(tr("学生信息管理系统"));


    //setCentralWidget(ui->mdiArea);
//    ui->mdiArea->setViewMode(QMdiArea::TabbedView); //设置视口模式：tabBar模式
    ui->mdiArea->setTabPosition(QTabWidget::North); //设置tabBar的位置
    ui->mdiArea->setTabShape(QTabWidget::Rounded); //设置tab形状
    ui->mdiArea->setTabsClosable(true); //tab可关闭
    ui->mdiArea->setTabsMovable(true); //tab可在tabBar拖动

    this->tableIndex = -1;

}

StudentMS::~StudentMS()
{
    delete ui;
}

int StudentMS::getActiveTalbeIndex()
{
    if(this->ui->mdiArea->activeSubWindow()==nullptr){
        return -1;
    }
    int i = this->WindMap.find(this->ui->mdiArea->activeSubWindow()).value();
    qDebug()<<"This index is"<<i<<endl;
    return i;
}

void StudentMS::on_actionNew_triggered()
{
    StuSubWindow *newWnd = new StuSubWindow();
    subWnds.push_back(newWnd);

    QMdiSubWindow *child = ui->mdiArea->addSubWindow(newWnd);
    tableIndex++;
    WindMap.insert(child,tableIndex);

    child->setWindowTitle(tr("学生信息%1").arg(tableIndex));
    child->resize(700,700);
    child->show();
}

void StudentMS::on_actionAdd_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->addLine();
}

void StudentMS::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("关于 StudentMS"),
            tr("<p>"
               "<b>StudentMS</b>是是一个管理程序，是南京大学计算机科学与技术系《高级程序设计》课程的大作业"
               "该程序使用C++和Qt框架开发，可以对学生的信息管理<br/>"
               "程序还处于迭代中，欢迎使用。<br/>"
               "有任何疑问可以发送邮件<a href=\"mailto:895254752@qq.com\">895254752@qq.com</a><br/>"
//               "更多详情，可以到我的github pages上查看<a href=\"https://tsunaou.github.io/GraphicsYoung.html\" target=\"_blank\"><b>Tsuna的个人主页</b></a>"
               "<hr/>"
               "<p style=\"text-align: right\">欧阳鸿荣 2018.12</p></p>"
              ));
}

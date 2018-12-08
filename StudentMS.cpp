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


    ui->mdiArea->setViewMode(QMdiArea::TabbedView); //设置视口模式：tabBar模式
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

void StudentMS::closeEvent(QCloseEvent *event)
{
    //自定义关闭事件，询问是否关闭
    foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList()){
        if(window->isActiveWindow()){
            int i = this->WindMap.find(window).value();
            subWnds[i]->closeEvent(event);
        }
    }
}

void StudentMS::on_actionNew_triggered()
{
    StuSubWindow *newWnd = new StuSubWindow();    subWnds.push_back(newWnd);

    QMdiSubWindow *child = ui->mdiArea->addSubWindow(newWnd);
    tableIndex++;
    WindMap.insert(child,tableIndex);


    //坑爹，这两个的名字不一样
    newWnd->resize(700,700);
    newWnd->setWindowTitle(tr("学生信息表%1").arg(tableIndex+1));

    child->setWindowTitle(tr("学生信息表%1").arg(tableIndex+1));
    child->resize(700,700);
    child->show();
}

void StudentMS::on_actionAdd_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
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

void StudentMS::on_actionAlter_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->alterLine();
}

void StudentMS::on_actionDelete_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->deleteLine();
}

void StudentMS::on_actionSortID_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->sortByID();
}

void StudentMS::on_actionSortName_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->sortByName();
}

void StudentMS::on_actionClose_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->close();
}

void StudentMS::on_actionSave_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->saveFile();
}


void StudentMS::on_actionSaveAs_triggered()
{
    int activeIndex = this->getActiveTalbeIndex();
    if(activeIndex == -1){
        QMessageBox::warning(this,tr("提示"),
                 tr("您当前未创建(或打开)文件，请先创建一个文件。"));
        return;
    }
    subWnds[activeIndex]->saveFileAs();
}


void StudentMS::on_actionOpen_triggered()
{
    //open：得到文件路径，文件名，以这个文件名创建窗口，然后导入文件内容
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),QDir::currentPath(),tr("Text File (*.txt)"));

    if(fileName == ""){//如果用户直接关闭了文件浏览对话框，那么文件名就为空值，直接返回
        return;
    }
    else{
       QFile file(fileName);
       if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
           return;
       }
       else
       {
           if(!file.isReadable())
           {
               QMessageBox::warning(this,tr("错误"),tr("该文件不可读"));
           }
           else
           {
               //该文件可以成功打开
               this->on_actionNew_triggered();
               int activeIndex = this->getActiveTalbeIndex();
               if(activeIndex == -1){
                   QMessageBox::warning(this,tr("提示"),
                            tr("您当前未创建(或打开)文件，请先创建一个文件。"));
                   return;
               }
               QFileInfo fi = QFileInfo(fileName);
               QStringList sections = fi.fileName().split(QRegExp("[.]")); //分割birthday
               this->ui->mdiArea->activeSubWindow()->setWindowTitle(sections.at(0));
               subWnds[activeIndex]->setWindowTitle(fi.fileName());
               subWnds[activeIndex]->importFile(fileName);

           }
           file.close();
       }
    }
}



void StudentMS::on_actionTabBar_triggered()
{
    ui->mdiArea->setViewMode(QMdiArea::TabbedView); //设置视口模式：tabBar模式
}

void StudentMS::on_actionWindow_triggered()
{
    ui->mdiArea->setViewMode(QMdiArea::SubWindowView); //设置视口模式：tabBar模式
}

void StudentMS::on_actionSascadeSubWindows_triggered()
{
    ui->mdiArea-> cascadeSubWindows();
}

void StudentMS::on_actionTileSubWindows_triggered()
{
    ui->mdiArea->tileSubWindows();
}


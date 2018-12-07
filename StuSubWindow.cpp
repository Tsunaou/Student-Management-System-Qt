#include "StuSubWindow.h"
#include "ui_StuSubWindow.h"

StuSubWindow::StuSubWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuSubWindow)
{
    ui->setupUi(this);
    tb = ui->tableWidget;
}

StuSubWindow::~StuSubWindow()
{
    delete ui;
}

void StuSubWindow::addLine()
{
    StuDialog *dialog = new StuDialog();
     QString idGet;
     if(dialog->exec() == QDialog::Accepted)
     {
         QVector<QString> res = dialog->getInput();
         idGet = dialog->getID();
         //qDebug()<< idGet <<endl;
         int row_count = tb->rowCount(); //获取表单行数
          tb->insertRow(row_count); //插入新行
          for(int i=0;i<=5;i++){
              QTableWidgetItem *newItem = new QTableWidgetItem();
              newItem->setText(res[i]);
              tb->setItem(row_count,i,newItem);
          }
     }
}

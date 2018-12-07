#include "SubWindow.h"

SubWindow::SubWindow()
{
    this->tb = new QTableWidget(this); //创建一个表格
    tb->setColumnCount(6);  //设置列数
    tb->setHorizontalHeaderLabels(QStringList()<<"学号"<<"姓名"<<"性别"<<"出生日期"<<"籍贯"<<"住址"); //设置行头
    tb->resize(1200,1200);  //初始大小
}

void SubWindow::addNewItem()
{
    StuDialog *dialog = new StuDialog();
    QString idGet;
    if(dialog->exec() == QDialog::Accepted)
    {
        QVector<QString> res = dialog->getInput();
        idGet = dialog->getID();
        qDebug()<< idGet <<endl;
        int row_count = tb->rowCount(); //获取表单行数
         tb->insertRow(row_count); //插入新行
         for(int i=0;i<=5;i++){
             QTableWidgetItem *newItem = new QTableWidgetItem();
             newItem->setText(res[i]);
             tb->setItem(row_count,i,newItem);
         }
    }





}

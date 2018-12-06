#include "SubWindow.h"

SubWindow::SubWindow()
{
    this->tb = new QTableWidget(this); //创建一个表格
//    tb->setRowCount(3);    //设置行数
    tb->setColumnCount(6); //设置列数
    tb->setHorizontalHeaderLabels(QStringList()<<"学号"<<"姓名"<<"性别"<<"出生日期"<<"籍贯"<<"住址"); //设置行头
//    tb->setItem(0,0,new QTableWidgetItem("161220096")); //设置表格内容
    tb->resize(1200,1200);
}

void SubWindow::addNewItem()
{
    int row_count = tb->rowCount(); //获取表单行数
     tb->insertRow(row_count); //插入新行
     QTableWidgetItem *id = new QTableWidgetItem();
     QTableWidgetItem *name = new QTableWidgetItem();
     QTableWidgetItem *sex = new QTableWidgetItem();
     QTableWidgetItem *birthday = new QTableWidgetItem();
     QTableWidgetItem *hometown = new QTableWidgetItem();
     QTableWidgetItem *address = new QTableWidgetItem();
     id->setText("161220096");
     name->setText("欧阳鸿荣");
     sex->setText("男");
     birthday->setText("1997-11-21");
     hometown->setText("福建晋江");
     address->setText("南京大学栖霞区仙林大道");
     tb->setItem(row_count, 0, id);
     tb->setItem(row_count, 1, name);
     tb->setItem(row_count, 2, sex);
     tb->setItem(row_count, 3, birthday);
     tb->setItem(row_count, 4, hometown);
     tb->setItem(row_count, 5, address);



}

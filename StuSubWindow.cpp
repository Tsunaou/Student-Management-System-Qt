#include "StuSubWindow.h"
#include "ui_StuSubWindow.h"

StuSubWindow::StuSubWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuSubWindow)
{
    ui->setupUi(this);
    tb = ui->tableWidget;
    //对表格的一些特性进行处理
    tb->setSelectionBehavior(QAbstractItemView::SelectRows);    //整行选中的方式
    tb->setSelectionMode (QAbstractItemView::SingleSelection);  //选择单行（防止一次性编辑多行）
    tb->setEditTriggers(QAbstractItemView::NoEditTriggers);     //禁止直接对单元格修改

    connect(tb,SIGNAL(on_tableWidget_cellDoubleClicked(int,int)),this,SLOT(on_tableWidget_cellDoubleClicked(int,int)));

}

StuSubWindow::~StuSubWindow()
{
    delete ui;
}

void StuSubWindow::addLine()
{
    StuDialog *dialog = new StuDialog();
    if(dialog->exec() == QDialog::Accepted)
    {
        QVector<QString> res = dialog->getInput();
        int row_count = tb->rowCount(); //获取表单行数
         tb->insertRow(row_count); //插入新行
         for(int i=0;i<=5;i++){
             QTableWidgetItem *newItem = new QTableWidgetItem();
             newItem->setText(res[i]);
             tb->setItem(row_count,i,newItem);
         }
    }
}

StuInfoTemplate StuSubWindow::getTableForRow(int row)
{
    return StuInfoTemplate(tb->item(row,0)->text(), //学号
                           tb->item(row,1)->text(), //姓名
                           tb->item(row,2)->text(), //性别
                           tb->item(row,3)->text(), //出生日期
                           tb->item(row,4)->text(), //籍贯
                           tb->item(row,5)->text());//住址
}

void StuSubWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    StuInfoTemplate info = getTableForRow(row);
    info.showStuInfo();
    StuDialog *dialog = new StuDialog();
    dialog->setByStuInfo(info);
    if(dialog->exec() == QDialog::Accepted)
    {
        QVector<QString> res = dialog->getInput();
        for(int i=0;i<=5;i++){
           tb->item(row,i)->setText(res[i]);
        }
    }

}

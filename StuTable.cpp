#include "StuTable.h"
#include "ui_stutable.h"

StuTable::StuTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuTable)
{
    ui->setupUi(this);
    this->tb = ui->tableWidget;
}

StuTable::~StuTable()
{
    delete ui;
}

void StuTable::addItem()
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

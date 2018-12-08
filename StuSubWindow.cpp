#include "StuSubWindow.h"
#include "ui_StuSubWindow.h"

StuSubWindow::StuSubWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuSubWindow)
{
    ui->setupUi(this);
    //成员变量初始化
    tb = ui->tableWidget;
    filePath = "";

    //对表格的一些特性进行处理
    tb->setSelectionBehavior(QAbstractItemView::SelectRows);    //整行选中的方式
    tb->setSelectionMode (QAbstractItemView::SingleSelection);  //选择单行（防止一次性编辑多行）
    tb->setEditTriggers(QAbstractItemView::NoEditTriggers);     //禁止直接对单元格修改

    //绑定双击事件的信号到处理函数（双击即可改变值）
    connect(tb,SIGNAL(on_tableWidget_cellDoubleClicked(int,int)),this,SLOT(on_tableWidget_cellDoubleClicked(int,int)));

//    //对表头进行设置
//    QTableWidgetItem *columnHeaderItem0 = tb->horizontalHeaderItem(0); //获得水平方向表头的Item对象
//    columnHeaderItem0->setFont(QFont("Helvetica")); //设置字体
//    columnHeaderItem0->setBackgroundColor(QColor(0,60,10)); //设置单元格背景颜色
//    columnHeaderItem0->setTextColor(QColor(200,111,30)); //设置文字颜色

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

void StuSubWindow::alterLine()
{
    int rowCur = tb->currentRow();
    on_tableWidget_cellDoubleClicked(rowCur,0);
}

void StuSubWindow::deleteLine()
{
    int rowCur = tb->currentRow();
    tb->removeRow(rowCur);
}

void StuSubWindow::sortByID()
{
    tb->sortItems(0);
}

void StuSubWindow::sortByName()
{
    tb->sortItems(1);
}

void StuSubWindow::saveFile()
{

}

void StuSubWindow::importFile(QString fileName)
{
    this->filePath = fileName;
    QFileInfo fi = QFileInfo(fileName);
    qDebug()<<fi.fileName()<<endl;
    this->setWindowTitle(fi.fileName());
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
            //该文件可以成功打开，于是将信息导入到
            QTextStream textStream(&file);
            QString lineInfo;
            while(!textStream.atEnd())
            {
                lineInfo = textStream.readLine();
                QStringList newLine = lineInfo.split(QRegExp("[ ]"));
                int row_count = tb->rowCount(); //获取表单行数
                tb->insertRow(row_count); //插入新行
                for(int i=0;i<=5;i++){
                    QTableWidgetItem *newItem = new QTableWidgetItem();
                    newItem->setText(newLine.at(i));
                    tb->setItem(row_count,i,newItem);
                }
            }
        }
        file.close();
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

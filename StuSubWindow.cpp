#include "StuSubWindow.h"
#include "ui_StuSubWindow.h"

StuSubWindow::StuSubWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuSubWindow)
{
    ui->setupUi(this);
    //成员变量初始化
    this->tb = ui->tableWidget; //指向窗口中的表格
    this->filePath = "";        //文件路径
    this->fileTitle = "";       //文件名
    this->flagModified = true;  //是否被修改过了

    //对表格的一些特性进行处理
    tb->setSelectionBehavior(QAbstractItemView::SelectRows);    //整行选中的方式
    tb->setSelectionMode (QAbstractItemView::SingleSelection);  //选择单行（防止一次性编辑多行）
    tb->setEditTriggers(QAbstractItemView::NoEditTriggers);     //禁止直接对单元格修改

    //绑定双击事件的信号到处理函数（双击即可改变值）
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
    //保存，是已经打开的，或者保存过的文件保存
    if(filePath == ""){
        this->saveFileAs();
        //QMessageBox::information(this,tr("新文件"),tr("新文件用另存为处理"));
    }else{
        //就把表格里的内容都存到filePath里就好
        this->saveTableTo(filePath);
    }
}

void StuSubWindow::saveFileAs()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Open File"),"/新表格",tr("Text File(*.txt)"));

    if(fileName == ""){
        return;
    }
    else{
        QString simpleName = this->getFileNameWithoutFormat(fileName);
        this->setWindowTitle(simpleName);   //“另存为”成功后，将窗口改名
        this->filePath = fileName;
        this->saveTableTo(fileName);
    }
}

void StuSubWindow::saveTableTo(QString filepath)
{
    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("警告"),tr("打开文件失败"));
        return;
    }
    else
    {
        QTextStream textStream(&file);
        for(int i=0; i <ui->tableWidget->rowCount(); i++)
        {
            for(int j=0; j<=5;j++){
                textStream << ui->tableWidget->item(i,j)->text()<<" ";
            }
            textStream<<endl;
        }
        QMessageBox::information(this,tr("提示"),tr("保存成功"));
        file.close();
    }
}

void StuSubWindow::importFile(QString fileName)
{
    this->filePath = fileName;
    QFileInfo fi = QFileInfo(fileName);
    qDebug()<<fi.fileName()<<endl;
    this->windowTitleChanged(fi.fileName());
//    this->setWindowTitle(fi.fileName());
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

QString StuSubWindow::getFileNameWithoutFormat(QString filename)
{
    QFileInfo fi(filename);
    QStringList simpleName = fi.fileName().split(QRegExp("[.]"));
    return simpleName.at(0);

}

void StuSubWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    QString name = this->windowTitle();
    button=QMessageBox::question(this,tr("退出程序"),QString(name+tr("尚未保存，是否保存")),QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(button==QMessageBox::No)
    {
        event->ignore(); // 忽略退出信号，程序继续进行
    }
    else if(button==QMessageBox::Yes)
    {
        event->accept(); // 接受退出信号，程序退出
    }
    else if(button==QMessageBox::Cancel)
    {
        event->ignore(); // 忽略退出信号，程序继续进行
    }
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


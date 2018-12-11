#ifndef STUSUBWINDOW_H
#define STUSUBWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QDebug>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextCodec>
//#include <QtPrintSupport/QPrinter>
//#include <QtPrintSupport/QPrintDialog>
//#include <QPainter>

#include "StuDialog.h"
#include "config.h"
#include "FilterDialog.h"
#include "SortDialog.h"

namespace Ui {
class StuSubWindow;
}

class StuSubWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StuSubWindow(QWidget *parent = nullptr);
    ~StuSubWindow();
    void addLine();     //增加一行数据
    void alterLine();   //修改一行数据
    void deleteLine();  //删除一行数据
    void sortByID();    //按照ID排序
    void sortByName();  //按照姓名排序
    void closeFile();   //关闭文件
    bool saveFile();    //保存
    bool saveFileAs();  //另存为
    bool saveTableTo(QString filepath);     //将文件保存到filepath上
    void importFile(QString fileName);      //导入文件内容
    void closeEvent(QCloseEvent *event);    //捕捉关闭事件
    void sortByUser();   //自定义排序
    void filter();                          //自定义筛选
    void printTable();  //打印表格
    //数据辅助处理函数
    StuInfoTemplate getTableForRow(int row);    //得到表格某一行的数据
    QString getFileNameWithoutFormat(QString filename); //得到某个路径下的文件名（不含格式）
    bool primaryKeyConfilct(QString ID,int before);    //每个学生学号唯一（实际上就是主键），不可重复
    QString getFilePath() const;            //得到文件路径
    bool QString_Matches(const QString& str,const QString& pattern,const Qt::MatchFlags& flags);    //看是否存在匹配的字符串

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);    //双击事件

private:
    Ui::StuSubWindow *ui;
    QTableWidget* tb;           //当前窗口的表格
    FilterDialog *stuFilter;    //当前的筛选器
    SortDialog *stuSorter;      //当前的排序器
    QString filePath;           //文件路径
    bool flagModified;          //是否被修改过
    //QPrinter *printer;
};

#endif // STUSUBWINDOW_H

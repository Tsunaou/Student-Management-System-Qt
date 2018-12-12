#ifndef STUINFOTEMPLATE_H
#define STUINFOTEMPLATE_H
#include "QString"
#include "QDebug"

//学生信息的模版
class StuInfoTemplate
{
public:
    StuInfoTemplate();
    StuInfoTemplate(QString ID,QString name,QString sex,QString birth,QString home,QString add);

    void showStuInfo();                     //打印信息
    void setID(const QString &value);       //设置学号
    void setName(const QString &value);     //设置姓名
    void setSex(const QString &value);      //设置性别
    void setBirthday(const QString &value); //设置出生日期
    void setHometown(const QString &value); //设置籍贯
    void setAddress(const QString &value);  //设置住址

    QString getID() const;      //得到学号
    QString getName() const;    //得到姓名
    QString getSex() const;     //得到性别
    QString getBirthday() const;//得到出生日期
    QString getHometown() const;//得到籍贯
    QString getAddress() const; //得到住址

private:
    QString ID;         //学号
    QString name;       //姓名
    QString sex;        //性别
    QString birthday;   //出生日期
    QString hometown;   //籍贯
    QString address;    //住址
};

#endif // STUINFOTEMPLATE_H

#include "StuInfoTemplate.h"

StuInfoTemplate::StuInfoTemplate()
{
    this->ID = "";
    this->name = "";
    this->sex = "";
    this->birthday = "";
    this->hometown = "";
    this->address = "";
}

StuInfoTemplate::StuInfoTemplate(QString ID, QString name, QString sex, QString birth, QString home, QString add)
{
    this->ID = ID;
    this->name = name;
    this->sex = sex;
    this->birthday = birth;
    this->hometown = home;
    this->address = add;
}

void StuInfoTemplate::showStuInfo()
{
    qDebug()<<"ID:"<<ID
            <<" name:"<<name
            <<" sex:"<<sex
            <<" birthday:"<<birthday
            <<" hometown:"<<hometown
            <<" address:"<<address
           <<endl;
}

QString StuInfoTemplate::getID() const
{
    return ID;
}

void StuInfoTemplate::setID(const QString &value)
{
    ID = value;
}

QString StuInfoTemplate::getName() const
{
    return name;
}

void StuInfoTemplate::setName(const QString &value)
{
    name = value;
}

QString StuInfoTemplate::getSex() const
{
    return sex;
}

void StuInfoTemplate::setSex(const QString &value)
{
    sex = value;
}

QString StuInfoTemplate::getBirthday() const
{
    return birthday;
}

void StuInfoTemplate::setBirthday(const QString &value)
{
    birthday = value;
}

QString StuInfoTemplate::getHometown() const
{
    return hometown;
}

void StuInfoTemplate::setHometown(const QString &value)
{
    hometown = value;
}

QString StuInfoTemplate::getAddress() const
{
    return address;
}

void StuInfoTemplate::setAddress(const QString &value)
{
    address = value;
}

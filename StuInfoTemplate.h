#ifndef STUINFOTEMPLATE_H
#define STUINFOTEMPLATE_H
#include "QString"
#include "QDebug"


class StuInfoTemplate
{
public:
    StuInfoTemplate();
    StuInfoTemplate(QString ID,QString name,QString sex,QString birth,QString home,QString add);
    void showStuInfo();

    QString getID() const;
    void setID(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getSex() const;
    void setSex(const QString &value);

    QString getBirthday() const;
    void setBirthday(const QString &value);

    QString getHometown() const;
    void setHometown(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

private:
    QString ID;
    QString name;
    QString sex;
    QString birthday;
    QString hometown;
    QString address;
};

#endif // STUINFOTEMPLATE_H

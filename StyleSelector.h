#ifndef STYLESELECTOR_H
#define STYLESELECTOR_H

#include <QFile>
#include <QApplication>

//样式选择器
class StyleSelector
{
public:
    StyleSelector();
    //静态函数，载入该路径的qss样式
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // STYLESELECTOR_H

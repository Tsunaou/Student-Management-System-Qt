#ifndef STYLESELECTOR_H
#define STYLESELECTOR_H

#include <QFile>
#include <QApplication>

class StyleSelector
{
public:
    StyleSelector();
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // STYLESELECTOR_H

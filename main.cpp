#include "StudentMS.h"
#include "StyleSelector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    StyleSelector::setStyle(":/qss/stylesheet/studentMS.qss");
//    StyleSelector::setStyle("H:/Advanced Cpp Programming/StudentMS_Qt/stylesheet/studentMS.qss");

    StudentMS w;
    w.show();
    w.showLoginBox();

    return a.exec();
}

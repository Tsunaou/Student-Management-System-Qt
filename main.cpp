#include "StudentMS.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentMS w;
    w.show();

    return a.exec();
}

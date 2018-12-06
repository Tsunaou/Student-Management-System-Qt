#ifndef SUBWINDOW_H
#define SUBWINDOW_H
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QMessageBox>

class SubWindow : public QWidget
{
public:
    SubWindow();
    void addNewItem();

    QTableWidget *tb;
};

#endif // SUBWINDOW_H

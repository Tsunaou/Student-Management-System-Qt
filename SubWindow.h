#ifndef SUBWINDOW_H
#define SUBWINDOW_H
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include "StuDialog.h"
#include "StuTable.h"

class SubWindow : public StuTable
{
public:
    SubWindow();
    void addNewItem();

    QTableWidget *tb;
};

#endif // SUBWINDOW_H

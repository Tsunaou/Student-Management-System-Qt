#ifndef STUTABLE_H
#define STUTABLE_H

#include <QWidget>
#include <QTableWidget>
#include "StuDialog.h"

namespace Ui {
class StuTable;
}

class StuTable : public QWidget
{
    Q_OBJECT

public:
    explicit StuTable(QWidget *parent = nullptr);
    ~StuTable();
    void addItem();

private:
    Ui::StuTable *ui;
    QTableWidget *tb;
};

#endif // STUTABLE_H

#ifndef STUDENTMS_H
#define STUDENTMS_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QVector>
#include <QMap>
#include <QDebug>
#include <QMessageBox>

#include "StuSubWindow.h"
#include "StuDialog.h"

namespace Ui {
class StudentMS;
}

class StudentMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMS(QWidget *parent = nullptr);
    ~StudentMS();
    int getActiveTalbeIndex();

private slots:
    void on_actionNew_triggered();
    void on_actionAdd_triggered();

    void on_actionAbout_triggered();

private:
    Ui::StudentMS *ui;
    QVector<StuSubWindow*> subWnds;
    QMap<QMdiSubWindow*,int> WindMap;

    int tableIndex;

};

#endif // STUDENTMS_H

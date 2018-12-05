#include "StudentMS.h"
#include "ui_StudentMS.h"

StudentMS::StudentMS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMS)
{
    ui->setupUi(this);
}

StudentMS::~StudentMS()
{
    delete ui;
}

#include "SortDialog.h"
#include "ui_SortDialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
}

SortDialog::~SortDialog()
{
    delete ui;
}

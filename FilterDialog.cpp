#include "FilterDialog.h"
#include "ui_FilterDialog.h"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, [=](){ qDebug("ok or save");}); //绑定
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, [=](){ qDebug("cancel"); });
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

QString FilterDialog::getKey()
{
    return this->ui->KeyEdit->text();
}

QString FilterDialog::getTarget()
{
    return this->ui->TargetBox->currentText();
}

QString FilterDialog::getType()
{
    return this->ui->TypeBox->currentText();
}

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

int FilterDialog::getTargetIndex()
{
    return this->ui->TargetBox->currentIndex();
}

QString FilterDialog::getType()
{
    return this->ui->TypeBox->currentText();
}

bool FilterDialog::isRegex()
{
    return this->ui->RegxBox->checkState();
}

bool FilterDialog::isWild()
{
    return this->ui->WildBoix->checkState();
}

bool FilterDialog::isCaseSensitive()
{
    return this->ui->CaseBox->checkState();
}

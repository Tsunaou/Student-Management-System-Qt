#include "StuDialog.h"
#include "ui_StuDialog.h"

StuDialog::StuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, [=](){ qDebug("ok or save");}); //绑定
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, [=](){ qDebug("cancel"); });
    ui->SexBox->addItem("男");
    ui->SexBox->addItem("女");
}

StuDialog::~StuDialog()
{
    delete ui;
}

QString StuDialog::getID()
{
    return  this->ui->IDEdit->text();
}

QVector<QString> StuDialog::getInput()
{
    QVector<QString> res;
    res.push_back(ui->IDEdit->text());
    res.push_back(ui->NameEdit->text());
    res.push_back(ui->SexBox->currentText());
    res.push_back(ui->BirthEdit->text());
    res.push_back(ui->HomeEdit->text());
    res.push_back(ui->AddEdit->text());

    return res;
}

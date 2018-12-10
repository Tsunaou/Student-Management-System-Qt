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

    ui->IDEdit->setPlaceholderText("请输入学生的学号（值唯一）");
    ui->NameEdit->setPlaceholderText("请输入学生的姓名");
    ui->HomeEdit->setPlaceholderText("请输入学生的籍贯");
    ui->AddEdit->setPlaceholderText("请输入学生的住址");


    QWidget::setTabOrder(ui->IDEdit, ui->NameEdit);
    QWidget::setTabOrder(ui->NameEdit, ui->SexBox);
    QWidget::setTabOrder(ui->SexBox, ui->BirthEdit);
    QWidget::setTabOrder(ui->BirthEdit, ui->HomeEdit);
    QWidget::setTabOrder(ui->HomeEdit, ui->AddEdit);
    QWidget::setTabOrder(ui->AddEdit, ui->buttonBox);
}

StuDialog::~StuDialog()
{
    delete ui;
}

StuInfoTemplate &StuDialog::getStuInfo()
{
    this->stuInfo = StuInfoTemplate(ui->IDEdit->text(),
                                    ui->NameEdit->text(),
                                    ui->SexBox->currentText(),
                                    ui->BirthEdit->text(),
                                    ui->HomeEdit->text(),
                                    ui->AddEdit->text());
    return this->stuInfo;
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

void StuDialog::setByStuInfo(StuInfoTemplate info)
{
    QDateTime time;
    QString str = info.getBirthday();
    QStringList sections = str.split(QRegExp("[//]")); //分割birthday
    time.setDate(QDate(sections.at(0).toInt(),sections.at(1).toInt(),sections.at(2).toInt()));

    ui->IDEdit->setText(info.getID());
    ui->NameEdit->setText(info.getName());
    ui->SexBox->setCurrentText(info.getSex());
    ui->BirthEdit->setDateTime(time);
    ui->HomeEdit->setText(info.getHometown());
    ui->AddEdit->setText(info.getAddress());
}

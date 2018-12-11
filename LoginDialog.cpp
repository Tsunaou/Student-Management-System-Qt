#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include "config.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->UserEdit->setPlaceholderText("请输入管理员用户名");
    ui->PwdEdit->setEchoMode(QLineEdit::Password);
    ui->PwdEdit->setPlaceholderText("请输入密码（不超过11位）");
    ui->PwdEdit->setMaxLength(11);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, [=](){ qDebug("ok or save");}); //绑定
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, [=](){ qDebug("cancel"); });
    //Test阶段
//    ui->PwdEdit->setText(PASSWORD);
//    ui->UserEdit->setText(USERNAME);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUSER()
{
    return ui->UserEdit->text();
}

QString LoginDialog::getPWD()
{
    return ui->PwdEdit->text();
}

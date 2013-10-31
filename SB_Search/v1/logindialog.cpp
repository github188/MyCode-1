#include "logindialog.h"
#include "ui_logindialog.h"
#include<QFile>
#include<QTextStream>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    data.clear();

    QFile file("UserInformation.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        QString s,t;
        s=in.readLine();t=in.readLine();
        data.insert(s,t);
    }
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::get_pMW(MainWindow* t)
{
    pMW=t;
}

void LoginDialog::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text(),t=ui->lineEdit_2->text();
    QMap<QString,QString>::iterator it=data.find(s);
    if (it==data.end())
    {
        ui->label_3->setText("Ã»ÓÐ¸ÃÕÊºÅ£¡");
        return;
    }
    if (t!=it.value())
    {
        ui->label_3->setText("ÃÜÂë´íÎó£¡");
        return;
    }
    pMW=new MainWindow;
    pMW->setUser(s);
    this->reject();
    pMW->show();
}

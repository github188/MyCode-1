#include "changeinformationdialog.h"
#include "ui_changeinformationdialog.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QVector>

ChangeInformationDialog::ChangeInformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeInformationDialog)
{
    ui->setupUi(this);
}

ChangeInformationDialog::~ChangeInformationDialog()
{
    delete ui;
}
void ChangeInformationDialog::get_right(int o,QString s,UserDialog* p)
{
    right=o;
    user=s;
    u=p;
}

void ChangeInformationDialog::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text(),t=ui->lineEdit_2->text(),st=ui->lineEdit_3->text();
    if (s!=t)
    {
        ui->label_4->setText("ÃÜÂë²»Ò»ÖÂ£¡");
        return;
    }

    QString tmp;

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="information.txt";
    QFile file(tmp);
    QTextStream out(&file);
    file.open(QIODevice::WriteOnly);
    out<<s<<endl<<st<<endl<<QString::number(right)<<endl;
    file.close();

    QFile file1("UserInformation.txt");
    QTextStream in(&file1);
    file1.open(QIODevice::ReadOnly);
    QVector<QString> tmp_s;tmp_s.clear();
    while (!in.atEnd())
    {
        QString tmp=in.readLine();
        tmp_s.push_back(tmp);
        if (tmp!=user) {tmp=in.readLine();}
        else
        {
            tmp=in.readLine();
            tmp_s.push_back(s);
        }

    }
    file1.close();

    QFile file2("UserInformation.txt");
    QTextStream out1(&file2);
    file2.open(QIODevice::WriteOnly);
    for (int i=0;i<tmp_s.size();i+=2)
    {
        out1<<tmp_s[i]<<endl<<tmp_s[i+1]<<endl;
    }
    file2.close();

    u->setUser(user);

    this->reject();
}

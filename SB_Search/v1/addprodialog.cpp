#include "addprodialog.h"
#include "ui_addprodialog.h"
#include<QMessageBox>
#include<QDir>
#include<iostream>
using namespace std;

AddProDialog::AddProDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProDialog)
{
    ui->setupUi(this);
}

AddProDialog::~AddProDialog()
{
    delete ui;
}

void AddProDialog::setUser(QString s)
{
    user=s;
}

void AddProDialog::on_pushButton_clicked()
{
    if (ui->lineNum->text().length()==0)
    {
        ui->labelWarning->setText("项目编号不能为空！");
        return;
    }

    QString tmp;
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="visible.txt";

    QFile file(tmp);
    QTextStream out(&file);
    file.open(QIODevice::Append);
    out<<ui->lineNum->text()<<endl;
    file.close();


    tmp.clear();
    //tmp+=".";tmp+="\\";tmp+="\\";
    //tmp+=user;tmp+="\\";tmp+="\\";
    tmp="index.txt";

    QFile file1(tmp);
    QTextStream out1(&file1);
    file1.open(QIODevice::Append);
    out1<<ui->lineNum->text()<<endl
        <<ui->lineName->text()<<endl
        <<ui->lineSource->text()<<endl
        <<ui->lineType->text()<<endl
        <<ui->lineCompany->text()<<endl
        <<ui->lineLeader->text()<<endl
        <<ui->lineMoney->text()<<endl
        <<ui->lineStart_Time->text()<<endl
        <<ui->lineState->text()<<endl;
    file1.close();

    QDir u;
    u.mkdir(ui->lineNum->text());

    tmp.clear();QString at=ui->lineNum->text();

    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=at;tmp+="\\";tmp+="\\";
    tmp+="jjxy.txt";

    QFile file2(tmp);
    QTextStream out2(&file2);
    if (!file2.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        cerr<<"fuck"<<endl;
        return;
    }
    out2<<ui->textjjxy->toPlainText() <<endl;
    file2.close();


    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=ui->lineNum->text();tmp+="\\";tmp+="\\";
    tmp+="shxy.txt";

    QFile file3(tmp);
    QTextStream out3(&file3);
    file3.open(QIODevice::WriteOnly);
    out3<<ui->textshxy->toPlainText() <<endl;
    file3.close();

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=ui->lineNum->text();tmp+="\\";tmp+="\\";
    tmp+="yfcg.txt";

    QFile file4(tmp);
    QTextStream out4(&file4);
    file4.open(QIODevice::WriteOnly);
    out4<<ui->textyfcg->toPlainText() <<endl;
    file4.close();

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=ui->lineNum->text();tmp+="\\";tmp+="\\";
    tmp+="yyqj.txt";

    QFile file5(tmp);
    QTextStream out5(&file5);
    file5.open(QIODevice::WriteOnly);
    out5<<ui->textyyqj->toPlainText() <<endl;
    file5.close();

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=ui->lineNum->text();tmp+="\\";tmp+="\\";
    tmp+="yyqk.txt";

    QFile file6(tmp);
    QTextStream out6(&file6);
    file6.open(QIODevice::WriteOnly);
    out6<<ui->textyyqk->toPlainText() <<endl;
    file6.close();

    QMessageBox* mes;
    mes=new QMessageBox;
    mes->setText("添加成功！");
    mes->show();

    this->reject();
}

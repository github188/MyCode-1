#include "userdialog.h"
#include "ui_userdialog.h"
#include "changeinformationdialog.h"
#include<QStringList>
#include<QMessageBox>
#include"managementuserdialog.h"
#include"guestpaydialog.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::setUser(QString tmp)
{
    user=tmp;

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="information.txt";
    QFile file(tmp);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    pwd=in.readLine();
    email=in.readLine();
    tmp=in.readLine();
    right=tmp.toInt();

    ui->label_2->setText(user);
    ui->label_4->setText(email);
    if ((right&1)!=0) {ui->label_6->setText("可增加记录");}
    else
    {
        ui->label_6->setText("不可增加记录");
        ui->pushButton_3->setVisible(false);
    }
    if ((right&2)!=0) {ui->label_7->setText("可更改用户权限");}
    else
    {
        ui->label_7->setText("不可更改用户权限");
        ui->pushButton_4->setVisible(false);
    }

    file.close();

    set.clear();
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="visible.txt";
    QFile file2(tmp);
    QTextStream in2(&file2);
    file2.open(QIODevice::ReadOnly);
    while (!in2.atEnd())
    {
        QString s=in2.readLine();
        set.insert(s);
    }
    file2.close();

    ui->tableWidget->clear();
    QStringList header;header.clear();
    header<<"项目编号"<<"项目名"<<"";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QVector<QString> tmp_s;tmp_s.clear();
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="StoredUp.txt";
    QFile file1(tmp);
    QTextStream in1(&file1);
    file1.open(QIODevice::ReadOnly);

    while (!in1.atEnd())
    {
        QString s=in1.readLine();
        tmp_s.push_back(s);
    }
    file1.close();

    ui->tableWidget->setRowCount(tmp_s.size()/2+1);
    for (int i=0;i<tmp_s.size();i+=2)
    {
        ui->tableWidget->setItem(i/2,0,new QTableWidgetItem(tmp_s[i]));
        ui->tableWidget->setItem(i/2,1,new QTableWidgetItem(tmp_s[i+1]));
        QSet<QString>::iterator it=set.find(tmp_s[i]);
        if (it!=set.end())
        {
            ui->tableWidget->setItem(i/2,2,new QTableWidgetItem("已支付"));
        } else {
        ui->tableWidget->setItem(i/2,2,new QTableWidgetItem("未支付"));}
    }

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="shared.txt";
    QFile file3(tmp);
    QTextStream in3(&file3);
    file3.open(QIODevice::ReadOnly);
    data.clear();

    while (!in3.atEnd())
    {
        QString s=in3.readLine();
        data.push_back(s);
    }
    file3.close();

    ui->tableWidget_2->clear();
    QStringList header1;header1.clear();
    header1<<"项目编号"<<"项目名"<<"推荐人"<<""<<"";
    ui->tableWidget_2->setColumnCount(5);
    ui->tableWidget_2->setHorizontalHeaderLabels(header1);
    ui->tableWidget_2->setRowCount(data.size()/3);
    for (int i=0;i<data.size();i+=3)
    {
        ui->tableWidget_2->setItem(i/3,0,new QTableWidgetItem(data[i]));
        ui->tableWidget_2->setItem(i/3,1,new QTableWidgetItem(data[i+1]));
        ui->tableWidget_2->setItem(i/3,2,new QTableWidgetItem(data[i+2]));
        ui->tableWidget_2->setItem(i/3,3,new QTableWidgetItem("收藏"));
        ui->tableWidget_2->setItem(i/3,4,new QTableWidgetItem("取消"));
    }
}

void UserDialog::on_pushButton_clicked()
{
    ChangeInformationDialog* d;
    d=new ChangeInformationDialog;
    d->get_right(right,user,this);
    d->show();
}

bool UserDialog::check(QString s)
{
    QString tmp;
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="StoredUp.txt";
    QFile file(tmp);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        QString st=in.readLine();
        if (st==s) {file.close();return true;}
    }

    file.close();
    return false;
}

void UserDialog::on_tableWidget_2_itemClicked(QTableWidgetItem *item)
{
    if (item->column()<3) return;
    if ((item->column()==3)&&(!check(data[item->row()*3])))
    {
        QString tmp;
        tmp.clear();
        tmp+=".";tmp+="\\";tmp+="\\";
        tmp+=user;tmp+="\\";tmp+="\\";
        tmp+="StoredUp.txt";
        QFile file(tmp);
        QTextStream out(&file);
        file.open(QIODevice::Append);

        out<<data[item->row()*3]<<endl<<data[item->row()*3+1]<<endl;
        file.close();

        QMessageBox mes;
        mes.setText("收藏成功！");
    }

    QString tmp;
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="shared.txt";
    QFile file(tmp);
    QTextStream out(&file);
    file.open(QIODevice::WriteOnly);

    for (int i=0;i<data.size();i+=3)
        if (i/3!=item->row())
        {
            out<<data[i*3]<<endl<<data[i*3+1]<<endl<<data[i*3+2]<<endl;
        }
    file.close();

    if (item->column()==4)
    {
        QMessageBox mes;
        mes.setText("取消成功！");
    }

    this->setUser(user);
}

void UserDialog::on_pushButton_2_clicked()
{
    FocusDialog* FD;
    FD=new FocusDialog;
    FD->setUser(user);
    FD->show();
}

void UserDialog::on_pushButton_3_clicked()
{
    AddProDialog* pAPD;
    pAPD=new AddProDialog;
    pAPD->setUser(user);
    pAPD->show();
}

void UserDialog::on_pushButton_4_clicked()
{
    ManagementUserDialog* pMUD;
    pMUD=new ManagementUserDialog;
    pMUD->setUser(user);
    pMUD->show();
}

void UserDialog::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item->text()=="未支付")
    {
        GuestPayDialog* pGPD=new GuestPayDialog;
        pGPD->setUser(user);
        pGPD->show();
        return;
    }
}

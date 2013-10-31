#include "share_to_friend.h"
#include "ui_share_to_friend.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QStringList>

Share_to_Friend::Share_to_Friend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Share_to_Friend)
{
    ui->setupUi(this);
}

Share_to_Friend::~Share_to_Friend()
{
    delete ui;
}

void Share_to_Friend::get_inf(QString t_u,QString t_i,QString t_n)
{
    user=t_u;
    id=t_i;
    name=t_n;
}

void Share_to_Friend::work()
{
    ui->tableWidget->clear();
    QStringList header;header.clear();
    header<<"好友"<<"";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnCount(2);
    QString tmp;tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="friends.txt";
    QFile file(tmp);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    s.clear();
    while (!in.atEnd())
    {
        QString tmp=in.readLine();
        s.push_back(tmp);
    }
    ui->tableWidget->setRowCount(s.size()+1);

    int num=s.size();
    for (int i=0;i<num;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(s[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem("推荐给Ta"));
    }
    s.push_back(user);
    ui->tableWidget->setItem(num,0,new QTableWidgetItem(user));
    ui->tableWidget->setItem(num,1,new QTableWidgetItem("自己收藏"));


    this->show();
}

void Share_to_Friend::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item->column()!=1) return;
    int num=item->row();
    QString tmp;tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=s[num];tmp+="\\";tmp+="\\";
    if (num!=s.size()-1) {tmp+="shared.txt";}
    else {tmp+="StoredUp.txt";}
    QFile file(tmp);
    QTextStream out(&file);
    file.open(QIODevice::Append|QIODevice::WriteOnly);

    QString tmp1;tmp1.clear();
    tmp1+=id;tmp1+="\n";
    tmp1+=name;tmp1+="\n";
    if (num!=s.size()-1)
    {
        tmp1+=user;
        tmp1+="\n";
    }
    out<<tmp1;
    file.close();
    QMessageBox* mes;
    mes=new QMessageBox;
    mes->setText("推荐成功");
    mes->show();
}

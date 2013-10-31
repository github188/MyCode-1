#include "managementuserdialog.h"
#include "ui_managementuserdialog.h"
#include<QStringList>
#include<QTableWidgetItem>

ManagementUserDialog::ManagementUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagementUserDialog)
{
    ui->setupUi(this);
}

ManagementUserDialog::~ManagementUserDialog()
{
    delete ui;
}

void ManagementUserDialog::setUser(QString s)
{
    user=s;
    ui->tableWidget->clear();
    QStringList header;header.clear();
    header<<"用户名"<<"是否可增加项目"<<"是否可增加用户权限";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);

    uList.clear();
    uRight.clear();

    QFile file("UserInformation.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while (!in.atEnd())
    {
        QString s=in.readLine();
        uList.push_back(s);

        QString tmp;tmp.clear();
        tmp+=".";tmp+="\\";tmp+="\\";
        tmp+=s;tmp+="\\";tmp+="\\";
        tmp+="information.txt";
        QFile file2(tmp);
        QTextStream in2(&file2);
        file2.open(QIODevice::ReadOnly);
        QString t;t=in2.readLine();t=in2.readLine();t=in2.readLine();
        uRight.push_back(t.toInt());
        file2.close();

        s=in.readLine();
    }
    file.close();

    ui->tableWidget->setRowCount(uList.size());
    for (int i=0;i<uList.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(uList[i]));
        if ((uRight[i]&1)==0)
        {
            ui->tableWidget->setItem(i,1,new QTableWidgetItem("否"));
        }
        else
        {
            ui->tableWidget->setItem(i,1,new QTableWidgetItem("是"));
        }
        if ((uRight[i]&2)==0)
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("否"));
        }
        else
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("是"));
        }
    }
}

void ManagementUserDialog::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int x=item->row(),y=item->column();
    if (y==1)
    {
        uRight[x]^=1;
    }
    if (y==2)
    {
        uRight[x]^=2;
    }

    QString tmp;tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=uList[x];tmp+="\\";tmp+="\\";
    tmp+="information.txt";
    QFile file2(tmp);
    QTextStream in2(&file2);
    file2.open(QIODevice::ReadOnly);
    QString t1,t2,t3;t1=in2.readLine();t2=in2.readLine();t3=QString::number(uRight[x]);
    file2.close();

    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=uList[x];tmp+="\\";tmp+="\\";
    tmp+="information.txt";
    QFile file(tmp);
    QTextStream out(&file);
    file.open(QIODevice::WriteOnly);
    out<<t1<<endl<<t2<<endl<<t3<<endl;
    file.close();

    this->setUser(user);

}

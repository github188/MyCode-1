#include "money.h"
#include "ui_money.h"
#include <QTableWidget>
#include <QStringList>
#include <QMap>
#include <QList>

Money::Money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Money)
{
    ui->setupUi(this);

    ui->comboBox->clear();
    ui->comboBox->addItem("");
    ui->comboBox->addItem("按项目来源分类");
    ui->comboBox->addItem("按项目类别分类");
    ui->comboBox->addItem("按承担单位分类");
}

Money::~Money()
{
    delete ui;
}

void Money::get_inf(QVector<inf_str> d)
{
    data=d;
    int sum=0,num=data.size();
    for (int i=0;i<num;i++)
    {
        QString s;s.clear();
        for (int j=0;j<data[i].money.length();j++)
            if ((data[i].money[j]>='0')&&(data[i].money[j]<='9'))
        {
            s+=data[i].money[j];
        }
        sum+=s.toInt();
    }
    QString tmp;tmp.clear();
    tmp=QString::number(sum);
    tmp+="万";
    ui->label_2->setText(tmp);
}

void Money::on_pushButton_clicked()
{
    ui->tableWidget->clear();
    QString tmp=ui->comboBox->currentText();
    if (tmp.length()==0) return;
    ui->tableWidget->setColumnCount(2);
    QStringList header;header.clear();
    header<<tmp<<"经费";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QMap<QString,int> map;map.clear();
    int num=data.size(),index=ui->comboBox->currentIndex();
    for (int i=0;i<num;i++)
    {
        QString tmp;tmp.clear();
        if (index==1)
        {
            QString tmp1;
            tmp1=data[i].source;
            for (int i=0;i<tmp1.length();i++)
                if (tmp1[i]!=' ') tmp+=tmp1[i];
        } else
            if (index==2)
            {
                QString tmp1;
                tmp1=data[i].typ;
                for (int i=0;i<tmp1.length();i++)
                    if (tmp1[i]!=' ') tmp+=tmp1[i];
            } else
            {
                QString tmp1;
                tmp1=data[i].company;
                for (int i=0;i<tmp1.length();i++)
                    if (tmp1[i]!=' ') tmp+=tmp1[i];
            }

        QString s;s.clear();
        for (int j=0;j<data[i].money.length();j++)
            if ((data[i].money[j]>='0')&&(data[i].money[j]<='9'))
        {
            s+=data[i].money[j];
        }

        QMap<QString,int>::iterator it=map.find(tmp);
        if (it==map.end())
        {
            map.insert(tmp,s.toInt());
        } else
        {
            it.value()+=s.toInt();
        }
    }

    ui->tableWidget->setRowCount(map.size());
    int num1=map.size();
    QList<QString> tmp_l1=map.keys();
    QList<int> tmp_l2=map.values();
    for (int i=0;i<num1;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(tmp_l1[i]));
        QString tmp=QString::number(tmp_l2[i]);
        tmp+="万";
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(tmp));
    }

}

#include "focusdialog.h"
#include "ui_focusdialog.h"
#include<QTextEdit>
#include<QMessageBox>
#include"addfocusdialog.h"

FocusDialog::FocusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FocusDialog)
{
    ui->setupUi(this);
}

FocusDialog::~FocusDialog()
{
    delete ui;
}

void FocusDialog::setUser(QString s)
{
    user=s;
    data.clear();
    QString tmp;
    tmp.clear();
    tmp+=".";tmp+="\\";tmp+="\\";
    tmp+=user;tmp+="\\";tmp+="\\";
    tmp+="friends.txt";

    QFile file(tmp);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while (!in.atEnd())
    {
        QString s=in.readLine();
        data.push_back(s);
    }
    file.close();

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(data.size());
    for (int i=0;i<data.size();i++)
    {
         ui->tableWidget->setItem(i,0,new QTableWidgetItem(data[i]));
         ui->tableWidget->setItem(i,1,new QTableWidgetItem("取消"));
    }
}

void FocusDialog::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item->column()==0)
    {
        QString tmp;
        tmp.clear();
        tmp+=".";tmp+="\\";tmp+="\\";
        tmp+=data[item->row()];tmp+="\\";tmp+="\\";
        tmp+="information.txt";

        QFile file(tmp);
        QTextStream in(&file);
        file.open(QIODevice::ReadOnly);
        QString t;t.clear();int i=0;
        while (!in.atEnd())
        {
            QString s=in.readLine();
            if (i!=0) {t+=s;t+="\n";}i++;
        }
        file.close();
        QTextEdit* te=new QTextEdit;
        te->setText(t);
        te->show();
    } else
    {
        QString tmp;
        tmp.clear();
        tmp+=".";tmp+="\\";tmp+="\\";
        tmp+=user;tmp+="\\";tmp+="\\";
        tmp+="friends.txt";

        QFile file(tmp);
        QTextStream in(&file);
        file.open(QIODevice::ReadOnly);
        QVector<QString> tmp_d;tmp_d.clear();
        while (!in.atEnd())
        {
            QString s=in.readLine();
            if (s!=data[item->row()])
            {
                tmp_d.push_back(s);
            }
        }
        file.close();

        QFile file1(tmp);
        QTextStream out(&file1);
        file1.open(QIODevice::WriteOnly);
        for (int i=0;i<tmp_d.size();i++) out<<tmp_d[i]<<endl;
        file1.close();
        QMessageBox* me=new QMessageBox;
        me->setText("取消成功！");
        me->show();
    }
    this->setUser(user);
}

void FocusDialog::on_pushButton_clicked()
{
    AddFocusDialog* pAFD=new AddFocusDialog;
    pAFD->setUser(user,this);
    pAFD->show();
}

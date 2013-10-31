#include "addfocusdialog.h"
#include "ui_addfocusdialog.h"
#include<QMessageBox>
#include<QTextEdit>

AddFocusDialog::AddFocusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFocusDialog)
{
    ui->setupUi(this);
}

AddFocusDialog::~AddFocusDialog()
{
    delete ui;
}

void AddFocusDialog::setUser(QString s,FocusDialog* p)
{
    user=s;
    pFD=p;
}

void AddFocusDialog::on_pushButton_clicked()
{
    QString t=ui->lineEdit->text();

    QString tmp;
    tmp.clear();
    tmp+="UserInformation.txt";

    QFile file(tmp);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    vec.clear();

    while (!in.atEnd())
    {
        QString s=in.readLine();
        bool check=false;
        for (int i=0;i<=s.length()-t.length();i++)
        {
            bool use=true;
            for (int j=0;j<t.length();j++) if (s[i+j]!=t[j]) {use=false;break;}
            if (use) {check=use;break;}
        }
        if(check) vec.push_back(s);
        s=in.readLine();
    }

    file.close();

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(vec.size());
    ui->tableWidget->setColumnCount(2);
    for (int i=0;i<vec.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(vec[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem("添加"));
    }
}

void AddFocusDialog::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item->column()==0)
    {
        QString tmp;
        tmp.clear();
        tmp+=".";tmp+="\\";tmp+="\\";
        tmp+=vec[item->row()];tmp+="\\";tmp+="\\";
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
        bool check=false;
        while (!in.atEnd())
        {
            QString s=in.readLine();
            if (s==vec[item->row()])
            {
                check=true;
            }
        }
        file.close();

        if (!check)
        {
          QFile file1(tmp);
          QTextStream out(&file1);
          file1.open(QIODevice::Append);
          out<<vec[item->row()]<<endl;
          file1.close();
        }
        QMessageBox* me=new QMessageBox;
        me->setText("添加成功！");
        me->show();
    }
    pFD->setUser(user);
}

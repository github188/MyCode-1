#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<string.h>
#include <QStringList>
#include <QTableWidget>
#include <QTextEdit>
#include<QSet>
#include<QPrinter>
#include<QTextDocument>
#include"dialog.h"
#include"money.h"
#include"share_to_friend.h"
#include"userdialog.h"
#include"guestpaydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(SearchClicked()));
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(OnItemClicked(QTableWidgetItem *)));

    data.clear();
    QFile file("index.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        inf_str tmp;
        for (int i=0;i<9;i++)
        {
            QString s=in.readLine();
            if (i==0) tmp.num=s;
            if (i==1) tmp.name=s;
            if (i==2) tmp.source=s;
            if (i==3)
            {
                tmp.typ=s;
                if (s[0]==' ')
                {
                    QString st;st.clear();
                    for (int i=1;i<s.length();i++)
                    {
                        st+=s[i];
                    }
                    tmp.typ=st;
                }
            }
            if (i==4) tmp.company=s;
            if (i==5) tmp.leader=s;
            if (i==6) tmp.money=s;
            if (i==7) tmp.Start_Time=s;
            if (i==8) tmp.State=s;
        }
        data.push_back(tmp);
    }
    file.close();
    QSet<QString> set1;
    set1.clear();
    ui->comboBoxCompany->addItem("");
    for (int i=0;i<data.size();i++)
    {
        QString s=data[i].company;
        QSet<QString>::iterator it=set1.find(s);
        if (it==set1.end())
        {
            ui->comboBoxCompany->addItem(s);
            set1.insert(s);
        }
    }

    set1.clear();
    ui->comboBoxSource->addItem("");
    for (int i=0;i<data.size();i++)
    {
        QString s=data[i].source;
        QSet<QString>::iterator it=set1.find(s);
        if (it==set1.end())
        {
            ui->comboBoxSource->addItem(s);
            set1.insert(s);
        }
    }

    set1.clear();
    ui->comboBoxtyp->addItem("");
    for (int i=0;i<data.size();i++)
    {
        QString s=data[i].typ;
        QSet<QString>::iterator it=set1.find(s);
        if (it==set1.end())
        {
            ui->comboBoxtyp->addItem(s);
            set1.insert(s);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

inf_str MainWindow::get_str()
{
    inf_str tmp;
    tmp.num=ui->lineNum->text();
    tmp.name=ui->lineName->text();
    tmp.company=ui->comboBoxCompany->currentText();
    tmp.leader=ui->lineLeader->text();
    tmp.money=ui->lineMoney->text();
    tmp.source=ui->comboBoxSource->currentText();
    tmp.Start_Time=ui->lineStart_Time->text();
    tmp.State=ui->lineState->text();
    tmp.typ=ui->comboBoxtyp->currentText();
    return tmp;
}

bool MainWindow::search_base(inf_str tmp,int o)
{
    if (tmp.company.length()!=0)
    {
        s_goal="承担单位";
        bool check=false;
        for (int i=0;i<=data[o].company.length()-tmp.company.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.company.length();j++)
                if (data[o].company[i+j]!=tmp.company[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.leader.length()!=0)
    {
        s_goal="项目负责人";
        bool check=false;
        for (int i=0;i<=data[o].leader.length()-tmp.leader.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.leader.length();j++)
                if (data[o].leader[i+j]!=tmp.leader[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.money.length()!=0)
    {
        s_goal="项目经费";
        bool check=false;/*
        for (int i=0;i<=data[o].money.length()-tmp.money.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.money.length();j++)
                if (data[o].money[i+j]!=tmp.money[j]) use=false;
            check=use;if (check) break;
        }*/
        QString s=ui->lineMoney_2->text();
        int ul=0,dl=0,money=0;
        for (int i=0;i<tmp.money.length();i++)
        {
            char ch=tmp.money[i].toAscii();
            if ((ch<'0')||(ch>'9')) break;
            ul=ul*10+ch-'0';
        }
        for (int i=0;i<s.length();i++)
        {
            char ch=s[i].toAscii();
            if ((ch<'0')||(ch>'9')) break;
            dl=dl*10+ch-'0';
        }
        for (int i=0;i<data[o].money.length();i++)
        {
            char ch=data[o].money[i].toAscii();
            if ((ch<'0')||(ch>'9')) break;
            money=money*10+ch-'0';
        }
        if ((money>=ul)&&(money<=dl)) check=true;

        if (!check) return false;
    }

    if (tmp.name.length()!=0)
    {
        s_goal="项目名称";
        bool check=false;
        for (int i=0;i<=data[o].name.length()-tmp.name.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.name.length();j++)
                if (data[o].name[i+j]!=tmp.name[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.num.length()!=0)
    {
        s_goal="项目编号";
        bool check=false;
        for (int i=0;i<=data[o].num.length()-tmp.num.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.num.length();j++)
                if (data[o].num[i+j]!=tmp.num[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.source.length()!=0)
    {
        s_goal="项目来源";
        bool check=false;
        for (int i=0;i<=data[o].source.length()-tmp.source.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.source.length();j++)
                if (data[o].source[i+j]!=tmp.source[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.Start_Time.length()!=0)
    {
        s_goal="立题时间";
        bool check=false;
        for (int i=0;i<=data[o].Start_Time.length()-tmp.Start_Time.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.Start_Time.length();j++)
                if (data[o].Start_Time[i+j]!=tmp.Start_Time[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.State.length()!=0)
    {
        s_goal="实施情况";
        bool check=false;
        for (int i=0;i<=data[o].State.length()-tmp.State.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.State.length();j++)
                if (data[o].State[i+j]!=tmp.State[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    if (tmp.typ.length()!=0)
    {
        s_goal="项目类别";
        bool check=false;
        for (int i=0;i<=data[o].typ.length()-tmp.typ.length();i++)
        {
            bool use=true;
            for (int j=0;j<tmp.typ.length();j++)
                if (data[o].typ[i+j]!=tmp.typ[j]) use=false;
            check=use;if (check) break;
        }
        if (!check) return false;
    }

    return true;
}

bool MainWindow::search_extend(QString num,int o)
{
    QString s=ui->linejjxy->text();
    if (s.length()!=0)
    {
        s_goal="项目负责人";
        QString path;path.clear();
        path+='.';path+='\\';path+='\\';
        path+=num;path+='\\';path+='\\';
        path+="jjxy.txt";

        if (!deal(s,path)) return false;
    }

    s=ui->lineshxy->text();
    if (s.length()!=0)
    {
            s_goal="项目负责人";
            QString path;path.clear();
            path+='.';path+='\\';path+='\\';
            path+=num;path+='\\';path+='\\';
            path+="shxy.txt";

            if (!deal(s,path)) return false;
    }

    s=ui->lineyfcg->text();
    if (s.length()!=0)
    {
            s_goal="研发成果";
            QString path;path.clear();
            path+='.';path+='\\';path+='\\';
            path+=num;path+='\\';path+='\\';
            path+="yfcg.txt";

            if (!deal(s,path)) return false;
    }

    s=ui->lineyyqj->text();
    if (s.length()!=0)
    {
                s_goal="项目负责人";
                QString path;path.clear();
                path+='.';path+='\\';path+='\\';
                path+=num;path+='\\';path+='\\';
                path+="yyqj.txt";

                if (!deal(s,path)) return false;
    }

    s=ui->lineyyqk->text();
    if (s.length()!=0)
    {
                    s_goal="项目负责人";
                    QString path;path.clear();
                    path+='.';path+='\\';path+='\\';
                    path+=num;path+='\\';path+='\\';
                    path+="yyqk.txt";

                    if (!deal(s,path)) return false;
    }

    return true;
}


bool MainWindow::deal(QString s,QString path)
{
    QString st=get_doc(path);
    QVector<QString> data;
    data.clear();

    int j;j=0;
    while (j<s.length())
    {
        QString t;t.clear();
        while ((j<s.length())&&(s[j]!=' '))
        {
            t+=s[j];
            j++;
        }
        data.push_back(t);
        j++;
    }

    int num=data.size();
    for (int i=0;i<num;i++)
    {
        bool check=false;
        int len=st.length()-data[i].length();
        int len1=data[i].length();
        for (int j=0;j<=len;j++)
        {
            bool use=true;
            for (int k=0;k<len1;k++)
                if (st[j+k]!=data[i][k])
                {
                    use=false;
                    break;
                }
            if (use) {check=true;break;}
        }

        if (!check) return false;
    }

    return true;
}

QString MainWindow::get_doc(QString path)
{
    QString ans;ans.clear();
    QFile file(path);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        ans+=in.readLine();
        ans+="\n";
    }
    file.close();
    return ans;
}

QString MainWindow::document(inf_str tmp)
{
    QString ans;ans.clear();
    ans+="项目编号：";ans+=tmp.num;ans+="\n";
    ans+="项目名称：";ans+=tmp.name;ans+="\n";
    ans+="项目来源：";ans+=tmp.source;ans+="\n";
    ans+="项目类别：";ans+=tmp.typ;ans+="\n";
    ans+="承担单位：";ans+=tmp.company;ans+="\n";
    ans+="项目负责人：";ans+=tmp.leader;ans+="\n";
    ans+="项目经费：";ans+=tmp.money;ans+="\n";
    ans+="立题时间：";ans+=tmp.Start_Time;ans+="\n";
    ans+="实施情况：";ans+=tmp.State;ans+="\n";
    QString path;

    {
       ans+="研发成果：";
       path.clear();
       path+='.';path+='\\';path+='\\';
       path+=tmp.num;path+='\\';path+='\\';
       path+="yfcg.txt";
       ans+=get_doc(path);
    }

    {
       ans+="应用情况：";
       path.clear();
       path+='.';path+='\\';path+='\\';
       path+=tmp.num;path+='\\';path+='\\';
       path+="yyqk.txt";
       ans+=get_doc(path);
    }

    {
       ans+="经济效益：";
       path.clear();
       path+='.';path+='\\';path+='\\';
       path+=tmp.num;path+='\\';path+='\\';
       path+="jjxy.txt";
       ans+=get_doc(path);
    }

    {
       ans+="社会效益：";
       path.clear();
       path+='.';path+='\\';path+='\\';
       path+=tmp.num;path+='\\';path+='\\';
       path+="shxy.txt";
       ans+=get_doc(path);
    }

    {
       ans+="应用前景：";
       path.clear();
       path+='.';path+='\\';path+='\\';
       path+=tmp.num;path+='\\';path+='\\';
       path+="yyqj.txt";
       ans+=get_doc(path);
    }

    ans+="------------------------------\n";
    return ans;
}

void MainWindow::init()
{
    ui->comboBoxCompany->setCurrentIndex(0);
    ui->comboBoxtyp->setCurrentIndex(0);
    ui->lineState->setText(tr(""));
    ui->lineStart_Time->setText(tr(""));
    ui->comboBoxSource->setCurrentIndex(0);
    ui->lineNum->setText(tr(""));
    ui->lineName->setText(tr(""));
    ui->lineMoney->setText(tr(""));
    ui->lineMoney_2->setText(tr(""));
    ui->lineLeader->setText(tr(""));
    ui->linejjxy->setText(tr(""));
    ui->lineshxy->setText(tr(""));
    ui->lineyfcg->setText(tr(""));
    ui->lineyyqj->setText(tr(""));
    ui->lineyyqk->setText(tr(""));
}

void MainWindow::SearchClicked()
{
    inf_str tmp=get_str();
    QString ans1;ans1.clear();
    memset(use,true,sizeof(use));
    int opt=0;
    int num=data.size();
    for (int i=0;i<num;i++)
    {
        use[i]=search_base(tmp,i);
        if (use[i])
        {
            if (!search_extend(data[i].num,i)) use[i]=false;//continue;
            if (use[i]) opt++;
            //ans1+=document(data[i]);
        }
    }
    //ui->textEdit->setPlainText(ans1);

    ui->tableWidget->clear();
    QStringList header;header.clear();
    QString s1,s2;s1.clear();s2.clear();
    if (s_goal=="项目编号")
    {
        s1="项目名称";
        s2="项目负责人";
    } else
        if (s_goal=="项目名称")
        {
            s1="项目编号";
            s2="项目负责人";
        } else
        {
            s1="项目编号";
            s2="项目名称";
        }
    header<<s_goal<<s1<<s2<<""<<"";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(opt);
    int fth=0;

    if (s_goal=="研发成果")
    {
        ui->tableWidget->setRowCount(10000);
        ui->tableWidget->setColumnCount(6);
        header<<s_goal<<s1<<s2<<""<<""<<"";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        special_table(tmp,s1,s2);
    } else
    for (int i=0;i<num;i++)
        if (use[i])
        {
            ui->tableWidget->setItem(fth,0,new QTableWidgetItem(choose_name(s_goal,data[i])));
            ui->tableWidget->setItem(fth,1,new QTableWidgetItem(choose_name(s1,data[i])));
            ui->tableWidget->setItem(fth,2,new QTableWidgetItem(choose_name(s2,data[i])));
            ui->tableWidget->setItem(fth,3,new QTableWidgetItem("see more..."));
            ui->tableWidget->setItem(fth,4,new QTableWidgetItem("推荐给好友"));
            fth++;
        }

    init();

}

void MainWindow::special_table(inf_str tmp,QString s1,QString s2)
{
    int tot=0;
    int num=data.size();
    QString st=ui->lineyfcg->text();
    int lenst=st.length();
    for (int i=0;i<num;i++)
        if (use[i])
        {
            QString ans,path;
            ans.clear();
            path.clear();
            path.clear();
            path+='.';path+='\\';path+='\\';
            path+=data[i].num;path+='\\';path+='\\';
            path+="yfcg.txt";
            ans+=get_doc(path);
            int pos=0,len=ans.length();
            while (pos<len)
            {
                QString s;s.clear();
                while ((pos<len)&&(ans[pos]!='[')) pos++;
                if (pos>=len) break;
                while ((pos<len)&&(ans[pos]!='\n')) {s+=ans[pos];pos++;}

                int len1=s.length();
                int ul=len1-lenst;
                bool use=false;
                for (int j=0;j<=ul;j++)
                {
                    use=true;
                    for (int k=0;k<lenst;k++)
                        if (s[j+k]!=st[k]) {use=false;break;}
                    if (use) break;
                }
                if (use)
                {
                    mark[tot]=i;
                    ui->tableWidget->setItem(tot,0,new QTableWidgetItem(s));
                    ui->tableWidget->setItem(tot,1,new QTableWidgetItem(choose_name(s1,data[i])));
                    ui->tableWidget->setItem(tot,2,new QTableWidgetItem(choose_name(s2,data[i])));
                    ui->tableWidget->setItem(tot,3,new QTableWidgetItem("see more..."));
                    ui->tableWidget->setItem(tot,4,new QTableWidgetItem("推荐给好友"));
                    ui->tableWidget->setItem(tot,5,new QTableWidgetItem("购买成果"));
                    tot++;
                }
            }
        }
}

QString MainWindow::choose_name(QString s,inf_str a)
{
    if (s=="项目编号") return a.num;
    if (s=="项目名称") return a.name;
    if (s=="项目来源") return a.source;
    if (s=="项目类别") return a.typ;
    if (s=="承担单位") return a.company;
    if (s=="项目负责人") return a.leader;
    if (s=="项目经费") return a.money;
    if (s=="立题时间") return a.Start_Time;
    if (s=="实施情况") return a.State;
}

void MainWindow::OnItemClicked(QTableWidgetItem *Item)
{
    if (s_goal=="研发成果")
    {
        //QTextEdit *nt=new QTextEdit();
        QString ss1;ss1=Item->text();
        int u=Item->column(),v=Item->row();
        if (u==4) {sharedpro(mark[v]);return;}
        if (u==5)
        {
            GuestPayDialog* pGPD=new GuestPayDialog;
            pGPD->setUser(user);
            pGPD->show();
        }
        if (u!=3) return;
        //nt->clear();
        //nt->setPlainText(document(data[mark[v]]));
        //nt->show();
        toPDF(document(data[mark[v]]),data[mark[v]].name);
    }
    QString ss1;ss1=Item->text();
    int u=Item->column();
    if (u<3) return;int v=u;
    u=Item->row();
    int num=data.size(),pos=0;

    for (int i=0;i<num;i++)
        if (use[i])
        {
            if (u==0) {pos=i;break;}
            u--;
        }
    //QTextEdit *nt=new QTextEdit();
    //nt->clear();
    //nt->setPlainText(document(data[pos]));
    //nt->show();
    if (v==4) {sharedpro(pos);return;}
    toPDF(document(data[pos]),data[pos].name);

}

void MainWindow::toPDF(QString s,QString name)
{
    Dialog *dia=new Dialog();
    dia->show();
    dia->get_Text(s);
    dia->get_filename(name);
}

void MainWindow::on_pushButton_2_clicked()
{
    QVector< inf_str > tmp;tmp.clear();
    int num=data.size();
    for (int i=0;i<num;i++)
        if (use[i])
        {
            tmp.push_back(data[i]);
        }
    Money* tmp_m;
    tmp_m=new Money;
    tmp_m->get_inf(tmp);
    tmp_m->show();
}


void MainWindow::setUser(QString s)
{
    user=s;
    ui->label_user->setText(user);
}


void MainWindow::sharedpro(int o)
{
    Share_to_Friend* tmp;
    tmp=new Share_to_Friend;
    tmp->get_inf(user,data[o].num,data[o].name);
    tmp->work();
}

void MainWindow::on_pushButton_User_clicked()
{
    UserDialog* pU;pU=new UserDialog;
    pU->setUser(user);
    pU->show();
}

bool MainWindow::check(QString s)
{
    bool isTrue=false;
    QString path;
    path.clear();
    path+='.';path+='\\';path+='\\';
    path+=user;path+='\\';path+='\\';
    path+="visible.txt";

    QFile file(path);
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        QString t=in.readLine();
        if (t==s)
        {
            isTrue=true;
            break;
        }
    }
    return isTrue;
}

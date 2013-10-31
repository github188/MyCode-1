#include <QtCore/QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDir>
using namespace std;

QFile file("1.txt");
QFile findex("index.txt");
QTextStream in(&file);
QTextStream out(&findex);
QString num;
QString pp[20];

QTextStream ccout(stdout);

bool check(QString s)
{
    for (int i=0;i<=5;i++)
    {
        if (!(((s[i]>='0')&&(s[i]<='9'))||((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z')))) return false;
    }
    return true;
}

bool check1(QString s,int o)
{
    for (int i=0;i<pp[o].length();i++) if (pp[o][i]!=s[i]) return false;
    return true;
}

void Seg()
{
    while (true)
    {
        QString s=in.readLine();

        //if (s.length()==0) return;
        if (check1(s,0))
        {
            num.clear();
            for (int i=5;i<s.length();i++) num+=s[i];
            if (s[7]=='5')
            {
                int fu=1;
            }
            out<<num<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,1))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,2))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,3))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,4))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    if (num[7]!='5')
    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,5))
        {
            QString s1;
            s1.clear();
            for (int i=6;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,6))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,7))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,8))
        {
            QString s1;
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            out<<s1<<endl;
            break;
        }
    }

    QString tmp;
    QDir u;
    u.mkdir(num);

    while (true)
    {
        QString s=in.readLine();
        //if (s.length()==0) return;
        if (check1(s,9))
        {
            QString s1;
            QString path;path.clear();
            path+='.';path+='\\';path+='\\';
            path+=num;path+='\\';path+='\\';
            s1.clear();
            for (int i=5;i<s.length();i++) s1+=s[i];
            path+="yfcg.txt";

            QFile ofile(path);
            QTextStream fout(&ofile);
            if (!ofile.open(QIODevice::WriteOnly))
            {
                cerr<<"fuck"<<endl;
                return;
            }
            fout<<s1<<endl;
            while (true)
            {
                s1=in.readLine();
                //if (s1.length()==0) return;
                if (check1(s1,10))
                {
                    ofile.close();
                    tmp.clear();
                    for (int i=5;i<tmp.length();i++) tmp+=s1[i];
                    break;
                }
                fout<<s1<<endl;
            }

            check1(s,0);
            break;
        }
    }

    {
        QString s1;
        QString path;path.clear();
        path+='.';path+='\\';path+='\\';
        path+=num;path+='\\';path+='\\';
        path+="yyqk.txt";

        QFile ofile(path);
        QTextStream fout(&ofile);
        ofile.open(QIODevice::WriteOnly);
        fout<<tmp<<endl;
        while (true)
        {
            s1=in.readLine();
            //if (s1.length()==0) return;
            if (check1(s1,11))
            {
                ofile.close();
                tmp.clear();
                for (int i=5;i<tmp.length();i++) tmp+=s1[i];
                break;
            }
            fout<<s1<<endl;
        }

    }

    {
        QString s1;
        QString path;path.clear();
        path+='.';path+='\\';path+='\\';
        path+=num;path+='\\';path+='\\';
        path+="jjxy.txt";

        QFile ofile(path);
        QTextStream fout(&ofile);
        ofile.open(QIODevice::WriteOnly);
        fout<<tmp<<endl;
        while (true)
        {
            s1=in.readLine();
            //if (s1.length()==0) return;
            if (check1(s1,12))
            {
                ofile.close();
                tmp.clear();
                for (int i=5;i<tmp.length();i++) tmp+=s1[i];
                break;
            }
            fout<<s1<<endl;
        }
    }

    {
        QString s1;
        QString path;path.clear();
        path+='.';path+='\\';path+='\\';
        path+=num;path+='\\';path+='\\';
        path+="shxy.txt";

        QFile ofile(path);
        QTextStream fout(&ofile);
        ofile.open(QIODevice::WriteOnly);
        fout<<tmp<<endl;
        while (true)
        {
            s1=in.readLine();
            //if (s1.length()==0) return;
            if (check1(s1,13))
            {
                ofile.close();
                tmp.clear();
                for (int i=5;i<tmp.length();i++) tmp+=s1[i];
                break;
            }
            fout<<s1<<endl;
        }
    }

    {
        QString s1;
        QString path;path.clear();
        path+='.';path+='\\';path+='\\';
        path+=num;path+='\\';path+='\\';
        path+="yyqj.txt";

        QFile ofile(path);
        QTextStream fout(&ofile);
        ofile.open(QIODevice::WriteOnly);
        fout<<tmp<<endl;
        while (true)
        {
            s1.clear();
            s1=in.readLine();
            //if (s1.length()==0) {ofile.close();return;}
            if (check(s1))
            {
                ofile.close();
                break;
            }
            fout<<s1<<endl;
        }
    }

    Seg();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile ifile("2.txt");
    QTextStream iout(&ifile);
    ifile.open(QIODevice::ReadOnly);
    for (int i=0;i<14;i++) pp[i]=iout.readLine();
    ifile.close();

    file.open(QIODevice::ReadOnly);
    findex.open(QIODevice::WriteOnly);
    Seg();
    file.close();
    findex.close();

    return 0;
}

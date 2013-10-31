#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
ifstream fin;
ofstream fout;

char a[30][30];
bool f[30][30];
int tt;

int main()
{
    fin.open("B-large.in");
    fout.open("B-large.out");
    fin>>tt;
    for (int ttt=1;ttt<=tt;ttt++)
    {
        string s;
        char ans[101];int n=0;
        for (int i=0;i<30;i++) for (int j=0;j<30;j++) {a[i][j]=0;f[i][j]=false;}
        int c,d,l;
        fin>>c;
        for (int i=0;i<c;i++)
        {
            fin>>s;
            a[s[0]-'A'][s[1]-'A']=a[s[1]-'A'][s[0]-'A']=s[2];
        }
        fin>>d;
        for (int i=0;i<d;i++)
        {
            fin>>s;
            f[s[0]-'A'][s[1]-'A']=f[s[1]-'A'][s[0]-'A']=true;
        }
        fin>>l>>s;
        n=1;ans[1]=s[0];
        for (int j=1;j<l;j++)
        {
            n++;ans[n]=s[j];
            while ((n>1)&&(a[ans[n-1]-'A'][ans[n]-'A']!=0)) {ans[n-1]=a[ans[n-1]-'A'][ans[n]-'A'];n--;}
            for (int k=1;k<n;k++)
            if (f[ans[k]-'A'][ans[n]-'A']) {n=0;break;}
        }
        fout<<"Case #"<<ttt<<": [";
        if (n>0)
        {
                fout<<ans[1];
                for (int j=2;j<=n;j++) fout<<", "<<ans[j];
        }
        fout<<"]"<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}

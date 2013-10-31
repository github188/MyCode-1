#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
string s[14][2],st[14];
int a[14][2][14][2];
int f[20000][14][2],g[20000][14][2][2];
string ans;

bool cmp(string a,string b)
{
    if (a.length()>b.length()) return true;return false;
}

int min(int o,int p)
{
    if (o<p) return o;return p;
}

int calc(int o,int p,int x,int y)
{
    return min(a[o][p][x][y]-s[x][y].length(),a[x][y^1][o][p^1]-s[x][y^1].length());
}

void work(int st,int n,int x,int y)
{
    if (n!=1)
    {
        int u=g[st][x][y][0],v=g[st][x][y][1];
        int l=a[x][y][u][v]-s[u][v].length();
        for (int i=0;i<l;i++) ans+=s[x][y][i];
        work(st-(1<<x),n-1,u,v);
        for (int i=l-1;i>=0;i--) ans+=s[x][y][i];
        return;
    }
    ans+=s[x][y];
    int l=a[x][y][x][y^1]-s[x][y].length();
    for (int i=l-1;i>=0;i--) ans+=s[x][y][i];
}

int main()
{
    cin>>n;m=0;
    for (int i=0;i<n;i++) cin>>st[i];
    sort(st,st+n,cmp);
    for (int i=0;i<n;i++)
    {
        string t=st[i];
        bool check=false;
        for (int j=0;j<m;j++)
        if (t.length()<=s[j][0].length())
        {
            if (check) break;
            for (int k=0;k<=s[j][0].length()-t.length();k++)
            {
                check=true;
                for (int l=0;l<t.length();l++) if (s[j][0][k+l]!=t[l]) {check=false;break;}
                if (check) break;
            }
        }
        for (int j=0;j<m;j++)
        if (t.length()<=s[j][1].length())
        {
            if (check) break;
            for (int k=0;k<=s[j][1].length()-t.length();k++)
            {
                check=true;
                for (int l=0;l<t.length();l++) if (s[j][1][k+l]!=t[l]) {check=false;break;}
                if (check) break;
            }
        }
        if (!check)
        {
            s[m][0]=t;
            s[m][1]="";
            for (int j=0;j<t.length();j++) s[m][1]+=t[t.length()-1-j];
            m++;
        }
    }
    for (int i=0;i<m;i++)
     for (int j=0;j<2;j++)
      for (int k=0;k<m;k++)
       for (int l=0;l<2;l++)
       {
           bool check=false;
           for (int h=0;h<s[i][j].length();h++)
           {
               int t=h;
               while (t<s[i][j].length())
               {
                   if (s[i][j][t]==s[k][l][t-h]) {t++;}
                   else {break;}
               }
               if (t>=s[i][j].length()) {a[i][j][k][l]=h+s[k][l].length();check=true;break;}
           }
           if (!check) a[i][j][k][l]=s[i][j].length()+s[k][l].length();
       }

    for (int i=0;i<m;i++)
    {
        f[1<<i][i][0]=a[i][0][i][1];
        f[1<<i][i][1]=a[i][1][i][0];
        g[1<<i][i][0][0]=g[1<<i][i][1][0]=-1;
    }

    for (int i=1;i<(1<<m);i++)
      for (int j=0;j<m;j++)
       for (int k=0;k<2;k++)
        if (f[i][j][k]!=0)
        {
            for (int l=0;l<m;l++)
            if ((i&(1<<l))==0)
            {
                int st=(i|(1<<l));
                for (int h=0;h<2;h++)
                if ((f[st][l][h]==0)||(f[st][l][h]>f[i][j][k]+calc(l,h,j,k)*2))
                {
                    f[st][l][h]=f[i][j][k]+calc(l,h,j,k)*2;
                    g[st][l][h][0]=j;
                    g[st][l][h][1]=k;
                }
            }
        }

    int tmp,tmpx,tmpy;tmp=0;
    for (int i=0;i<m;i++)
     for (int j=0;j<2;j++)
      if ((f[(1<<m)-1][i][j]!=0)&&((f[(1<<m)-1][i][j]<tmp)||(tmp==0)))
      {
          tmp=f[(1<<m)-1][i][j];
          tmpx=i;tmpy=j;
      }
    ans="";
    work((1<<m)-1,m,tmpx,tmpy);
    cout<<ans<<endl;
    return 0;
}


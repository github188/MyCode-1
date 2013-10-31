#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int n,m;
long long k;
struct p
{
    int x,y;
};
int c[100][100],f[200];
long long g[300][300];
p a[200];

int min(int o,int p)
{
    if (o<p) return o;return p;
}

bool cmp(p a,p b)
{
    if (a.x<b.x) {return true;} return false;
}

long long work(int o)
{
    f[o]=0;
    memset(g,0,sizeof(g));
    g[0][1]=1;bool u=true;
    for (int i=1;i<=n+m-2;i++)
     if (f[i]<0)
     {
         for (int j=0;j<=n+m-2;j++)
         {
             if (j>0) g[i][j]+=g[i-1][j-1];
             if (g[i][j]>=k) g[i][j]=k;
             if (j<n+m-2) g[i][j]+=g[i-1][j+1];
             if (g[i][j]>=k) g[i][j]=k;
         }
     } else
     {
         if (f[i]==0)
         {
             for (int j=1;j<=n+m-2;j++) g[i][j]=g[i-1][j-1];
         } else
         {
             for (int j=0;j<n+m-2;j++) g[i][j]=g[i-1][j+1];
         }
     }
     f[o]=-1;
     return g[n+m-2][0];
}

int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<=n+m-2;i++) {a[i].x=n*m+100;a[i].y=i;f[i]=-1;}
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        {
            scanf("%d",&c[i][j]);
            a[i+j].x=min(a[i+j].x,c[i][j]);
        }

    sort(a,a+n+m-1,cmp);
    f[0]=0;f[n+m-2]=1;
    for (int i=0;i<=n+m-2;i++)
    if (f[a[i].y]<0)
    {
        long long tmp=work(a[i].y);
        if (tmp<k) {k-=tmp;f[a[i].y]=1;} else {f[a[i].y]=0;}
    }
    char ch[200][200];memset(ch,0,sizeof(ch));
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (f[i+j]==0) {ch[i][j]='(';} else {ch[i][j]=')';}

    for (int i=0;i<n;i++) printf("%s\n",ch[i]);

    return 0;
}

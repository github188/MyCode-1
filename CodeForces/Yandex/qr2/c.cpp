#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int v[5001],e[10010][4],ans[5001],f[5001][3],g[5001];
struct par
{
       int x,y;
} b[5001],a[5001][5001];
int n,uu;

bool comp(par a,par b)
{
     if (a.x<b.x) {return true;}return false;
}

void find(int o,int p)
{
     int j;
     j=v[o];
     while (j!=0)
     {
           if (e[j][0]!=p)
           {
                          f[e[j][0]][0]=o;
                          f[e[j][0]][1]=e[j][1];
                          f[e[j][0]][2]=e[j][2];
                          find(e[j][0],o);
           }
           j=e[j][3];
     }
}

void work(int o,int p,int time)
{
     int j;
     
     if (o==1)
     {
        for (int i=1;i<=g[o];i++)
        {
            ans[a[o][i].y]=time;uu++;
        }
        g[o]=0;
     } else
     {
           if (g[o]<=f[o][1]) 
           {
                              for (int i=1;i<=g[o];i++)
               {
                   g[p]++;
                   a[p][g[p]]=a[o][i];
               }
                              g[o]=0;
           }
           else
           {
               for (int i=1;i<=f[o][1];i++)
               {
                   g[p]++;
                   a[p][g[p]]=a[o][i];
               }
               for (int i=f[o][1]+1;i<=g[o];i++)
               {
                   a[o][i-f[o][1]]=a[o][i];
               }
               g[o]-=f[o][1];
           }
     }
     
     j=v[o];
     while (j!=0)
     {
           if (e[j][0]!=p)
           {
                 work(e[j][0],o,time);         
           }
           j=e[j][3];
     }
     if (g[o]>0) {sort(a[o]+1,a[o]+1+g[o],comp);}
}

int main()
{
    scanf("%d",&n);int m=0;
    for (int i=1;i<=n;i++) {scanf("%d",&b[i].x);b[i].y=i;}
    for (int i=1;i<n;i++)
    {
        int s,t,c;
        scanf("%d%d%d",&s,&t,&c);
        m++;
        e[m][0]=t;
        e[m][1]=c;
        e[m][2]=i;
        e[m][3]=v[s];
        v[s]=m;
        m++;
        e[m][0]=s;
        e[m][1]=c;
        e[m][2]=i;
        e[m][3]=v[t];
        v[t]=m;
    }
    find(1,0);
    
    for (int i=1;i<=n;i++) {g[i]=1;a[i][1]=b[i];}
    g[1]=0;uu=1;int i=1;
    while (uu<n)
    {
        work(1,0,i-1);
        i++;
    }
    
    for (int i=1;i<n;i++) {printf("%d ",ans[i]);}printf("%d\n",ans[n]);
    
    return 0;
}

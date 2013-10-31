#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct loc
{
       int x,y;
} b[50000];
int a[50000],ans[50000],heap[50001],c[50000],dir[50000][2],d[50000],f[50000];
int n,k,t,m;
int first;

bool comp(loc a,loc b)
{
     if ((a.y>b.y) || ((a.y==b.y) && (a.x<b.x))) {return true;}
     return false;
}

bool comp1(int a,int p)
{
     if (a<p) {return true;}
     return false;
}

void hiswap(int &a,int &b)
{
     int c=a;a=b;b=c;
}

void up(int o)
{
     int p=o/2;
     if (p>0)
     if (comp(b[heap[o]],b[heap[p]]))
     {
        hiswap(heap[o],heap[p]);
        d[heap[o]]=o;d[heap[p]]=p;
        up(p);
     }
}

void down(int o)
{
     int p=o*2;
     if ((p+1<=m+1) && (comp(b[heap[p+1]],b[heap[p]]))) {p++;}
     if ((p<=m+1) && (comp(b[heap[p]],b[heap[o]])))
     {
        hiswap(heap[o],heap[p]);
        d[heap[o]]=o;d[heap[p]]=p;
        down(p);       
     }
}

void change(int o,int p)
{
     c[0]++;
     c[c[0]]=b[o].x;
     b[o].y--;
     down(d[o]);
     f[o]=p;
     if (b[o].y==0)
     {
         if (dir[o][0]!=-1) dir[dir[o][0]][1]=dir[o][1];
         if (dir[o][1]!=n) dir[dir[o][1]][0]=dir[o][0];
         if (first==o) {first=dir[o][1];}
     }
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          scanf("%d%d",&n,&k);
          for (int i=0;i<n;i++) {scanf("%d",&a[i]);}
          sort(a,a+n);
          b[0].x=a[0];b[0].y=1;m=0;
          for (int i=1;i<n;i++)
          {
              if (a[i]==b[m].x) {b[m].y++;}
              else
              {
                  m++;
                  b[m].x=a[i];
                  b[m].y=1;
              }
          }
          
          bool legal=true;
          for (int i=0;i<=m;i++) {heap[i+1]=i;dir[i][0]=i-1;dir[i][1]=i+1;d[i]=i+1;f[i]=-1;up(i+1);}
          int u=n/k;int x=0;first = 0;
          for (int i=0;i<u;i++)
          {
              if (b[heap[1]].y>u-i) {legal=false;break;}
              c[0]=0;
              while (b[heap[1]].y==u-i) {change(heap[1],i);}
              int l=first;
              while (c[0]<k) {if ((f[l]<i)&&(b[l].y>0)) {change(l,i);}l=dir[l][1];}
              sort(c+1,c+1+c[0]);
              for (int j=1;j<=c[0];j++)
              {
                  ans[x]=c[j];
                  x++;
              }
          }
          
          if (!legal) {printf("-1\n");}
          else { for (int i=0;i<n-1;i++) {printf("%d ",ans[i]);}printf("%d\n",ans[n-1]); }
    }
    return 0;
}

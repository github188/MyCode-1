#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int d[501][501],q[501][501];
int a[501],b[501];
int n;
double dtot,qtot;

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
          int dd,qq;
          scanf("%d%d%d",&n,&dd,&qq);dtot=qtot=0;
          for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=q[i][j]=0;int u,v;
          for (int i=0;i<dd;i++) {int x,y,z; scanf("%d%d%d",&x,&y,&z);d[x][y]=z;u=x;v=y;}
          for (int i=0;i<qq;i++) {int x,y,z; scanf("%d%d%d",&x,&y,&z);q[x][y]=z;}
          
          a[0]=b[0]=1;
          a[1]=u;b[1]=v;
          for (int i=1;i<=n;i++)
          if ((i!=u)&&(i!=v))
          {
              int dsum,qsum,sdel,tdel;
              sdel=tdel=0;
              
              dsum=qsum=0;
              for (int j=1;j<=a[0];j++) {dsum+=d[i][b[j]];}
              for (int j=1;j<=a[0];j++) {qsum+=q[i][b[j]];}
              sdel=dsum-qsum;
              
              dsum=qsum=0;
              for (int j=1;j<=a[0];j++) {dsum+=d[i][a[j]];}
              for (int j=1;j<=a[0];j++) {qsum+=q[i][a[j]];}
              tdel=dsum-qsum;
              
              if (sdel>tdel) {a[0]++;a[a[0]]=i;} else {b[0]++;b[b[0]]=i;}
          }
          
          printf("%d",a[0]);
          sort(a+1,a+a[0]+1);
          for (int i=1;i<=a[0];i++) {printf(" %d",a[i]);}
          printf("\n");
    }
    return 0;
}

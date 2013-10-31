#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

int t,n,m,k,ansl;
int a[10001],b[300],f[300][300],c[10001],ans[301],d[301],g[301];

int main()
{
    srand(time(NULL));
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          scanf("%d%d%d",&n,&m,&k);
          for (int i=0;i<n;i++) {b[i]=0;}
          for (int i=1;i<=k;i++) {scanf("%d",&c[i]);a[i]=b[c[i]];b[c[i]]=i;}
          for (int i=0;i<n;i++) for (int j=0;j<n;j++) {f[i][j]=400000;}
          for (int i=0;i<m;i++)
          {
              int x,y,z;
              scanf("%d%d%d",&x,&y,&z);
              if (f[x][y]>z) {f[x][y]=f[y][x]=z;}
          }
          
          for (int k=0;k<n;k++)
           for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
             if (f[i][k]+f[k][j]<f[i][j]) {f[i][j]=f[i][k]+f[k][j];}
          d[0]=0;
          for (int i=1;i<n;i++) if (b[i]!=0) {d[0]++;d[d[0]]=i;}
          ansl=400*1000*400;
          
          for (int u=1;u<=300;u++)
          {
              bool h[301];
              g[0]=1;g[1]=0;int nn=d[0];
              for (int i=1;i<=d[0];i++) {h[i]=true;}
              for (int i=1;i<=d[0];i++)
              {
                  int r=rand()%nn;nn--;
                  for (int j=1;j<=d[0];j++)
                  if (h[j])
                  {
                           if (r!=0) {r--;} else {g[0]++;g[g[0]]=j;h[j]=false;break;}
                  }
              }
              int l=0;
              for (int i=2;i<=g[0];i++) {l+=f[d[g[i-1]]][d[g[i]]];}
              if (l<ansl) 
              {
                ansl=l;
                for (int i=0;i<=g[0];i++) {ans[i]=g[i];}
              }
          }
          int uuu=0;
          for (int i=1;i<=ans[0];i++)
          {
              while (b[d[ans[i]]]!=0)
              {
                    if (uuu!=0) {printf(" ");}
                    uuu++;
                    printf("%d",b[d[ans[i]]]);
                    b[d[ans[i]]]=a[b[d[ans[i]]]];
              }
          }
          printf("\n");
    }
    return 0;
}

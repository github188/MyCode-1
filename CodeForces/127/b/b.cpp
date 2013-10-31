#include<stdio.h>
#include<iostream>
using namespace std;
long long a[1000][1000],ah[1000],av[1000],sh[1001],sv[1001],sum[1001][1001];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++)
    {
        ah[i]=0;
        for (int j=0;j<m;j++) ah[i]+=a[i][j];
    }
    for (int i=0;i<m;i++)
    {
        av[i]=0;
        for (int j=0;j<n;j++) av[i]+=a[j][i];
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<=n;j++)
      {
          long long d=j-i;
          if (d<=0)
          {
              d=-d;
              long long two=2;
              d=d*two*two+two;
          } else
          {
              d--;
              long long two=2;
              d=d*two*two;
              d+=two;
          }
          d*=d;
          sh[j]+=ah[i]*d;
      }

    for (int i=0;i<m;i++)
      for (int j=0;j<=m;j++)
      {
          long long d=j-i;
          if (d<=0)
          {
              d=-d;
              long long two=2;
              d=d*two*two+two;
          } else
          {
              d--;
              long long two=2;
              d=d*two*two;
              d+=two;
          }
          d*=d;
          sv[j]+=av[i]*d;
      }

    for (int i=0;i<=n;i++)
     for (int j=0;j<=m;j++) sum[i][j]=sh[i]+sv[j];

    long long ans=sum[0][0];
    int x,y;x=y=0;
    for (int i=0;i<=n;i++)
     for (int j=0;j<=m;j++)
      if (sum[i][j]<ans)
      {
          ans=sum[i][j];
          x=i;
          y=j;
      }
    cout<<ans<<endl<<x<<" "<<y<<endl;
    return 0;
}

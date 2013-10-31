#include<stdio.h>
#define p 2012
int a[251],c[2001][2001],f[251][2001][2],h[2012][2012],ans[251];

int main()
{
    a[1]=1;
    for (int i=2;i<=250;i++) a[i]=a[i-1]+2;
    for (int i=0;i<p;i++)
      for (int j=0;j<p;j++) h[i][j]=i*j%p;
    c[0][0]=1;
    for (int i=1;i<=2000;i++)
      for (int j=0;j<=2000;j++)
      {
          c[i][j]=c[i-1][j];
          if (j>0) c[i][j]+=c[i-1][j-1];
          if (c[i][j]>=p) c[i][j]-=p;
      }

    f[1][0][0]=f[1][1][1]=1;
    for (int i=2;i<=250;i++)
      for (int j=0;j<=a[i];j++)
        for (int k=0;(k<=a[i]-j)&&(k<=a[i-1]);k++)
         {
             if (a[i]-k-1>=j)
             {
                 f[i][j][0]+=h[f[i-1][k][0]][c[a[i]-k-1][j]];
                 if (f[i][j][0]>=p) f[i][j][0]-=p;
                 if (a[i]-k-2>=j)
                 {
                     f[i][j][0]+=h[f[i-1][k][1]][c[a[i]-k-2][j]];
                     if (f[i][j][0]>=p) f[i][j][0]-=p;
                 }
             }
             if (j>0)
             {
                 f[i][j][1]+=h[f[i-1][k][0]][c[a[i]-k-1][j-1]];
                 if (f[i][j][1]>=p) f[i][j][1]-=p;
                 if (a[i]-k-1>=j)
                 {
                     f[i][j][1]+=h[f[i-1][k][1]][c[a[i]-k-2][j-1]];
                     if (f[i][j][1]>=p) f[i][j][1]-=p;
                 }
             }
         }
    for (int i=1;i<=250;i++)
    {
      for (int j=0;j<=a[i];j++)
      {
          ans[i]+=f[i][j][0];
          if (ans[i]>=p) ans[i]-=p;
          ans[i]+=f[i][j][1];
          if (ans[i]>=p) ans[i]-=p;
      }
      int tmp=1;
      for (int k=0;k<4;k++) tmp=tmp*ans[i]%p;
      ans[i]=tmp;
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n/2]);
    }
    return 0;
}

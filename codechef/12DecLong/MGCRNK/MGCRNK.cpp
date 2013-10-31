#include<stdio.h>
double f[150][150],a[150][150];
double minn=250000000;
int n;

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
          for (int j=1;j<=n;j++)
          {
              f[i][j]=-minn;
              scanf("%lf",&a[i][j]);
          }
        f[1][1]=0;
        for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
             if (i<n) f[i+1][j]=f[i+1][j]>f[i][j]+a[i+1][j]?f[i+1][j]:f[i][j]+a[i+1][j];
             if (j<n) f[i][j+1]=f[i][j+1]>f[i][j]+a[i][j+1]?f[i][j+1]:f[i][j]+a[i][j+1];
         }
        if (f[n][n]<0) printf("Bad Judges\n");
        else printf("%.7f\n",f[n][n]/(double)(n+n-3));
    }
    return 0;
}

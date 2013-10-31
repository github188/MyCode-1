#include<stdio.h>
double f[2001][2001],g[2001][2001],h[2001][2001];

int main()
{
    f[1][1]=0.5;
    h[1][1]=0.5;
    h[1][2]=0.25;
    f[1][0]=0.5;
    h[1][0]=0.25;
    for (int i=2;i<=1000;i++)
    {
      h[i][0]=h[i-1][0]/4.0;
      for (int j=1;j<=2000;j++)
      {
          //f[i][j]+=f[i-1][j]/4.0;
          f[i][j]+=h[i-1][j-1]/2.0;
          h[i][j]=h[i-1][j]/4.0;
          h[i][j]+=f[i][j]/2.0;
          h[i][j]+=f[i][j-1]/2.0;
          h[i][j]+=h[i-1][j-1]/4.0;
      }
    }
    for (int j=0;j<=2000;j++) g[1000][j]=f[1000][j];
    for (int i=999;i>=1;i--) for (int j=0;j<=2000;j++) g[i][j]=g[i+1][j]+f[i][j];

    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;scanf("%d",&n);
        double ans=0;
        for (int i=1;i<=n;i++)
        {
            double x,tmp;scanf("%lf",&x);
            int j=n-i+1;
            tmp=g[i/2+1][i]-g[(n+1)/2+1][i]+g[j/2+1][j]-g[(n+1)/2+1][j];
            ans+=x*tmp;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}

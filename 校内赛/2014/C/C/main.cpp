#include<stdio.h>
#include<math.h>
#include<string.h>
double f[101][101][1001];
int n,tt;
double ps, pr, pi, pu, pw, pd, pl;
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        scanf("%lf%lf%lf%lf%lf%lf%lf",&ps,&pr,&pi,&pu,&pw,&pd,&pl);
        int a=round(pi*1000.0),b=round(pu*1000.0),c=round(pd*1000.0);
        f[0][0][a]=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<=1000;k++)
                    if (f[i][j][k]!=0)
                {
                    double psun=(double)k/1000.0;
                    double pwin=psun*ps+(1-psun)*pr;
                    f[i+1][j][k]+=f[i][j][k]*pwin*(1-pw);
                    int k1=k+b;if (k1>1000) k1=1000;
                    f[i+1][j][k1]+=f[i][j][k]*pwin*pw;
                    if (j+1<n) f[i][j+1][k]+=f[i][j][k]*(1-pwin)*(1-pl);
                    int k2=k-c;if (k2<0) k2=0;
                    if (j+1<n) f[i][j+1][k2]+=f[i][j][k]*(1-pwin)*pl;
                }
        double ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<=1000;j++) ans+=f[n][i][j];
        printf("%.3f\n",ans);
    }
    return 0;
}

#include<stdio.h>
long long mod=1000000007;
long long f[1001][1001],a[1001];

int main()
{
    f[0][0]=1;
    for (int i=1;i<=1000;i++)
      for (int j=0;j<=i;j++)
      {
          f[i][j]=f[i-1][j];
          if (j>=0) f[i][j]+=f[i-1][j-1];
          f[i][j]%=mod;
      }
    a[0]=1;
    for (int i=1;i<=1000;i++) a[i]=(a[i-1]+a[i-1])%mod;
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        int n,x;scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&x);
        if (n&1)
        {
            printf("%d\n",a[n-1]);
        } else
        {
            long long ans=a[n-1];
            ans-=f[n-1][n/2];
            if (ans<0) ans+=mod;
            printf("%d\n",ans);
        }
    }
    return 0;
}

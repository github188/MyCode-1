#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
long long mod=1000000007;
long long c[10001][10001];
long long a[10001];
int n,k;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    c[0][0]=1;
    for (int i=1;i<=10000;i++)
      for (int j=0;j<=i;j++)
      {
          c[i][j]=c[i-1][j];
          if (j>0) c[i][j]+=c[i-1][j-1];
          if (c[i][j]>=mod) c[i][j]-=mod;
      }
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&k);
        for (int j=0;j<n;j++) scanf("%d",&a[j]);
        std::sort(a,a+n);
        long long ans=0;
        for (int j=k-1;j<n;j++) ans=(ans+a[j]*c[j][k-1])%mod;
        int s=ans;
        printf("Case #%d: %d\n",t,s);
    }
    return 0;
}

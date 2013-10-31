#include<stdio.h>
long long mod=1000000007;
long long a[1001][1001],b[1001];

int main()
{
    a[1][1]=1;
    for (int i=2;i<=1000;i++)
     for (int j=1;j<=i;j++)
     {
         long long jj=j;
         a[i][j]=(a[i-1][j-1]+a[i-1][j]*jj)%mod;
     }
    for (int i=1;i<=1000;i++)
    {
        b[i]=0;
        for (int j=1;j<=i;j++) b[i]=(b[i]+a[i][j])%mod;
    }
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n;
        scanf("%d",&n);
        printf("%I64d\n",b[n]);
    }
    return 0;
}

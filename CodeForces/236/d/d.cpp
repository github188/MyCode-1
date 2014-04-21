#include<stdio.h>
long long f[1001][1001],s[1001][1001];
long long p[1001];
long long mod=1000000007;

int main()
{
    p[1]=1;
    for (long long i=2;i<=1000;i++)
    {
        p[i]=p[i-1]*i%mod;
    }
    f[0][1]=f[0][0]=1;
    for (int i=1;i<=n;i++)
    return 0;
}

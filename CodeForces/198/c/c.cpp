#include<stdio.h>
long long d[2001],p[2001];
long long mod=1000000007,one=1;
long long n,ans,k,l,m;
bool f[2001],g[2001];

int main()
{
    scanf("%I64d",&k);
    for (int i=1;i<=k;i++)
    {
        int u;scanf("%d",&u);
        if (u>0) f[i]=true;if (u>0) g[u]=true;
    }
    for (int i=1;i<=k;i++)
    if (!f[i]) if (!g[i]) n++; else m++;
    d[0]=1;d[1]=0;d[2]=1;
    p[0]=1;p[1]=1;p[2]=2;
    for (long long i=3;i<=k;i++)
    {
        p[i]=p[i]*i%mod;
        d[i]=(i-one)*(d[i-1]+d[i-2])%mod;
    }
    long long u=n;if (m<u) u=m;
    for (long long n2=0;n2<=u;n2++)
    {
        long long tmp=1;
        tmp*=d[n-n2];
        long long c1=1,c2=1,tn=n,tm=m;
        for (long long j=0;j<n2;j++)
        {
            c1*=tn;c2*=tm;
            c1%=mod;c2%=mod;
            tn--;tm--;
        }
        tmp=(tmp*c1)%mod*c2%mod*c2%mod;
        ans=(ans+tmp)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}

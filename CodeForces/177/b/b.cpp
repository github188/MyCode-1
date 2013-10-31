#include<iostream>
using namespace std;
long long mod=1000000007;
long long a[10],f[10],c[10][10],g[10];
long long sum=0;

int main()
{
    long long ans=1;
    long long n,m;
    cin>>n>>m;
    for (long long i=1;i<=(n-m);i++) ans=(ans*(n-m))%mod;
    for (long long i=0;i<=m;i++)
    {
        f[i]=1;
        c[i][0]=1;
        for (long long j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    f[1]=1;f[2]=2;f[0]=1;g[1]=1;g[2]=3;g[0]=1;
    for (long long i=3;i<=m;i++)
    {
        long long one=1;g[i]=0;
        for (long long j=0;j<i;j++)
        {
            long long tmp=((((c[i-1][j]*g[j])%mod)*g[i-1-j])%mod)*(j+one)%mod;
            g[i]=(g[i]+tmp)%mod;
        }
    }
    long long one=1;
    ans=(ans*g[m-1]*m)%mod;
    cout<<ans<<endl;
    return 0;
}

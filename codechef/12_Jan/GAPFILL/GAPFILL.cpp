#include<iostream>
#include<stdio.h>
using namespace std;
long long ans;
long long mod=1000000007,two=2,ts=16,one=1,mod1=500000003;
void pow(long long o)
{
    if (o==1) return;
    pow(o>>1);
    ans=(ans*ans)%mod;
    if ((o&1)!=0)
    {
        ans=(ans*ts)%mod;
    }
}

int main()
{
    int tt;
    cin>>tt;
    long long n,m;
    while (tt>0)
    {
        tt--;
        cin>>n>>m;
        //scanf("%lld%lld",&n,&m);
        if (n>m)
        {
            long long k=n;n=m;m=k;
        }
        if (n==1)
        {
            cout<<2<<endl;
            continue;
        }
        ts=2;
        ans=2;
        long long u;
        u=(n>>1);
        u=(u%mod1);
        u*=((m>>1)%mod1);
        u%=mod1;
        u*=4;
        u%=mod1;
        pow(u);
        if ((n&1)+(m&1)>0) {ans=(ans<<1)%mod;}
        cout<<ans<<endl;
        //printf("%lld\n",ans);
    }
    return 0;
}

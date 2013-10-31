#include<iostream>
using namespace std;
int t,n;
long long v,p0,p1,q0,q1,a0,a1,b0,b1,c0,c1,m0,m1;
long long ans=1;
long long mod=1000000007;
long long phimod=1000000006;
long long one=1;

void work(long long o,long long p)
{
    if (v!=0)
    {
        long long l=(o*m1+p)%phimod;
        ans=(ans*l)%phimod;
    } else
    {
        long long l=(o*m1+p);
        if (l==0) ans=0;
    }
}

long long mul(long long v,long long o)
{
    if (o==0) return 1;
    if (o==1) return v;
    long long ans=mul(v,o>>1);
    ans=(ans*ans)%mod;
    if (o&one) ans=(ans*v)%mod;
    return ans;
}

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>v>>n;
        v%=mod;
        cin>>p0>>p1>>a0>>b0>>c0>>m0;
        a0=(a0*a0)%m0;
        cin>>q0>>q1>>a1>>b1>>c1>>m1;
        a1=(a1*a1)%m1;
        ans=1;
        work(p0,q0);work(p1,q1);
        p0%=m0;p1%=m0;
        q0%=m1;q1%=m1;
        for (int i=2;i<n;i++)
        {
            long long tmp;
            tmp=((a0*p1+b0*p0)+c0)%m0;
            p0=p1;p1=tmp;
            tmp=((a1*q1+b1*q0)+c1)%m1;
            q0=q1;q1=tmp;
            work(p1,q1);
        }
        cout<<mul(v,ans)<<endl;
    }
    return 0;
}

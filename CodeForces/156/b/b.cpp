#include<iostream>
using namespace std;
long long n,x,y,c,t;
long long two=2,one=1;

long long f(long long x,long long y,long long t)
{
    long long ans=0;
    if ((t==0)||(x*y==0)) return 0;
    if (x+y<=t) return x*y;
    ans=(one+t)*t/two;
    if (t>x) ans=ans-(one+t-x)*(t-x)/two;
    if (t>y) ans=ans-(one+t-y)*(t-y)/two;
    return ans;
}

int main()
{
    cin>>n>>x>>y>>c;
    long long l=0,r=n+n+n;
    while (l<r)
    {
        long long mid=(l+r)/two;
        long long tmp=1;
        tmp+=f(x-one,y,mid)+f(n-x+one,y-one,mid)+f(n-x,n-y+one,mid)+f(x,n-y,mid);
        if (tmp>=c) r=mid; else l=mid+one;
    }
    cout<<l<<endl;
    return 0;
}

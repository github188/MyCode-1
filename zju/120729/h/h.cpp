#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

unsigned long long work(unsigned long long n)
{
    unsigned long long ans=0;
    if (n<0) return 0;
    unsigned long long i=1,eight=8,two=2,one=1,four=4;
    unsigned long long m=n/eight,d=0;
    ans=1;
    unsigned long long l=0,r=3037000499;
    while (l<r)
    {
        unsigned long long mid=(l+r)/two+one;
        if (mid*(mid+one)<=m*two) {l=mid;} else {r=mid-one;}
    }
    i=l;
    ans+=i+(i*(i+one)*two);
    d=(i*(i+one)*four)+(i+one)*four;
    if (n>=d) ans+=n-d+one;
    return ans;
}

int main()
{
   unsigned long long n,m,one=1;
    while (cin>>n>>m)
    {
        unsigned long long ans=work(m);
        if (n>0) ans-=work(n-one);
        cout<<ans<<endl;
    }
    return 0;
}

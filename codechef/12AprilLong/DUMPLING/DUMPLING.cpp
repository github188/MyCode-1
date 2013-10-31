#include<iostream>
using namespace std;
long long a,b,c,d,k;

long long gcd(long long a,long long b)
{
    if (a==0) return b;return gcd(b%a,a);
}

int main()
{
    int t;
    cin>>t;
    while (t>0)
    {
        t--;
        cin>>a>>b>>c>>d>>k;
        if (a>b) {long long e=a;a=b;b=e;}
        if (c>d) {long long e=c;c=d;d=e;}
        long long u=gcd(a,b),v=gcd(c,d);
        if (u>v) {long long e=v;v=u;u=e;}
        u/=gcd(u,v);
        long long f=k/u;f/=v;
        f+=f;f++;
        cout<<f<<endl;
    }
    return 0;
}

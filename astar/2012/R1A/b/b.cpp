#include<iostream>
using namespace std;
long long one=1;

long long work(long long a,long long x)
{
    if (x>a) return 0;
    long long p=1,u=0,xx=x;
    long long ten=10;
    while (xx!=0)
    {
        p=p*ten;
        xx/=ten;
    }
    long long ans=a/p;
    if (a%p>=x) ans++;
    return ans;
}

int main()
{
    int tt;
    cin>>tt;
    while (tt>0)
    {
        tt--;
        long long x,a,b,ans;
        cin>>x>>a>>b;
        if (x>b) {cout<<0<<endl;continue;}
        ans=work(b,x)-work(a-one,x);
        cout<<ans<<endl;
    }
    return 0;
}

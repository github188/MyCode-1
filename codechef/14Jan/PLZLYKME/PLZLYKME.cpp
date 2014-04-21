#include<iostream>
using namespace std;
long long l,d,s,c;

long long work(long long d,long long s,long long c)
{
    if (d==0) return 1;
    if (d==1) return c;
    long long ans=work(d>>1,s,c);
    if (ans*s>=l) return ans;
    ans*=ans;
    if (ans*s>=l) return ans;
    if (d&1) ans*=c;
    return ans;
}

int main()
{
    int t;cin>>t;
    while (t--)
    {
        cin>>l>>d>>s>>c;
        if (l>work(d-1,s,c+1)*s) cout<<"DEAD AND ROTTING"<<endl;
        else cout<<"ALIVE AND KICKING"<<endl;
    }
    return 0;
}

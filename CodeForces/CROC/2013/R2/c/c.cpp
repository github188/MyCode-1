#include<iostream>
using namespace std;
long long ans=0;
long long n;
long long three=3,two=2,one=1;
long long prime[1000000];
bool g[10000001];
int main()
{
    cin>>n;
    if ((n%three)>0) {cout<<0<<endl;return 0;}n/=three;
    if ((n%two)>0) {cout<<0<<endl;return 0;}
    long long l=1;
    while (l*l*l<=n) l++;l--;long long ll=l;
    /*
    for (int i=2;i<=10000000;i++)
    if (!g[i])
    {
        prime[++prime[0]]=i;int j=i;
        while (j<=10000000)
        {
            g[j]=true;j+=i;
        }
    }
    //cout<<prime[0]<<endl;
    */
    while (l>1)
    {
        if ((n%l)!=0)
        {
            l--;continue;
        }
        long long o=n/l;
        if ((l&1)&&(o&one)) continue;
        long long min=l;
        long long ll=1,rr=10000000;
        while (ll!=rr)
        {
            long long mid=(ll+rr)/two+one;
            if (mid*mid>o) rr=mid; else ll=mid;
        }
        l--;
    }
    l=ll;
    if ((l*l*l==n)&&(l&1)) ans++;
    cout<<ans<<endl;
    return 0;
}

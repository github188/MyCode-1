//source here
#include<iostream>
using namespace std;
long long mod=1000000007;

int main()
{
    int tt;cin>>tt;
    for (int t=1;t<=tt;t++)
    {
        long long n,n1,k,one=1,two=2,three=3;
        cin>>n;
        n1=(n+one)%mod;
        if (n%two==0) k=(n/two%mod)*((n+one)%mod)%mod;
        else k=(n%mod)*((n+one)/two%mod)%mod;
        long long ans=k*k%mod*k%mod;
        long long temp=0;
        temp=(n1*n1%mod*k%mod-n1*n1%mod*n1%mod)*(n%mod)%mod*three%mod;
        temp=(temp+(-two*n1%mod*k%mod+n1*n1%mod*three%mod)*k%mod*three%mod)%mod;
        temp=(temp+(k-three*n1%mod)*k%mod*(two*(n%mod)%mod+one)%mod)%mod;
        temp=(temp+k*k%mod*three%mod)%mod;
        if (temp<0) temp+=mod;
        ans-=temp;
        if (ans<0) ans+=mod;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}

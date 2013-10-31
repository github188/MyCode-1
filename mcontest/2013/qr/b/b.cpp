#include<iostream>
using namespace std;
long long n,m,k,t,tt;

int main()
{
    cin>>tt;
    for (int t=1;t<=tt;t++)
    {
        cin>>n>>m>>k;
        if (m<n) {long long p=n;n=m;m=p;}
        long long ans=0,one=1,two=2;
        for (long long i=2;i<=n;i++)
        if (k/i<=m)
        {
            long long j=k/i;
            long long ans1=i*j*(i-one)*(j-one)/(two*two);
            long long kk=k-i*j;
            if (j+one<=m) ans1+=(kk-one)*kk/two*j;
            else ans1+=(kk-one)*kk/two*i;
            ans=ans1>ans?ans1:ans;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

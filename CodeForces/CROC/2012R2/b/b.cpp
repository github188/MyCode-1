#include<string.h>
#include<iostream>
using namespace std;
long long ans,mod;
int k;
string s,t;

int main()
{
    cin>>s>>t>>k;
    mod=1000000007;
    ans=0;
    long long m=s.length();
    string ss=s+s;
    long long a,b,c,d;
    a=0;c=0;b=1;d=m-1;
    long long m1=m-1,m2=m-2;
    for (int tt=2;tt<=k;tt++)
    {
        long long tmp=(c*m1+d*m2)%mod;
        c=d;d=tmp;
        tmp=(a*m1+b*m2)%mod;
        a=b;b=tmp;
    }
    if ((s==t)&&(k>=1)) ans=d;
    //long long m1=m-1;
    for (int i=1;i<m;i++)
    {
        bool check=false;
        for (int j=0;j<m;j++)
        if (t[j]!=ss[i+j]) {check=true;break;}
        if (!check)
        {
            ans=(ans+b)%mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}

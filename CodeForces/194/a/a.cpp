#include<iostream>
using namespace std;

int main()
{
    long long n=0,ans=0,three=3,mod=0,one=1,zero=0;
    cin>>n;
    mod=n%three;
    if (mod!=0) {ans=n/three+one;}
    else
    {
        while (n%three==zero) n/=three;
        ans=n/three+one;
    }
    cout<<ans<<endl;
}

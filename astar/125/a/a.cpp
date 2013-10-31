#include<iostream>
using namespace std;

long long k,b,n,t;

int main()
{
    cin>>k>>b>>n>>t;
    long long a=1,m=0;
    while (a*k+b<=t)
    {
        a=a*k+b;
        m++;
    }
    n-=m;
    if (n<0) n=0;
    cout<<n<<endl;
    return 0;
}

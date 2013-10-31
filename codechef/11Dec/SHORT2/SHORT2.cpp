#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
long long n;

long long work1(long long p)
{
    double pp=p+1;
    long long hp=sqrt(pp)+1;
    long long ans=0;
    for (int i=2;i<=hp;i++)
    {
    }
    return ans;
}

int main()
{
    int tt;scanf("%d\n",&tt);
    while (tt>0)
    {
        long long ans=0;
        cin>>n;
        ans+=work1(n);
        cout<<ans<<endl;
    }

    return 0;
}

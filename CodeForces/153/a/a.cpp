#include<stdio.h>
#include<iostream>
using namespace std;
int a[100000];
int n,d;
long long ans=0;

int main()
{
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int t=2;
    for (int i=0;i<=n-3;i++)
    {
        while ((t+1<n)&&(a[t+1]-a[i]<=d)) t++;
        if ((a[t]-a[i]<=d)&&(t-i>=2))
        {
            long long u=t-i,v=u-1,two=2;
            ans+=u*v/two;
        }
    }
    cout<<ans<<endl;
    return 0;
}

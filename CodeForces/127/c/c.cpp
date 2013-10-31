#include<stdio.h>
#include<iostream>
using namespace std;
long long a[100000],l[2][100000],r[2][100000];
int n;

long long max(long long o,long long p)
{
    if (o>p) return o;
    return p;
}

int main()
{
    scanf("%d",&n);
    long long one=1,two=2;
    for (int i=0;i<n-1;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) l[0][i]=l[1][i]=r[0][i]=r[1][i]=0;
    for (int i=1;i<n;i++)
    {
        l[0][i]=max(l[0][i-1],l[1][i-1])+two*((a[i-1]-one)/two)+one;
        if (a[i-1]>one) l[1][i]=l[1][i-1]+a[i-1]-(a[i-1]&one);
    }
    for (int i=n-2;i>=0;i--)
    {
        r[0][i]=max(r[0][i+1],r[1][i+1])+two*((a[i]-one)/two)+one;
        if (a[i]>one) r[1][i]=r[1][i+1]+a[i]-(a[i]&one);
    }
    long long ans=0;
    for (int i=0;i<n;i++) ans=max(ans,max(l[1][i]+max(r[0][i],r[1][i]),r[1][i]+max(l[0][i],l[1][i])));
    cout<<ans<<endl;
    return 0;
}

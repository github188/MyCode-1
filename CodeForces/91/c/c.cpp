#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long a[10000];
int num;

bool check(int m)
{
    while (m>0)
    {
        if (((m%10)!=4)&&((m%10)!=7)) return false;
        m/=10;
    }
    return true;
}

int work(int n,long long f,int base)
{
    int b[20];
    f--;
    for (int i=1;i<=n;i++) {b[i]=i;}
    for (int i=n-1;i>0;i--)
    {
        long long u=1;
        for (long long j=1;j<=i;j++) {u=u*j;}
        long long v=f/u;f=f%u;
        int c=b[n-i];b[n-i]=b[n-i+v];b[n-i+v]=c;
        sort(b+n-i+1,b+1+n);
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    if (check(i+base)&check(b[i]+base)) ans++;
    return ans;
}

int main()
{
    num=1;a[0]=0;
    for (int i=1;i<=9;i++)
    {
        long long fou=4,thr=3,ten=10,base=0;
        for (int j=1;j<=i;j++) {base=base*ten+fou;}
        for (int j=0;j<(1<<i);j++)
        {
            long long ans=base,b=j,rk=1;
            while (b!=0)
            {
                if ((b&1)==1) {ans+=rk*thr;}
                rk=rk*ten;
                b=b/2;
            }
            a[num]=ans;num++;
        }
    }

    long long fou=4,thr=3,ten=10,base=0,ans=0,one=1;
    for (int j=1;j<=10;j++) {base=base*ten+fou;}
    a[num]=base;num++;

    long long n,k,mul,dig;
    cin>>n>>k;mul=1;dig=1;
    while (mul<k) {dig++;mul*=dig;}
    if (dig>n) {printf("-1\n");return 0;}
    long long pos=n-dig;
    for (int i=0;i<num;i++)
    if (a[i]>pos)
    {
        ans=i-1;
        if (a[i]>n) {cout<<ans<<endl;return 0;}
        ans+=work(dig,k,pos);
        break;
    }

    cout<<ans<<endl;
    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;

long long a[10000];
int num;

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

    long long l,r;
    cin>>l>>r;
    for (int i=1;i<num;i++)
    {
        if ((a[i-1]<l)&&(l<=a[i]))
        {
            if ((a[i-1]<r)&&(r<=a[i])) {ans=(r-l+one)*a[i];break;}
            ans+=(a[i]-l+one)*a[i];
        }
        if ((l<a[i-1])&&(a[i]<=r)) {ans+=(a[i]-a[i-1])*a[i];if (r==a[i]) break;}
        if ((a[i-1]<r)&&(r<=a[i])) {ans+=(r-a[i-1])*a[i];}
    }
    cout<<ans<<endl;

    return 0;
}

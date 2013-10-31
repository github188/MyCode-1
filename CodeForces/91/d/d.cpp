#include<stdio.h>
#include<iostream>
using namespace std;

long long a[1000000];
int num,n,k;
long long a[100000][2];

int main()
{
    num=1;
    for (int i=1;i<=18;i++)
    {
        long long fou=4,thr=3,ten=10,base=0,two=2;
        for (int j=1;j<=i;j++) {base=base*ten+fou;}
        for (int j=0;j<(1<<i);j++)
        {
            long long ans=base,b=j,rk=1;
            while (b!=0)
            {
                if ((b&1)==1) {ans+=rk*thr;}
                rk=rk*ten;
                b=b/two;
            }
            a[num]=ans;num++;
        }
    }
    num--;
    cin>>n>>k;long long min=-1;
    for (i=1;i<=n;i++) {scanf("%I64d%I64d",&a[i][0],&a[i][1]);if (i==1) {min=a[i][1]-a[i][0];}min=min1(min,a[i][1]-a[i][0]);}

    return 0;
}

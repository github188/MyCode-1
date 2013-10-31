#include<stdio.h>
#include<iostream>
using namespace std;
int t,s,d;
long long a[60000];

int main()
{
    a[0]=3;
    a[1]=2;
    a[2]=5;
    a[3]=8;
    int h=1;
    while (a[a[0]]<=222222222)
    {
        a[++a[0]]=a[h]*10+2;
        a[++a[0]]=a[h]*10+5;
        a[++a[0]]=a[h]*10+8;
        h++;
    }
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d%d",&s,&d);
        long long ans=0;
        for (int i=1;i<a[0];i++)
        {
            long long x=a[i]+1,y=a[i+1]-1,delta=a[i+1]-a[i],one=1;
            if (s>x) x=s;
            if (d<y) y=d;
            if (y>=x) ans+=(y-x+one)*delta;
        }
        cout<<ans<<endl;
    }
    return 0;
}

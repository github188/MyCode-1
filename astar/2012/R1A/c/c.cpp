#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct seg
{
    int l,r;
};
seg a[100000];
int b[200000];
int n,h,t;
long long ans=0;

bool cmp(seg a,seg b)
{
    if (a.l<b.l) return true;
    return false;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i].l,&a[i].r);
    sort(a,a+n,cmp);
    h=0;t=0;
    b[0]=0;
    for (int i=1;i<n;i++)
    {
        while ((h<=t)&&(a[b[h]].r<=a[i].l)) h++;
        if (h>t)
        {
            h++;
            b[h]=i;
            continue;
        }
        for (int j=h;j<=t;j++)
        {
            long long e[4];
            e[0]=a[i].l;
            e[1]=a[i].r;
            e[2]=a[b[j]].l;
            e[3]=a[b[j]].r;
            sort(e,e+4);
            if (ans<(e[3]-e[0])*(e[2]-e[1])) ans=(e[3]-e[0])*(e[2]-e[1]);
        }
        if (a[i].r>a[b[t]].r)
        {
            t++;
            b[t]=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}

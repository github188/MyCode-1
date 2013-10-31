#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct rep
{
     double l,w;  
};

rep a[2000];
double b[2000],e[2000];
int n,t1,tt;
double s,r,x,t;

bool comp(rep a,rep b)
{
     if (a.w<b.w) {return true;} return false;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&tt);
    for (int t1=1;t1<=tt;t1++)
    {
        scanf("%lf%lf%lf%lf%d",&x,&s,&r,&t,&n);
        a[0].l=x;a[0].w=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&b[i],&e[i],&a[i].w);
            a[i].l=e[i]-b[i];
            a[0].l-=a[i].l;
        }
        sort(a,a+n+1,comp);
        double ans=0;double delta=1e-10;
        for (int i=0;i<=n;i++)
        {
            if (t>0)
            {
               double time=a[i].l/(r+a[i].w);
               if (time<=t) {ans+=time;t-=time;} else
               {
                   ans=ans+t;
                   a[i].l=a[i].l-t*(r+a[i].w);
                   t=0;
                   ans=ans+a[i].l/(s+a[i].w);         
               }
            } else {ans=ans+a[i].l/(s+a[i].w);}
        }
        printf("Case #%d: %.7f\n",t1,ans);
    }
    return 0;
}

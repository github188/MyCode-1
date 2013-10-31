#include<stdio.h>
long long a[30],b[30],k[30];
int p[30];
int u,n,r;
long long ans=0;
long long rr;

void check()
{
    long long ans1=0;
    for (int i=0;i<n;i++) ans1+=a[i]*k[i];
    if (ans1>ans) ans=ans1;
}

void work(int o,int u)
{
    long long aa[30];
    if ((u&1)==0) check();
    if (u==0) return;
    if (o==0)
    {
        for (int i=0;i<n;i++) {a[i]^=b[i];}
        work(1,u-1);
        for (int i=0;i<n;i++) {a[i]^=b[i];}
    }
    else
    {
        for (int i=0;i<n;i++) aa[i]=a[i];
        for (int i=0;i<n;i++) a[i]=aa[p[i]-1]+rr;
        work(0,u-1);
        work(1,u-1);
        for (int i=0;i<n;i++) a[i]=aa[i];
    }
}

int main()
{
    ans=-200000000;long long tmp=1000000;ans*=tmp;
    scanf("%d%d%d",&n,&u,&r);rr=r;
    for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
    for (int i=0;i<n;i++) scanf("%I64d",&b[i]);
    for (int i=0;i<n;i++) scanf("%I64d",&k[i]);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    work(0,u);
    work(1,u);
    printf("%I64d\n",ans);
    return 0;
}

#include<stdio.h>
int a[(1<<20)],b[(1<<20)];
long long f[21],g[21];

void sort(int n,int o)
{
    if (n==0) return;
    sort(n-1,o);
    sort(n-1,o+(1<<(n-1)));
    int x=o,y=o+(1<<(n-1)),z=0;
    long long sum=0,rep=0;
    while ((x<o+(1<<(n-1)))&&(y<o+(1<<(n-1))+(1<<(n-1))))
    {
        if (b[x]<=b[y])
        {
            if ((b[x]==b[x-1])&&(rep>0)&&(x>o)) rep++; else if (b[x]==b[y]) rep=1; else rep=0;
            a[z++]=b[x++];
        }
        else
        {
            if (b[y]==b[x-1]) sum+=rep;
            f[n]+=(long long)(o+(1<<(n-1))-x);
            a[z++]=b[y++];
        }
    }
    while (x<o+(1<<(n-1))) a[z++]=b[x++];
    while (y<o+(1<<(n-1))+(1<<(n-1)))
    {
        if (b[y]==b[x-1]) sum+=rep;
        a[z++]=b[y++];
    }
    for (int i=0;i<z;i++) b[i+o]=a[i];
    long long tmp=1;tmp<<=(2*n-2);
    g[n]=g[n]+tmp-sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<(1<<n);i++) scanf("%d",&b[i]);
    sort(n,0);
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int x;scanf("%d",&x);
        for (int i=1;i<=x;i++)f[i]=g[i]-f[i];
        long long ans=0;
        for (int i=0;i<=n;i++) ans+=f[i];
        printf("%I64d\n",ans);
    }
    return 0;
}

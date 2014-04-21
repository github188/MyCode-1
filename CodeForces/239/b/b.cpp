#include<stdio.h>
long long a[1001];
int p[1001];
long long mod=1000000007;

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    a[0]=0;
    long long two=2;
    for (int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-1]+two-a[p[i]-1];
        if (a[i]<0) a[i]+=mod;
        a[i]%=mod;
    }
    int ans=a[n];
    printf("%d\n",ans);
    return 0;
}

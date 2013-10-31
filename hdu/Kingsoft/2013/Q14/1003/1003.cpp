#include<stdio.h>
long long f[1000001],g[1000001];
int prime[1000];
bool t[1001];

int main()
{
    for (int i=2;i<=1000;i++)
    if (!t[i])
    {
        prime[++prime[0]]=i;
        int j=i;
        while (j<=1000)
        {
            t[i]=true;
            j+=i;
        }
    }
    f[1]=2;g[1]=2;
    for (int i=2;i<=1000000;i++)
    {
        int k=i;f[i]=i;
        for (int j=1;j<=prime[0] && prime[j]*prime[j]<=i && k>1;j++)
        if ((k%prime[j])==0)
        {
            int l=0;
            while ((k%prime[j])==0) {k/=prime[j];l++;}
            if (l==1) f[i]=f[i/prime[j]]*(long long)(prime[j]-1);
            else f[i]=f[i/prime[j]]*(long long)prime[j];
            k=1;
            break;
        }
        if (k!=1) f[i]=f[i]/(long long)k*(long long)(k-1);
        g[i]=g[i-1]+f[i];
    }
    int n;
    long long one=1;
    while (scanf("%d",&n)!=EOF) printf("%I64d\n",g[n]+g[n]-one);
    return 0;
}

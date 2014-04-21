#include<stdio.h>
int used[100000];
int prime[100000];
int a[5000],b[5000],g[5000];

int gcd(int o,int p)
{
    if (o<p) {int q=o;o=p;p=q;}
    if (p==0) return o;
    return gcd(p,o%p);
}

int AddPrime(int val)
{
    int ans=0;
    for (int i=1;(i<prime[0])&&(prime[i]*prime[i]<=val);i++)
    if ((val%prime[i])==0)
    {
        int tmp=prime[i],num=1;
        if (prime[i]<0) tmp=-tmp,num=-num;
        while ((val%tmp)==0)
        {
            ans+=num;
            val/=tmp;
        }
    }
    if (val>1)
    {
        if (used[val]==0) ans++;
        else ans--;
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<m;i++) {scanf("%d",&b[i]);used[b[i]]=-1;}
    for (int i=2;i<100000;i++)
    if (used[i]<1)
    {
        prime[++prime[0]]=i;
        if (used[i]!=0) prime[prime[0]]*=-1;
        int j=i+i;
        while (j<100000)
        {
            used[j]=1;j+=i;
        }
    }
    g[0]=a[0];
    for (int i=1;i<n;i++) g[i]=gcd(g[i-1],a[i]);
    int ans=0;
    for (int i=0;i<n;i++) ans+=AddPrime(a[i]);
    int max_g=0;
    for (int i=n-1;i>=0;i--)
    {
        int tmp=AddPrime(g[i]);
        if (tmp<max_g)
        {
            ans+=(max_g-tmp)*(i+1);
            max_g=tmp;
        }
    }
    printf("%d\n",ans);
    return 0;
}

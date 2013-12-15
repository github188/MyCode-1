#include<stdio.h>
int e[10000][2],v[5001],a[5001];
bool b[5001];
long long f[5001],f1[5001];
long long mod=1000000007;
int n,tot;
long long ans=0,u=0,one=1;

void work(int o,int p)
{
    int q=v[o];
    b[o]=true;
    if (o!=a[p])
    {
        f[p]=(f[p]+(u*f[o]*f1[o]%mod))%mod;
        u=(u*(f[o]*f1[o]%mod+))%mod;
    }
    while (q>0)
    {
        if (e[q][0]<p) work(e[q][0],p);
        q=e[q][1];
    }
}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (int i=0;i<=n;i++) v[i]=0;
        tot=0;
        for (int i=1;i<n;i++)
        {
            int x;scanf("%d",&x);a[i]=x;
            tot++;
            e[tot][0]=i;
            e[tot][1]=v[x];
            v[x]=tot;
        }
        ans=1;f[0]=1;f1[0]=1;
        for (int i=1;i<n;i++)
        {
            f[i]=0;u=1;f1[i]=0;
            for (int j=a[i]+1;j<i;j++) b[j]=false;
            work(a[i],i);
            long long g=0;
            for (int j=a[i]+1;j<i;j++)
            {
                long long h=f[j]-f[a[j]];
                if (h<0) h+=mod;
                g=(g*h)%mod;
            }
            ans=(ans+f[i]*f1[i]%mod)%mod;
            if (ans<0) ans+=mod;
        }
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}

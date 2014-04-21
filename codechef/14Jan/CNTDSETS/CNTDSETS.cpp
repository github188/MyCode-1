#include<stdio.h>

long long maxn=1000000007,maxn1=maxn-1;
long long c[1001][1001];

long long pow(long long a,long long b,long long m)
{
    if (b==0) return 1;
    if (b==1) return a;
    long long ans=pow(a,b>>1,m);
    ans=ans*ans%m;
    if (b&1) ans=a*ans%m;
    return ans;
}

long long work(long long n,long long d)
{
    if (d==0) return 0;
    long long ans=0;
    long long sym=1;
    for (int i=0;i<=n;i++)
    {
        long long sum=0;
        sum=pow(2,(pow(d+1,n-i,maxn1)*pow(d,i,maxn1))%maxn1,maxn);
        sum-=(pow(d+1,n-i,maxn)*pow(d,i,maxn))%maxn+1;if (sum<0) sum+=maxn;
        sum=sum*c[n][i]%maxn;
        ans+=sym*sum;
        if (ans<0) ans+=maxn;
        ans=ans%maxn;
        sym=-sym;
    }
    return ans;
}

int main()
{
    c[0][0]=1;
    for (int i=1;i<=1000;i++)
        for (int j=0;j<=i;j++)
        {
            c[i][j]=c[i-1][j];
            if (j>0) c[i][j]+=c[i-1][j-1];
            c[i][j]%=maxn;
        }
    int t;scanf("%d",&t);
    while (t--)
    {
        long long n,d;
        scanf("%lld%lld",&n,&d);
        long long ans=work(n,d)-work(n,d-1);
        if (ans<0) ans+=maxn;
        printf("%lld\n",ans);
    }
    return 0;
}

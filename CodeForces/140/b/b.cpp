#include<stdio.h>
#include<algorithm>
using namespace std;
long long f[100001],g[100001],sum[100001];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&f[i]);
    sort(f+1,f+1+n);g[0]=0;sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i];
    for (int i=n;i>0;i--) {long long tmp=n-i;g[1]+=f[i]*tmp;}
    for (int i=2;i<=n;i++) g[i]=-1;
    int q;
    scanf("%d",&q);
    while (q>0)
    {
        q--;
        long long x;scanf("%I64d",&x);
        long long y=0;
        if (x>n-1) x=n-1;
        if (g[x]==-1)
        {
            g[x]=0;
            long long u=1;
            long long pos=n;
            while (pos>0)
            {
                long long one=1;
                long long t=pos-u+one;
                if (t<one) t=1;
                g[x]+=y*(sum[pos]-sum[t-one]);
                y++;
                pos-=u;
                u*=x;
            }
        }
        printf("%I64d ",g[x]);
    }
    printf("\n");
    return 0;
}

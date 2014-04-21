#include<stdio.h>
#include<string.h>
int a[2][5000];
int q[5000];
bool used[5000];

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n,m;scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(used,false,sizeof(used));
        long long mod=m;
        a[0][0]=1;q[0]=1;q[1]=0;
        int l=0;used[0]=true;
        for (int i=1;i<=n;i++)
        {
            memset(a[l^1],0,sizeof(a[l^1]));int qq=q[0];
            for (int j=1;j<=qq;j++)
            {
                a[l^1][q[j]]+=a[l][q[j]];
                if (a[l^1][q[j]]>=m) a[l^1][q[j]]-=m;
                int x=(q[j]^i);
                a[l^1][x]+=a[l][q[j]];
                if (a[l^1][x]>=m) a[l^1][x]-=m;
                if (!used[x])
                {
                    used[x]=true;
                    q[++q[0]]=x;
                }
            }
            l^=1;
        }
        int ans=a[l][0],sum=a[l][0];
        for (int i=1;i<=n;i++)
        {
            long long aa=a[l][i],ss=sum;
            aa=(aa*ss)%mod;
            int a1=aa;
            ans+=a1;
            sum+=a[l][i];
            if (ans>=m) ans-=m;
            if (sum>=m) sum-=m;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

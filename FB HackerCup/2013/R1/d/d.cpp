#include<stdio.h>
#include<queue>
using namespace std;
int n,k;
int a[50],pr[150];
int b[200];
int c[51][200];
priority_queue<int> f;
int g[21][33000][21];
int q1[2][15000000],q2[2][15000000];
int num[2];

void init()
{
    pr[0]=0;
    for (int i=2;i<=150;i++)
    {
        int j=0;
        for (int k=2;k<i;k++) if (i%k==0) j++;
        if (j==0) pr[++pr[0]]=i;
    }
    b[0]=2;b[1]=7;b[2]=11;
    for (int i=1;i<=15;i++) b[++b[0]]=(1<<(i-1));
    for (int i=1;i<15;i++)
        for (int j=i+1;j<=15;j++)
        if (pr[i]*pr[j]<pr[pr[0]]) b[++b[0]]=((1<<(i-1))|(1<<(j-1)));
    for (int i=2;i<=50;i++)
        for (int j=1;j<=b[0];j++)
        {
            int mul[5];mul[0]=0;
            for (int k=1;k<=15;k++)
                if (b[j]&(1<<(k-1))) mul[++mul[0]]=pr[k];
            while (f.size()>0) f.pop();
            f.push(-1);
            while (-f.top()<i)
            {
                int tmp=-f.top();f.pop();
                for (int k=1;k<=mul[0];k++) f.push(-mul[k]*tmp);
            }
            c[i][j]=-f.top()-i;
        }
}

int work()
{
    if (a[0]==1) return 0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<(1<<15);j++)
            for (int k=0;k<=n;k++) g[i][j][k]=-1;
    num[0]=1;
    q1[0][0]=0;q2[0][0]=0;g[0][0][0]=0;
    for (int i=1;i<=a[0];i++)
    {
        int l=(i&1),l1=(l^1);
        num[l]=0;
        for (int j=0;j<num[l1];j++)
        {
            int u=q1[l1][j],v=q2[l1][j];
            int ans=0;
            ans=pr[15+v+1]-a[i]+g[i-1][u][v];
            if (g[i][u][v+1]==-1)
            {
                g[i][u][v+1]=ans;
                q1[l][num[l]]=u;
                q2[l][num[l]++]=v+1;
            } else
            {
                if (ans<g[i][u][v+1]) g[i][u][v+1]=ans;
            }
            for (int k=1;k<=b[0];k++)
                if ((b[k]&u)==0)
                {
                    ans=g[i-1][u][v]+c[a[i]][k];
                    if (g[i][u|b[k]][v]==-1)
                    {
                        g[i][u|b[k]][v]=ans;
                        q1[l][num[l]]=(u|b[k]);
                        q2[l][num[l]++]=v;
                    } else if (ans<g[i][u|b[k]][v]) g[i][u|b[k]][v]=ans;
                }
        }
    }

    int ans=-1;
    for (int i=0;i<(1<<15);i++)
        for (int j=0;j<=a[0];j++)
            if (g[a[0]][i][j]!=-1)
            {
                if (ans==-1)
                {
                    ans=g[a[0]][i][j];
                } else if (g[a[0]][i][j]<ans) ans=g[a[0]][i][j];
            }
    return ans;
}

int main()
{
    init();
    freopen("preventing_alzheimers.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&k);int z=0,ans=0;a[0]=0;
        for (int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            if ((x==0)&&(z==0)) {z++;} else
            if (x<=k) ans+=k-x; else
            {
                if (x%k!=0) ans+=k-x%k;
                a[++a[0]]=x/k;
                if (x%k>0) a[a[0]]++;
            }
        }
        ans+=work()*k;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

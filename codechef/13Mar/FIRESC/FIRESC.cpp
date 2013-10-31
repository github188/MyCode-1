#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long mod=1e9+7;
bool used[100001];
int e[200001],v[100001],next[200001];

long long dfs(int o)
{
    long long ans=1;
    used[o]=true;
    int j=v[o];
    while (j!=0)
    {
        if (!used[e[j]]) ans+=dfs(e[j]);
        j=next[j];
    }
    return ans;
}

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        memset(used,false,sizeof(used));
        memset(v,0,sizeof(v));
        int tot=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            e[++tot]=y;next[tot]=v[x];v[x]=tot;
            e[++tot]=x;next[tot]=v[y];v[y]=tot;
        }
        long long ans=1,num=0;
        for (int i=1;i<=n;i++)
        if (!used[i]) ans=(ans*dfs(i))%mod,num++;
        cout<<num<<" "<<ans<<endl;
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
bool used[501];
struct edge
{
    int x,v,t;
} e[20000];
int head[501];
int tot,n,m,l,r;

void dfs(int o,int fa)
{
    used[o]=true;
    int j=head[o];
    while (j!=0)
    {
        if ((!used[e[j].x])&&((e[j].t<l)||(e[j].t>r))) dfs(e[j].x,o);
        j=e[j].v;
    }
}

int main()
{
    tot=1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[tot].x=y;
        e[tot].t=i;
        e[tot].v=head[x];;
        head[x]=tot++;

        e[tot].x=x;
        e[tot].t=i;
        e[tot].v=head[y];;
        head[y]=tot++;
    }
    int k;scanf("%d",&k);
    while (k--)
    {
        memset(used,false,sizeof(used));
        scanf("%d%d",&l,&r);int ans=0;
        for (int i=1;i<=n;i++) if (!used[i])
        {
            ans++;
            dfs(i,-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}

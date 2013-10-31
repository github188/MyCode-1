#include<stdio.h>
struct node
{
    long long len,size;
} tr[80001];

int e[200000][2],v[80001];
int n,tot;
long long ans=0;

void dfs1(int o,int fa)
{
    tr[o].size=1;tr[o].len=0;
    int j=v[o];
    long long tmp=0;
    while (j!=0)
    {
        if (e[j][0]!=fa)
        {
            int k=e[j][0];
            dfs1(k,o);
            ans+=tmp*tr[k].len;
            tmp+=tr[k].len;
            tr[o].len+=tr[k].len;
            tr[o].len+=tr[o].size*tr[k].size;
            tr[o].size+=tr[k].size;
        }
        j=e[j][1];
    }
}

void dfs2(int o,int fa)
{
    int j=v[o];
    long long tmp=0;
    while (j!=0)
    {
        if (e[j][0]!=fa)
        {
            int k=e[j][0];
            long long u=n-1-tr[k].size;
            ans+=u*tr[k].len;
            dfs2(k,o);
        }
        j=e[j][1];
    }
}

int main()
{
    tot=0;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        e[++tot][0]=y;
        e[tot][1]=v[x];
        v[x]=tot;
        e[++tot][0]=x;
        e[tot][1]=v[y];
        v[y]=tot;
    }
    dfs1(1,0);
    dfs2(1,0);ans+=ans;
    printf("%I64d\n",ans);
    return 0;
}


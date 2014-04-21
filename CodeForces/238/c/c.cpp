#include<stdio.h>
#include<vector>
using namespace std;

struct edge
{
    int x,y,z;
} a[100000],e[200001];
int v[100001];
int c[100001],d[100001],fa[100001];
bool used[100001];
vector<int> g[100001];

void dfs(int o,int f)
{
    int p=v[o],q=0;
    used[o]=true;fa[o]=f;
    while (p!=0)
    {
        if (!used[e[p].x])
        {
            q++;
            dfs(e[p].x,o);
        }
        p=e[p].y;
    }
    if (q==0) d[++d[0]]=o;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if (m&1) {printf("No solution\n");return 0;}
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].x=x;a[i].y=y;
        c[x]++;c[y]++;
        e[i*2+1].x=y;
        e[i*2+1].y=v[x];
        e[i*2+1].z=i;
        e[i*2+2].x=x;
        e[i*2+2].y=v[y];
        e[i*2+2].z=i;
        v[x]=i*2+1;v[y]=i*2+2;
    }
    for (int i=1;i<=n;i++) g[i].clear();
    int k=1;
    while ((k<n)&&(c[k]==1)) k++;
    dfs(k,0);
    while (d[0])
    {
        int k=d[d[0]--];
        int l=v[k],u=-1,v=-1;
        while (l>0)
        {
            if (a[e[l].z].z==0)&&(e[l].x!=fa[])
            {
                if (u==-1) u=e[l].z;
                else
                {
                    a[e[l].z].z=-1;
                    a[u].z=-1;
                    if (a[u].x==a[e[l].z].x) printf("%d %d %d\n",a[u].y,a[u].x,a[e[l].z].y); else
                    if (a[u].x==a[e[l].z].y) printf("%d %d %d\n",a[u].y,a[u].x,a[e[l].z].x); else
                    if (a[u].y==a[e[l].z].x) printf("%d %d %d\n",a[u].x,a[u].y,a[e[l].z].y); else
                    if (a[u].y==a[e[l].z].y) printf("%d %d %d\n",a[u].x,a[u].y,a[e[l].z].x);
                }
            }
            l=e[l].y;
        }
        if (u==-1)
        {
            for (int i=0;i<g[k].size();i+=2)
            {
                printf("%d %d %d\n",g[k][i],k,g[k][i+1]);
            }
            if (g[k].size()&1)
        }
    }
    return 0;
}

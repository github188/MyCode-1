#include<stdio.h>
#include<set>
#define MAXNUM 2000000007
using namespace std;
struct node
{
    int n,v;
} heap[100010];
set<int> s1[100010];
int n,m;
int v[100010],e[200010][3],pos[100010],dis[100010];
bool use[100010];

void up(int o)
{
    if (o==1) return;
    int p=o/2;
    if (heap[p].v>heap[o].v)
    {
        node tmp=heap[p];heap[p]=heap[o];heap[o]=tmp;
        pos[heap[o].n]=o;
        pos[heap[p].n]=p;
        up(p);
    }
}

void down(int o)
{
    int p=o+o;
    if (p>n) return;
    if ((p+1<=n)&&(heap[p+1].v<heap[p].v)) p++;
    if (heap[p].v<heap[o].v)
    {
        node tmp=heap[p];heap[p]=heap[o];heap[o]=tmp;
        pos[heap[o].n]=o;
        pos[heap[p].n]=p;
        down(p);
    }

}

int main()
{
    int tot=0;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        tot++;
        e[tot][0]=y;
        e[tot][1]=z;
        e[tot][2]=v[x];
        v[x]=tot;

        tot++;
        e[tot][0]=x;
        e[tot][1]=z;
        e[tot][2]=v[y];
        v[y]=tot;
    }

    for (int i=1;i<=n;i++)
    {
        int m=0;scanf("%d",&m);
        s1[i].clear();
        for (int j=0;j<m;j++)
        {
            int x;scanf("%d",&x);
            s1[i].insert(x);
        }
    }

    int size=n;
    for (int i=1;i<=n;i++)
    {
        heap[i].n=i;
        heap[i].v=MAXNUM;
        pos[i]=i;
        up(i);
    }
    heap[1].v=0;

    while (!use[n])
    {
        int tmp=heap[1].n;
        if (use[heap[1].n]) break;
        if (tmp==n) {use[n]=true;dis[n]=heap[1].v;break;}
        if (s1[tmp].find(heap[1].v)!=s1[tmp].end())
        {
            heap[1].v++;
            down(1);
            continue;
        }
        use[tmp]=true;
        dis[tmp]=heap[1].v;
        int j=v[tmp];
        heap[1].v=MAXNUM;
        down(1);
        while (j!=0)
        {
            int k=e[j][0],v=e[j][1];
            if ((!use[k])&&(heap[pos[k]].v>dis[tmp]+v))
            {
                heap[pos[k]].v=dis[tmp]+v;
                up(pos[k]);
            }
            j=e[j][2];
        }
    }

    if (!use[n]) printf("-1\n"); else printf("%d\n",dis[n]);
    return 0;
}

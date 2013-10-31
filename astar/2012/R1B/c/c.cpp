#include<stdio.h>
#include<string.h>

#define N 2000
#define E 20000
#define typef int // type of flow
#define typec int // type of dis
const typef inff = 0x3f3f3f3f; // max of flow
const typec infc = 0x3f3f3f3f; // max of dis

int e[20000][4],a[2000][2],b[2][3];
void gete(int o,int *x,int *y,int *f,int *w)
{
    *x=e[o][0];
    *y=e[o][1];
    *f=e[o][2];
    *w=-e[o][3];
}

struct network
{
int nv, ne, pnt[E], nxt[E];
int vis[N], que[N], head[N], pv[N], pe[N];
typef flow, cap[E]; typec cost, dis[E], d[N];
void addedge(int u, int v, typef c, typec w) {
pnt[ne] = v; cap[ne] = c;
dis[ne] = +w; nxt[ne] = head[u]; head[u] = (ne++);
pnt[ne] = u; cap[ne] = 0;
dis[ne] = -w; nxt[ne] = head[v]; head[v] = (ne++);
}
int mincost(int src, int sink) {
int i, k, f, r; typef mxf;
for (flow = 0, cost = 0; ; ) {
memset(pv, -1, sizeof(pv));
memset(vis, 0, sizeof(vis));
for (i = 0; i < nv; ++i) d[i] = infc;
d[src] = 0; pv[src] = src; vis[src] = 1;
for (f = 0, r = 1, que[0] = src; r != f; ) {
i = que[f++]; vis[i] = 0;
if (N == f) f = 0;
for (k = head[i]; k != -1; k = nxt[k])
if(cap[k] && dis[k]+d[i] < d[pnt[k]])
{
d[pnt[k]] = dis[k] + d[i];
if (0 == vis[pnt[k]]) {
vis[pnt[k]] = 1;
que[r++] = pnt[k];
if (N == r) r = 0;
}
pv[pnt[k]]=i; pe[pnt[k]]=k;
}
}
if (-1 == pv[sink]) break;
for (k = sink, mxf = inff; k != src; k = pv[k])
if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
flow += mxf; cost += d[sink] * mxf;
for (k = sink; k != src; k = pv[k]) {
cap[pe[k]] -= mxf; cap[pe[k] ^ 1] += mxf;
}
}
return cost;
}
void build(int v, int e) {
nv = v; ne = 0;
memset(head, -1, sizeof(head));
int x, y; typef f; typec w;
for (int i = 0; i < e; ++i) {
//cin >> x >> y >> f >> w; // vertex: 0 ~ n-1
gete(i,&x,&y,&f,&w);
addedge(x, y, f, w);// add arc (u->v, f, w)
}
}
} g;


int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
    for (int i=0;i<2;i++) for (int j=0;j<3;j++) scanf("%d",&b[i][j]);
    int tot=0;
    for (int i=0;i<n;i++)
    {
        e[tot][0]=0;e[tot][1]=i+1;e[tot][2]=1;e[tot][3]=0;tot++;
        e[tot][0]=i+1;e[tot][1]=n+1;e[tot][2]=1;e[tot][3]=a[i][0]*b[0][1]+a[i][1]*b[0][2];tot++;
        e[tot][0]=i+1;e[tot][1]=n+2;e[tot][2]=1;e[tot][3]=a[i][0]*b[1][1]+a[i][1]*b[1][2];tot++;
    }
    e[tot][0]=n+1;e[tot][1]=n+3;e[tot][2]=b[0][0];e[tot][3]=0;tot++;
    e[tot][0]=n+2;e[tot][1]=n+3;e[tot][2]=b[1][0];e[tot][3]=0;tot++;
    g.build(n+4,tot);
    printf("%d\n",-g.mincost(0,n+3));
    return 0;
}

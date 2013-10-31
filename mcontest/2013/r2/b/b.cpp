#include<stdio.h>
#include<string.h>
#define N 1000
#define E 50000
#define typef int                  // type of flow
#define typec double                     // type of dis
using namespace std;
const typef inff = 1e9;       // max of flow
const typec infc = -1e9;       // max of dis
struct  network
{
  int  nv, ne, pnt[E], nxt[E];
  int  vis[N], que[N], head[N], pv[N], pe[N];
  typef flow, cap[E]; typec cost, dis[E], d[N];
  void addedge(int  u, int  v, typef c, typec w) {
    pnt[ne] =  v; cap[ne] = c;
    dis[ne] = +w; nxt[ne] = head[u]; head[u] = (ne++);
    pnt[ne] =  u; cap[ne] = 0;
    dis[ne] = -w; nxt[ne] = head[v]; head[v] = (ne++);
 }
  double  mincost(int  src,  int  sink) {
  int  i, k, f, r; typef mxf;
  for  (flow = 0, cost = 0; ; ) {
   memset(pv, -1, sizeof (pv));
   memset(vis, 0, sizeof (vis));
    for  (i = 0; i < nv; ++i) d[i] = infc;
      d[src] = 0; pv[src] = src; vis[src] = 1;

    for  (f = 0, r = 1, que[0] = src; r != f; ) {
        i = que[f++]; vis[i] = 0;
if (N == f) f = 0;
    for  (k = head[i]; k != -1; k = nxt[k])
     if(cap[k] && dis[k]+d[i] > d[pnt[k]])
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
    if (-1 == pv[sink])  break;

    for  (k = sink, mxf = inff; k != src; k = pv[k])
    if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
      flow += mxf; cost += d[sink];

    for  (k = sink; k != src; k = pv[k]) {
        cap[pe[k]] -= mxf; cap[pe[k] ^ 1] += mxf;
   }
  }
  return  cost;
 }

} g;

double q1[510],q2[510],c1[510],c2[510];

    int n,n1,n2;
bool check(double mid)
{
        g.nv=n+5;g.ne=0;
        memset(g.head, -1, sizeof (g.head));
        g.addedge(1+n+1,1+n+3,n1,0);
        g.addedge(1+n+2,1+n+3,n2,0);
        for (int i=1;i<=n;i++)
        {
            g.addedge(1,1+i,1,0);
            g.addedge(1+i,1+n+1,1,q1[i]-mid*c1[i]);
            g.addedge(1+i,1+n+2,1,q2[i]-mid*c2[i]);
        }
        double ans=g.mincost(1,1+n+3);
        if (ans>=0) return true;
        return false;
}

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d%d",&n,&n1,&n2);
        for (int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&q1[i],&c1[i],&q2[i],&c2[i]);
        double l=0,r=1e6;
        while (r-l>1e-7)
        {
            double mid=(l+r)/2.0;
            if (check(mid)) l=mid; else r=mid;
        }
        printf("Case #%d: %.6f\n",t,l);
    }
    return 0;
}

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define E 50000
#define N 300
#define typef int                     // type of flow
#define typec int                     // type of dis
const typef inff = 0x3f3f3f3f;       // max of flow
const typec infc = 0x3f3f3f3f;       // max of dis
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
  int  mincost(int  src,  int  sink) {
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
    if (-1 == pv[sink])  break;

    for  (k = sink, mxf = inff; k != src; k = pv[k])
    if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
      flow += mxf; cost += d[sink] * mxf;

    for  (k = sink; k != src; k = pv[k]) {
        cap[pe[k]] -= mxf; cap[pe[k] ^ 1] += mxf;
   }
  }
  return  cost;
 }
  void build(int  v, int  e) {
    nv = v; ne = 0;
  memset(head, -1, sizeof (head));
 }
};

char s[100],st[100];
char a[50][50][100];
struct str
{
    char s[100];
    int ind;
    bool operator<(const str &b) const
    {
        int n=strlen(s);
        for (int i=0;i<n;i++)
        if (s[i]>b.s[i]) return false;
        return true;
    }
} b[50];

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.out","w",stdout);
    int tt;scanf("%d",&tt);gets(s);
    for (int t=1;t<=tt;t++)
    {
        int m,l;scanf("%d",&m);gets(s);
        gets(s);gets(st);l=strlen(s)/m;
        network g;g.build(2*m+3,0);
        for (int i=1;i<=m;i++)
        {
            g.addedge(2*m+1,i,1,0);
            g.addedge(m+i,2*m+2,1,0);
        }
        memset(a,0,sizeof(a));
        for (int i=0;i<m;i++)
        {
            int tot=0;
            for (int j=0;j<m;j++)
            {
                int x=i*l,y=j*l;
                bool check=true;
                char s1[100];memset(s1,0,sizeof(s1));
                for (int k=0;k<l;k++)
                {
                    if (s[x+k]==st[y+k])
                    {
                        if (s[x+k]=='?') s1[k]='a';
                        else s1[k]=s[x+k];
                    } else
                    if (s[x+k]=='?') s1[k]=st[y+k]; else
                    if (st[y+k]=='?') s1[k]=s[x+k]; else
                    {
                        check=false;
                        break;
                    }
                }
                if (check)
                {
                    for (int k=0;k<l;k++) a[i][j][k]=b[tot].s[k]=s1[k];
                    b[tot].ind=j;tot++;
                }
            }
            std::sort(b,b+tot);
            for (int j=0;j<tot;j++) g.addedge(i+1,m+b[j].ind+1,1,j);
        }
        g.mincost(2*m+1,2*m+2);
        if (g.flow!=m) printf("Case #%d: IMPOSSIBLE\n",t);
        else
        {
            printf("Case #%d: ",t);
            for (int i=0;i<m;i++)
            {
                int j=g.head[i+1];
                while (j!=-1)
                {
                    if ((g.pnt[j]>m)&&(g.pnt[j]<=2*m)&&(g.cap[j]==0))
                    {
                        printf("%s",a[i][g.pnt[j]-m-1]);
                        break;
                    }
                    j=g.nxt[j];
                }
            }
            printf("\n");
        }
    }
    return 0;
}

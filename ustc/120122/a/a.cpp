#include<stdio.h>
#include<string.h>
#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
struct edge { int x, y, nxt; typec c; } bf[100000];
int ne, head[2000], cur[2000], ps[2000], dep[2000];
void addedge(int x, int y, typec c)
{ // add an arc(x -> y, c); vertex: 0 ~ n-1;
bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
bf[ne].nxt = head[x]; head[x] = ne++;
bf[ne].x = y; bf[ne].y = x; bf[ne].c = 0;
bf[ne].nxt = head[y]; head[y] = ne++;
}
typec flow(int n, int s, int t)
{
typec tr, res = 0;
int i, j, k, f, r, top;
while (1) {
memset(dep, -1, n * sizeof(int));
for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
{
if (bf[j].c && -1 == dep[k = bf[j].y]){
dep[k] = dep[i] + 1; ps[r++] = k;
if (k == t) { f = r; break; }
}
}
if (-1 == dep[t]) break;
memcpy(cur, head, n * sizeof(int));
for (i = s, top = 0; ; ) {
if (i == t) {
for (k = 0, tr = inf; k < top; ++k)
if (bf[ps[k]].c < tr)
tr = bf[ps[f = k]].c;
for (k = 0; k < top; ++k)
bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
res += tr; i = bf[ps[top = f]].x;
}
for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
if (cur[i]) {
ps[top++] = cur[i];
i = bf[cur[i]].y;
}
else {
if (0 == top) break;
dep[i] = -1; i = bf[ps[--top]].x;
}
}
}
return res;
}

int n,m,s,t;
int a[1001],b[10000][4],c[1001];
bool use[2][1001];

int main()
{
    int tt=0;
    while (true)
    {
        scanf("%d%d",&n,&m);if (n==0) break;
        scanf("%d%d",&s,&t);

        for (int i=0;i<m;i++) {scanf("%d%d%d%d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);}
        for (int i=1;i<=n;i++) {c[i]=a[i]=1000001;use[0][i]=use[1][i]=false;}
        a[s]=c[t]=0;
        while (!use[0][t])
        {
            int u,v=1000001;
            for (int i=1;i<=n;i++)
            if ((!use[0][i])&&(a[i]<v)) {u=i;v=a[i];}
            for (int i=0;i<m;i++)
            {
                if (b[i][0]==u)
                {
                    int y=b[i][1];
                    if (a[u]+b[i][2]<a[y]) a[y]=a[u]+b[i][2];
                }

                if (b[i][1]==u)
                {
                    int y=b[i][0];
                    if (a[u]+b[i][2]<a[y]) a[y]=a[u]+b[i][2];
                }
            }
            use[0][u]=true;
        }

        while (!use[1][s])
        {
            int u,v=1000001;
            for (int i=1;i<=n;i++)
            if ((!use[1][i])&&(c[i]<v)) {u=i;v=c[i];}
            for (int i=0;i<m;i++)
            {
                if (b[i][0]==u)
                {
                    int y=b[i][1];
                    if (c[u]+b[i][2]<c[y]) c[y]=c[u]+b[i][2];
                }

                if (b[i][1]==u)
                {
                    int y=b[i][0];
                    if (c[u]+b[i][2]<c[y]) c[y]=c[u]+b[i][2];
                }
            }
            use[1][u]=true;
        }

        ne=2;
        for (int i=0;i<=n;i++) head[i]=0;
        for (int i=0;i<m;i++)
        {
            int x=b[i][0],y=b[i][1],w=b[i][2];
            if (a[x]+c[y]+w==a[t]) addedge(b[i][0]-1,b[i][1]-1,b[i][3]);
            if (a[y]+c[x]+w==a[t]) addedge(b[i][1]-1,b[i][0]-1,b[i][3]);
        }
        int ans=flow(n,s-1,t-1);
        tt++;
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}

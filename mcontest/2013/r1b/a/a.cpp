#include<stdio.h>
#include<string.h>
#define N 300
#define E 90000
#define typec int
#define typef int
const typec inf = 0x3f3f3f3f;       // max of cost
struct  edge {  int  x, y, nxt; typec c; } bf[E];
int  ne, head[N], cur[N], ps[N], dep[N];
void addedge(int  x, int  y, typec c)
{  // add an arc(x -> y, c); vertex: 0 ~ n-1;
  bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
  bf[ne].nxt = head[x]; head[x] = ne++;
  bf[ne].x = y; bf[ne].y = x; bf[ne].c = 0;
  bf[ne].nxt = head[y]; head[y] = ne++;
}
typec flow( int  n, int  s, int  t)
{
  typec tr, res = 0;
  typef e[N];
    int  i, j, k, f, r, top;
    while (1) {
        memset(dep, -1, n * sizeof ( int ));
  for  (f = dep[ps[0] = s] = 0, r = 1; f != r; )
    for  (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
{
    if (bf[j].c && -1 == dep[k = bf[j].y]){
          dep[k] = dep[i] + 1; ps[r++] = k;
     if (k == t) { f = r; break; }
    }
   }
        if (-1 == dep[t])  break;

        memcpy(cur, head, n * sizeof ( int ));
        for  (i = s, top = 0; ; ) {
            if (i == t) {
                for  (k = 0, tr = inf; k < top; ++k)
    if (bf[ps[k]].c < tr)
tr = bf[ps[f = k]].c;
                for  (k = 0; k < top; ++k)
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                res += tr;  i = bf[ps[top = f]].x;
            }
            for  (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
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
    return  res;
}

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        printf("Case #%d:\n",t);
        int last=0;
        ne=2;
        int n,m;scanf("%d%d",&n,&m);
        for (int i=0;i<=n;i++) head[i]=0;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
            int tmp=flow(n+1,1,n);
            if (tmp!=0) printf("%d %d\n",i,tmp);
        }
    }
    return 0;
}

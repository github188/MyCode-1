#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct edge
{
int a,b,c;
} e[1000000];
int fa[100001];
int n,m,len,p;
int l[1000000];
bool cmp (edge a,edge b)
{
return a.c<b.c;
}

int fat(int o)
{
if (fa[o]==o) return o;
fa[o]=fat(fa[o]);
return fa[o];
}

int main()
{
int tt;scanf("%d",&tt);
while (tt--)
{
scanf("%d%d",&n,&m);
for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
len=0;
for (int i=1;i<=n;i++) fa[i]=i;
sort(e,e+m,cmp);
int i=0;int q=n-1;p=0;
while ((q)&&(i<m))
{
int j=i;l[0]=0;if (fat(e[i].a)!=fat(e[i].b))l[++l[0]]=i;
while ((i+1<m)&&(e[i+1].c==e[j].c))
{
i++;
if (fat(e[i].a)!=fat(e[i].b))
{
l[++l[0]]=i;
}
}
for (int k=1;k<=l[0];k++)
{
if (fat(e[l[k]].a)!=fat(e[l[k]].b))
{fa[fa[e[l[k]].a]]=fa[e[l[k]].b];len+=e[l[k]].c;q--;} else p=1;
}
i++;
}
if (q==0) printf("%d %d\n",len,p); else printf("-1\n");
}
return 0;
}

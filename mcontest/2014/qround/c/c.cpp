#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define maxn 205
#define maxm 300005
#define inf 0x3fffffff
struct Edge{ int u,v,cap,cost,x; }E[maxm];
int e,l[maxn];
inline void init(){ e=0; memset(l,-1,sizeof(l)); }
inline void insert(int u,int v,int cap,int cost){
	E[e].u=u; E[e].v=v; E[e].cap=cap; E[e].cost= cost; E[e].x=l[u]; l[u]=e++;
	E[e].u=v; E[e].v=u; E[e].cap=0  ; E[e].cost=-cost; E[e].x=l[v]; l[v]=e++;
}
int q[20*maxn],s,t, inq[maxn], dis[maxn],eid[maxn];
void min_cost_max_flow(int src,int sink,int &cap,int &cost){
	cost=cap=0;
	while( true ){
		for(int i=0;i<maxn;i++) dis[i]=inf;
		s=t=0; q[t++]=src; inq[src]=1; dis[src]=0;
		while(s<t){
			int u=q[s++]; inq[u]=0;
			for(int p=l[u];p>=0;p=E[p].x){
				if( E[p].cap<=0 ) continue;
				int v=E[p].v;
				if( dis[v]>dis[u]+E[p].cost ){  //<
					dis[v]=dis[u]+E[p].cost; eid[v]=p;
					if( inq[v]==0 ){
						inq[v]=1; q[t++]=v;
					}
				}
			}
		}
		if( dis[sink]>=inf ) return;
		int c=inf;
		for(int i=sink;i!=src;i=E[eid[i]].u) c=min(c,E[eid[i]].cap);
		cost+=dis[sink]*c;  cap+=c;
		for(int i=sink;i!=src;i=E[eid[i]].u) {
			int p=eid[i];  E[p].cap-=c; E[p^1].cap+=c;
		}
	}
}

int a[100][100],b[100],c[100];

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n,m;scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
        if (n>m)
        {
            int k=n;n=m;m=k;
            for (int i=0;i<100;i++)
            for (int j=i+1;j<100;j++) {k=a[i][j];a[i][j]=a[j][i];a[j][i]=k;}
        }
        for (int i=0;i<m;i++)
        {
            b[i]=a[0][i];
            for (int j=0;j<n;j++) if (a[j][i]<b[i]) b[i]=a[j][i];
        }
        init();
        insert(0,n+1,m-n,0);
        for (int i=0;i<n;i++) insert(0,i+1,1,0);
        for (int i=0;i<m;i++) {insert(n+1,i+n+2,1,b[i]);insert(i+n+2,n+m+2,1,0);}
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) insert(1+i,j+n+2,1,a[i][j]);
        int flow=0,value=0;
        min_cost_max_flow(0,n+m+2,flow,value);
        printf("Case %d: %d\n",t,value);
    }
    return 0;
}

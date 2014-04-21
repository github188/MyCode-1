#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 1200
#define MAXE 50000
#define inf  0x3f3f3f3f
int edge[30000][4],v[1001],d[1001];
bool used[1001];
struct Edge
{  int v,c,x; }
E[MAXE];
int l[MAXN],e;
void init(){ e=0; memset(l,-1,sizeof(l));  }
inline void insert(int u,int v,int f,int invf){ //u->v=f   v->u=invf
	E[e].v=v; E[e].c=f;   E[e].x=l[u]; l[u]=e++;
	E[e].v=u; E[e].c=invf;E[e].x=l[v]; l[v]=e++;
}
struct Netflow{
	int src,sink; //需要初始化
	//以上
	int L[MAXN],Q[MAXN]; //L=level  Q=queue
	int _bfs(){ //广搜,并标记level(只取流量大于0的边)
		int s=0,t=0,u;
		memset(L,0xff,sizeof(L));
		L[src]=0; Q[t++]=src;
		while (s<t){
			u=Q[s++];
			for (int p=l[u];p>=0;p=E[p].x)
				if (E[p].c && L[E[p].v]==-1)
					L[(Q[t++]=E[p].v)]=L[u]+1;
		}
		return L[sink]!=-1;
	}
	int _find(int u,int in){
		if (u==sink) return in;
		int t,w=0;
		for (int p=l[u];p>=0 && w<in;p=E[p].x){
			if (E[p].c>0 && L[E[p].v]==L[u]+1){
				if (t=_find(E[p].v,min(E[p].c,in-w))){
					E[  p].c-=t;
					E[p^1].c+=t; //这里表示必须
					w+=t;     //多路增广优势巨大
				}
			}
		}
		if( w<in )L[u]=-1;//关键的一句话
		return w;
	}
	int dinic(){
		int t,res=0;
		while (_bfs())while (t=_find(src,inf))res+=t;
		return res;
	}
}flow;


int main()
{
    while (true)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n+m==0) break;
        int u,vv;scanf("%d%d",&u,&vv);
        for (int i=1;i<=n;i++) {v[i]=0;d[i]=1e9;used[i]=false;}
        int tot=0;
        for (int i=0;i<m;i++)
        {
            tot++;
            int x,y,w,c;scanf("%d%d%d%d",&x,&y,&w,&c);
            edge[tot][0]=y;
            edge[tot][1]=v[x];
            edge[tot][2]=w;
            edge[tot][3]=c;
            v[x]=tot;
            tot++;
            edge[tot][0]=x;
            edge[tot][1]=v[y];
            edge[tot][2]=w;
            edge[tot][3]=c;
            v[y]=tot;
        }
        d[u]=0;
        while (true)
        {
            int maxn=1e9,p=-1;
            for (int i=1;i<=n;i++)
            {
                if ((d[i]<=maxn)&&(!used[i]))
                {
                    if (((maxn==d[i])&&(p==vv))||(maxn>d[i])) p=i;
                    maxn=d[i];
                }
            }
            if ((p<0)||(p==vv)) break;
            used[p]=true;
            int j=v[p];
            while (j>0)
            {
                int x=edge[j][0];
                if (d[p]+edge[j][2]<d[x])
                {
                    d[x]=d[p]+edge[j][2];
                }
                j=edge[j][1];
            }
        }
        if (d[vv]==1e9) {printf("0\n");continue;}
        init();
        for (int i=1;i<=n;i++)
        {
            int j=v[i];
            while (j)
            {
                if (d[i]+edge[j][2]==d[edge[j][0]])
                {
                    insert(i,edge[j][0],edge[j][3],0);
                }
                j=edge[j][1];
            }
        }
        flow.src=u;flow.sink=vv;
        printf("%d\n",flow.dinic());
    }
    return 0;
}

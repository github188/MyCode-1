#include<vector>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int a[50][2],b[50][2];
#define maxn 100
#define inf  1e9

int adj[maxn][maxn],src,sink; //总节点数n(base0), 流网络adj, 源s汇t
int L[maxn],Q[maxn]; //L=level  Q=queue
int _bfs(){ //广搜,并标记level(只取流量大于0的边)
	int s=0,t=0,u;
	memset(L,0xff,sizeof(L));
	L[src]=0; Q[t++]=src;
	while (s<t){
		u=Q[s++];
		for (int v=0;v<=sink;v++)
		if (adj[u][v] && L[v]==-1)
		L[ Q[t++]=v ]=L[u]+1;
	}
	return L[sink]!=-1;
}
int _find(int u,int in){ //in:能流入u节点的最大流量. 返回u节点能流出的最大流量
	if (u==sink) return in;
	int t=0,w=0; //w表示已经从u流出的总流量
	for (int v=0;v<=sink && w<in;v++){
		if (adj[u][v] && L[v]==L[u]+1){
			if (t=_find(v,min(adj[u][v],in-w))){
				adj[u][v]-=t;
				adj[v][u]+=t;
				w+=t;
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
}//n,adj,src,sink赋值之后,调用dinic()....

class SpecialCells
{
public:
	int guess(vector <int> x, vector <int> y)
	{
		int n=x.size();
		int ma=0,mb=0;
		for (int i=0;i<n;i++)
		{
			bool p=false;
			for (int j=0;j<ma;j++)
			if (a[j][0]==x[i]) {a[j][1]++;p=true;break;}
			if (!p) {a[ma][0]=x[i];a[ma++][1]=1;}
			p=false;
			for (int j=0;j<mb;j++)
			if (b[j][0]==y[i]) {b[j][1]++;p=true;break;}
			if (!p) {b[mb][0]=y[i];b[mb++][1]=1;}
		}
		src=0,sink=ma+mb+1;
		memset(adj,0,sizeof(adj));
		for (int i=0;i<ma;i++) adj[0][i+1]+=a[i][1];
		for (int j=0;j<mb;j++) adj[ma+j+1][ma+mb+1]+=b[j][1];
		for (int i=0;i<ma;i++)
			for (int j=0;j<mb;j++)
			{
				bool p=true;
				for (int k=0;k<n;k++) if ((x[k]==a[i][0])&&(y[k]==b[j][0])) {p=false;break;}
				if (p) adj[i+1][ma+j+1]+=1;
			}

		return n-dinic();
	}
} PO;

int main()
{
    vector<int> g,h;
    g.clear();h.clear();
    g.push_back(1);
    g.push_back(2);
    g.push_back(1);
    h.push_back(1);
    h.push_back(1);
    h.push_back(2);
    printf("%d\n", PO.guess(g,h));
    return 0;
}

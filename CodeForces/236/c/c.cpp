#include<stdio.h>
#include<string.h>
#define maxn 5000
int min(int o,int p)
{
    return (o<p)?o:p;
}

struct Edge
{
    int v,next;
} E[4000001];
int label[2000],list[2000];

/*
有向图强连通分量Tarjan算法
如果一个节点是根,那么DFN(深度优先序号)==Low(能达到的最低标号)
*/
struct Tarjan{
	Edge *E;  bool in[maxn];
	int DFN[maxn],Low[maxn], st[maxn],top , *list ,*label , compo, deep; //深度必须是一个全局量!!!!
	//处理0~N-1,结果存在label数组里,label[i]表示i这个节点属于谁,返回收缩后还有几个点base0
	int DirGraphShrink(int N,int *list,Edge *E,int *label){
		this->list=list; this->E=E; this->label=label;
		memset(in,false,sizeof(in)); memset(DFN,0,sizeof(DFN));
		top=compo=deep=0;
		for(int i=0;i<N;i++) if( DFN[i]==0 ) _tarjan(i);
		return compo;
	}
	void _tarjan(int u){
		DFN[u]=Low[u]=++deep;
		st[top++]=u; in[u]=true;
		for(int p=list[u];p!=-1;p=E[p].next){
			int v=E[p].v;
			if( DFN[v]==0 ){
				_tarjan(v);
				Low[u]=min(Low[u],Low[v]);
			}else if( in[v] )//防止uv是横叉边****必须在栈中
				Low[u]=min(Low[u],DFN[v]);
		}
		if( Low[u]==DFN[u] ){
			int v;
			do{
				v=st[--top];
				label[v]=compo;  in[v]=false;
			}while( v!=u );
			compo++;
		}
	}
}dir_tarjan;

int main()
{
    int n,tot=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) list[i]=-1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            int x;scanf("%d",&x);
            if (x>0)
            {
                E[tot].v=j;
                E[tot].next=list[i];
                list[i]=tot;tot++;
            }
        }
    if (dir_tarjan.DirGraphShrink(n,list,E,label)==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}

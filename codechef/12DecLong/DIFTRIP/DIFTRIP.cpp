#include<stdio.h>
#include<vector>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>

using namespace std;
#define maxn 200020
#define maxn2 100010
#define absize 200
int n,m,i,j,len[maxn],Link[maxn],sz,last[maxn2],cur,pr[maxn2],F[maxn2],T[maxn],P[maxn],ii,G[maxn][absize],xi,yi,tqn,tqi,Q[maxn2];
vector<bool>u;
pair<int,int>f[maxn];
long long dp[maxn],k;
long long res=0;
int a[maxn2];
map < int , int > dirc;
int size_dec;

inline void addedge(int x,int y){
	T[++ii]=y;P[ii]=F[x];F[x]=ii;
}
void build(){
	int q,p,cl,c,q1,q2;
	q1=1,q2=0;Q[0]=1;u[1]=1;
	while(q1!=q2){
		k=Q[q2++];
		c=a[k];cur=++sz;len[cur]=len[last[pr[k]]]+1;
		p=last[pr[k]];
		while(p&&!G[p][c]){G[p][c]=cur;p=Link[p];}
		if(!p)Link[cur]=1;else{
			q=G[p][c];
			if(len[p]+1==len[q])Link[cur]=q;else{
				cl=++sz;
				len[cl]=len[p]+1;Link[cl]=Link[q];
				for(j=0;j<size_dec;j++)G[cl][j]=G[q][j];
				while(p&&G[p][c]==q){G[p][c]=cl;p=Link[p];}
				Link[q]=Link[cur]=cl;
			}
		}
		last[k]=cur;q=F[k];
		while(q){
			if(!u[T[q]]){
				pr[T[q]]=k;u[T[q]]=1;
				Q[q1++]=T[q];
			}
			q=P[q];
		}
	}
}
inline int read(){
	int fla=0,ret=0;char ch;
	while(1){
		ch=getchar();
		if(ch<'0')if(fla)return ret;else continue;
		ret=10*ret+ch-'0';
		fla=1;
	}
}

int main(){
	sz=last[0]=1;len[1]=Link[1]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)a[i]=0;
	for(i=1;i<n;i++){
		xi=read();yi=read();
		addedge(xi,yi);
		addedge(yi,xi);
		a[xi]++;a[yi]++;
	}
	dirc.clear();
	int num=0;
	for (int i=1;i<=n;i++)
	{
	    if (dirc[a[i]]==0) {dirc[a[i]]=++num;}
	    a[i]=dirc[a[i]]-1;
	}
	size_dec=dirc.size();
	u.resize(n+1);
	build();
	for(i=1;i<=sz;i++)f[i]=make_pair(len[i],i);
	sort(f+1,f+sz+1);
	for(i=1;i<=sz;i++){
		k=f[sz-i+1].second;
		dp[k]=1;
		for(j=0;j<size_dec;j++)if(G[k][j])dp[k]+=dp[G[k][j]];
	}
	cout<<dp[1]-1<<endl;
	return 0;
}

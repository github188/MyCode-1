#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int tr[1000000][4],v[100001],e[200001][2],a[100001],g[100001][2],fa[100001],b[100001][2],q[100001];
int n,m,tot,tt,tot_t;
string s;

void dfs(int o,int p)
{
    q[0]++;
    q[q[0]]=a[o];
    b[o][0]=q[0];
    fa[o]=p;

    int j=v[o];
    while (j>0)
    {
        if (e[j][0]!=p) dfs(e[j][0],o);
        j=e[j][1];
    }
    b[o][1]=q[0];
}

void ins(int o,int l,int r,int pos,int val)
{
    if (val>tr[o][0]) tr[o][0]=val;
    if (l==r) return;
    int mid=(l+r)/2;
    if (pos<=mid)
    {
        if (tr[o][2]==0)
        {
            tot_t++;
            tr[o][2]=tot_t;
            tr[tot_t][0]=tr[tot_t][1]=tr[tot_t][2]=tr[tot_t][3]=0;
        }
        ins(tr[o][2],l,mid,pos,val);
    }
    else
    {
        if (tr[o][3]==0)
        {
            tot_t++;
            tr[o][3]=tot_t;
            tr[tot_t][0]=tr[tot_t][1]=tr[tot_t][2]=tr[tot_t][3]=0;
        }
        ins(tr[o][3],mid+1,r,pos,val);
    }
}

int max(int o,int p)
{
    if (o>p) return o;return p;
}

void add(int o,int l,int r,int p,int q,int t)
{
    if (q<p) return;
    if ((p<=l)&&(r<=q)) {tr[o][1]+=t;return;}
    int mid=(l+r)/2;int x=0,y=0;
    if ((p<=mid)&&(tr[o][2]!=0)) add(tr[o][2],l,mid,p,q,t);
    if ((q>mid)&&(tr[o][3]!=0)) add(tr[o][3],mid+1,r,p,q,t);
    if (tr[o][2]!=0) x=tr[tr[o][2]][0]+tr[tr[o][2]][1];
    if (tr[o][3]!=0) y=tr[tr[o][3]][0]+tr[tr[o][3]][1];
    tr[o][0]=max(x,y);
}

int find(int o,int l,int r,int p,int q)
{
    if (q<p) return 0;
    if ((p<=l)&&(r<=q)) return tr[o][0]+tr[o][1];
    int x=0,y=0;
    int mid=(l+r)/2;
    if ((p<=mid)&&(tr[o][2]!=0)) x=find(tr[o][2],l,mid,p,q);
    if ((q>mid)&&(tr[o][3]!=0)) y=find(tr[o][3],mid+1,r,p,q);
    int ans=max(x,y);
    return ans+tr[o][1];
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {scanf("%d",&a[i]);v[i]=0;}
        tot=0;
        for (int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tot++;
            e[tot][0]=y;
            e[tot][1]=v[x];
            v[x]=tot;
            tot++;
            e[tot][0]=x;
            e[tot][1]=v[y];
            v[y]=tot;
            g[i][0]=x;
            g[i][1]=y;
        }
        q[0]=0;
        dfs(1,0);
        tot_t=1;
        tr[1][0]=tr[1][1]=tr[1][2]=tr[1][3]=0;
        for (int i=1;i<=q[0];i++) ins(1,1,n,i,q[i]);
        for (int i=0;i<m;i++)
        {
            cin>>s;
            if (s[0]=='A')
            {
                int x,y,num;
                scanf("%d%d%d",&num,&x,&y);
                if (y>x) {int z=x;x=y;y=z;}
                num--;
                int node;
                if (fa[g[num][0]]==g[num][1]) {node=g[num][0];} else node=g[num][1];
                if (b[node][1]-b[node][0]+1>n-(b[node][1]-b[node][0]+1))
                {
                    add(1,1,n,b[node][0],b[node][1],x);
                    add(1,1,n,1,b[node][0]-1,y);
                    add(1,1,n,b[node][1]+1,n,y);
                }
                if (b[node][1]-b[node][0]+1<n-(b[node][1]-b[node][0]+1))
                {
                    add(1,1,n,b[node][0],b[node][1],y);
                    add(1,1,n,1,b[node][0]-1,x);
                    add(1,1,n,b[node][1]+1,n,x);
                }
            } else
            {

                int num;
                scanf("%d",&num);
                num--;
                int node;
                if (fa[g[num][0]]==g[num][1]) {node=g[num][0];} else node=g[num][1];
                int x=find(1,1,n,b[node][0],b[node][1]),y=max(find(1,1,n,1,b[node][0]-1),find(1,1,n,b[node][1]+1,n));
                if (x>y) {int z=x;x=y;y=z;}
                printf("%d %d\n",x,y);
            }
        }
    }
    return 0;
}

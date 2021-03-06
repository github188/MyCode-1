#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
#define N 310000
bool used[N],prime[2001],c[1500001],b[N];
int p[2001],e[2*N],v[N],next[2*N];
int tot,n,totl,totc,qsize;
long long ans;
/*
struct node
{
    int l,r;
    long long v;
} len[5*N],cnt[5*N];
*/
long long len[N+N],cnt[N+N];

long long f=0;

inline void add(int x,int y)
{
    e[++tot]=y;
    next[tot]=v[x];
    v[x]=tot;
}

struct mark_ts
{
    int o,fa;
};
stack<mark_ts> treesize_st;
inline int treesize(int o,int fa)
{
    int ans=0;
    mark_ts tmpt;
    tmpt.o=o;tmpt.fa=fa;
    treesize_st.push(tmpt);ans++;
    while (!treesize_st.empty())
    {
        mark_ts tmp=treesize_st.top();treesize_st.pop();
        int j=v[tmp.o];
        while (j>0)
        {
            if ((!used[e[j]])&&(tmp.fa!=e[j]))
            {
                ans++;
                mark_ts tmpt;
                tmpt.o=e[j];tmpt.fa=tmp.o;
                treesize_st.push(tmpt);
            }
            j=next[j];
        }
    }
    return ans;
}

struct centn
{
    int size,o,fa,j,maxn;
};
stack< centn > cents;

inline int cent(int o,int fa,int size,int &maxn,int &s)
{
    centn tmpn;
    tmpn.fa=fa;tmpn.o=o;
    tmpn.j=v[o];tmpn.size=1;
    tmpn.maxn=0;
    cents.push(tmpn);
    while (!cents.empty())
    {
        tmpn=cents.top();cents.pop();
        if (tmpn.j==0)
        {
            if (!cents.empty())
            {
               centn tmp=cents.top();cents.pop();
               tmp.size+=tmpn.size;
               tmp.maxn=tmp.maxn>tmpn.size?tmp.maxn:tmpn.size;
               cents.push(tmp);
            }
            tmpn.maxn=(size-tmpn.size)>tmpn.maxn?(size-tmpn.size):tmpn.maxn;
            if (tmpn.maxn<maxn)
            {
                maxn=tmpn.maxn;
                s=tmpn.o;
            }
        } else
        {
            int k=e[tmpn.j];
            tmpn.j=next[tmpn.j];
            cents.push(tmpn);f++;
            if ((!used[k])&&(tmpn.fa!=k)&&(k>0))
            {
                centn tmp;
                tmp.fa=tmpn.o;tmp.o=k;
                tmp.j=v[k];tmp.size=1;
                tmp.maxn=0;
                cents.push(tmp);
            }
        }
    }
    return 0;
}

 void insert(long long tr[],int &tot,int o,int p,int q,int pos,long long val)
{
    pos=pos-N+qsize;
    pos=qsize+qsize-pos+1;
    int ss=qsize+qsize+1;
     while (pos <= ss)
     {
       tr[pos] += val;
       pos += (pos & -pos);
     }
    /*
    tr[o].v+=val;
    if (p==q) return;
    int mid=(p+q)/2;
    if (pos<=mid)
    {
        if (tr[o].l==0)
        {
            tr[o].l=++tot;
            tr[tot].l=tr[tot].r=tr[tot].v=0;
        }
        insert(tr,tot,tr[o].l,p,mid,pos,val);
    } else
    {
        if (tr[o].r==0)
        {
            tr[o].r=++tot;
            tr[tot].l=tr[tot].r=tr[tot].v=0;
        }
        insert(tr,tot,tr[o].r,mid+1,q,pos,val);
    }*/
}

long long find(long long tr[],int &tot,int o,int p,int q,int pos)
{/*
    if (p==q) return tr[o].v;
    int mid=(p+q)/2;
    if (pos>mid)
    {
        if (tr[o].r==0) return 0;
        else return find(tr,tot,tr[o].r,mid+1,q,pos);
    } else
    {
        long long ans=0;
        if (tr[o].r>0) ans+=tr[tr[o].r].v;
        if (tr[o].l>0) ans+=find(tr,tot,tr[o].l,p,mid,pos);
        return ans;
    }*/
    pos=pos-N+qsize;
    pos=qsize+qsize-pos+1;
    int ss=qsize+qsize+1;
    long long sum = 0;
    while (pos > 0){
      sum += tr[pos];
      pos -= (pos & -pos);
      }
 return sum;
}

struct bfs1
{
    int root,v,l,fa;
};
stack< bfs1 > bs1;

inline void dfs1(int root,int fa,int v1,int l)
{
    bfs1 tmpb;
    tmpb.fa=fa;tmpb.root=root;
    tmpb.l=l;tmpb.v=v1;
    bs1.push(tmpb);
    while (!bs1.empty())
    {
        tmpb=bs1.top();bs1.pop();
        int j=v[tmpb.root];
        if (b[tmpb.root]) tmpb.v--; else tmpb.v++;
        ans+=find(len,totl,1,0,N+N,tmpb.v);
        ans+=(long long)tmpb.l*find(cnt,totc,1,0,N+N,tmpb.v);
        while (j>0)
        {
            if ((e[j]!=tmpb.fa)&&(!used[e[j]]))
            {
                bfs1 tmp;
                tmp.fa=tmpb.root;tmp.root=e[j];
                tmp.l=tmpb.l+1;tmp.v=tmpb.v;
                bs1.push(tmp);
            }
            j=next[j];
        }
    }
}

inline void dfs2(int root,int fa,int v1,int l)
{
    bfs1 tmpb;
    tmpb.fa=fa;tmpb.root=root;
    tmpb.l=l;tmpb.v=v1;
    bs1.push(tmpb);
    while (!bs1.empty())
    {
        tmpb=bs1.top();bs1.pop();
        int j=v[tmpb.root];
        if (b[tmpb.root]) tmpb.v++; else tmpb.v--;
        insert(len,totl,1,0,N+N,tmpb.v,tmpb.l);
        insert(cnt,totc,1,0,N+N,tmpb.v,1);
        while (j>0)
        {
            if ((e[j]!=tmpb.fa)&&(!used[e[j]]))
            {
                bfs1 tmp;
                tmp.fa=tmpb.root;tmp.root=e[j];
                tmp.l=tmpb.l+1;tmp.v=tmpb.v;
                bs1.push(tmp);
            }
            j=next[j];
        }
    }
}

void work(int root)
{
    int size=treesize(root,-1),maxn=1e9,s=0;qsize=size;
    memset(len,0,sizeof(long long)*2*size+2);
    memset(cnt,0,sizeof(long long)*2*size+2);
    if (size!=1)
    {
        cent(root,-1,size,maxn,s);
        root=s;
    }
    //totl=totc=1;
    //len[1].l=len[1].r=len[1].v=0;
    //cnt[1].l=cnt[1].r=cnt[1].v=0;
    int j=v[root],br=0;
    if (b[root]) br=1; else br=-1;
    insert(len,totl,1,0,N+N,N+br,1);
    insert(cnt,totc,1,0,N+N,N+br,1);
    if (b[root]) ans++;
    while (j>0)
    {
        if (!used[e[j]])
        {
            dfs1(e[j],root,N,1);
            dfs2(e[j],root,N+br,2);
        }
        j=next[j];
    }
    used[root]=true;
    j=v[root];
    while (j>0)
    {
        if (!used[e[j]]) work(e[j]);
        j=next[j];
    }
}

int main()
{
    //freopen("1.in","r",stdin);
    for (int i=3;i<2001;i+=2)
    if (!prime[i])
    {
        p[++p[0]]=i;
        int j=i+i;
        while (j<2001)
        {
            prime[j]=true;
            j+=i;
        }
    }
    for (int i=1;i<=1500000;i++)
    if ((i&1)==0)
    {
        int j=i;
        while ((j&1)==0) j>>=1;
        c[i]=c[j];
    } else
    {
        int j=i;
        bool mark=true;
        for (int k=1;k<=p[0];k++)
        if ((j%p[k])==0)
        {
            int l=0;
            while ((j%p[k])==0) j/=p[k],l++;
            mark&=((l&1)==0);
            if ((j==1)||(!mark)) break;
        }
        if (j>1) mark=false;
        c[i]=mark;
    }
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        b[i]=c[x];
    }
    ans=0;
    work(1);
    cout<<ans<<endl;
    return 0;
}



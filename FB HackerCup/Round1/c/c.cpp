#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
struct pt
{
    int x,y;
    bool operator<(const pt &b) const
    {
        return ((x<b.x)||((x==b.x)&&(y<b.y)));
    }
} f[1000000];
int W,H,P,Q,n,X,Y,a,b,c,d,tot,sum,h,t;
struct node
{
    int l,r,v;
} tr[10000000];
int num[50000],head[50000],tail[50000],q[5000000];

int find(int o,int l,int r,int p)
{
    if ((l==r)||(tr[o].v>=0)) return tr[o].v;
    int mid=(l+r)/2;
    if (p<=mid) return find(tr[o].l,l,mid,p);
    else return find(tr[o].r,mid+1,r,p);
}

void insert(int o,int l,int r,int p,int q,int s)
{
    if (q<p) return;
    if ((p<=l)&&(r<=q))
    {
        tr[o].l=tr[o].r=0;
        tr[o].v=s;return;
    }
    if (tr[o].v>=0)
    {
        int tmpv=tr[o].v;tr[o].v=-1;
        tr[o].l=++tot;
        tr[tot].l=tr[tot].r=0;tr[tot].v=tmpv;
        tr[o].r=++tot;
        tr[tot].l=tr[tot].r=0;tr[tot].v=tmpv;
    }
    int mid=(l+r)/2;
    if (p<=mid) insert(tr[o].l,l,mid,p,q,s);
    if (q>mid) insert(tr[o].r,mid+1,r,p,q,s);
}

void divide(int p)
{
    if (num[p]==0)
    {
        int h1=find(1,0,H-1,p),t1=head[h1];
        head[h1]=p-1;tail[t1]=p+1;
        tail[p-1]=h1;head[p+1]=t1;
        insert(1,0,H-1,h1,p-1,h1);
        insert(1,0,H-1,p,p,-2);
        insert(1,0,H-1,p+1,t1,p+1);
        if (t1-h1+1>=Q)
        {
            sum-=t1-h1+2-Q;
            int p1=p-1,p2=p+1;
            if (p1-h1+1>=Q) sum+=p1-h1+2-Q;
            if (t1-p2+1>=Q) sum+=t1-p2+2-Q;
        }
    }
    num[p]++;
}

void merge(int p)
{
    num[p]--;
    if (num[p]==0)
    {
        int h1=tail[p-1],t1=head[p+1];
        head[h1]=t1;tail[t1]=h1;
        insert(1,0,H-1,h1,t1,h1);
        if (t1-h1+1>=Q)
        {
            int p1=p-1,p2=p+1;
            if (p1-h1+1>=Q) sum-=p1-h1+2-Q;
            if (t1-p2+1>=Q) sum-=t1-p2+2-Q;
            sum+=t1-h1+2-Q;
        }
    }
}

int work()
{
    int ans=0;
    sum=H-Q+1;
    tot=1;
    h=0,t=-1;
    memset(num,0,sizeof(num));
    memset(head,0,sizeof(head));
    memset(tail,0,sizeof(tail));
    tr[1].l=tr[1].r=tr[1].v=0;
    head[0]=H-1;tail[H-1]=0;
    int p=0;
    while ((p<n)&&(f[p].x<P)) {q[++t]=p;divide(f[p++].y);}
    ans+=sum;
    for (int i=P;i<W;i++)
    {
        while ((h<=t)&&(f[q[h]].x<=i-P)) merge(f[q[h++]].y);
        while ((p<n)&&(f[p].x==i)) {q[++t]=p;divide(f[p++].y);}
        ans+=sum;
    }
    return ans;
}

int main()
{
    freopen("3.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d%d%d%d%d%d%d%d%d%d",&W,&H,&P,&Q,&n,&X,&Y,&a,&b,&c,&d);
        f[0].x=X;f[0].y=Y;
        for (int i=1;i<n;i++)
        {
            f[i].x=(f[i-1].x*a+f[i-1].y*b+1)%W;
            f[i].y=(f[i-1].x*c+f[i-1].y*d+1)%H;
        }
        sort(f,f+n);
        printf("Case #%d: %d\n",t,work());
    }
    return 0;
}

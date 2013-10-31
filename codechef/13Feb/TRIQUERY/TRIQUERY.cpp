#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node
{
    int l,r,v;
} tr[3000000];
struct point
{
    int x,y,xy,xyd;
    int d,ind;
} a[400000],query[400000];
int ans[400000],inda[400000],indq[400000];
int n,q,tot;

inline bool qcmpx(int x,int y)
{
    return query[x].x<query[y].x;
}

inline bool cmpxy(int x,int y)
{
    return a[x].xy<a[y].xy;
}

inline bool cmpx(int x,int y)
{
    return a[x].x<a[y].x;
}

inline bool qcmpxyd(int x,int y)
{
    return query[x].xyd<query[y].xyd;
}


void insert(int o,int l,int r,int p)
{
    tr[o].v++;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (p<=mid)
    {
        if (tr[o].l==0)
        {
            tr[o].l=++tot;
            tr[tot].l=tr[tot].r=tr[tot].v=0;
        }
        insert(tr[o].l,l,mid,p);
    } else
    {
        if (tr[o].r==0)
        {
            tr[o].r=++tot;
            tr[tot].l=tr[tot].r=tr[tot].v=0;
        }
        insert(tr[o].r,mid+1,r,p);
    }
}

int find(int o,int l,int r,int p,int q)
{
    if ((p<=l)&&(r<=q)) return tr[o].v;
    int mid=(l+r)>>1,ans=0;
    if (p<=mid)
    {
        if (tr[o].l!=0) ans+=find(tr[o].l,l,mid,p,q);
    }
    if (q>mid)
    {
        if (tr[o].r!=0) ans+=find(tr[o].r,mid+1,r,p,q);
    }
    return ans;
}

int main()
{
    //freopen("1.out","r",stdin);
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) {scanf("%d%d",&a[i].x,&a[i].y);a[i].xy=a[i].x+a[i].y;inda[i]=i;}
    for (int i=0;i<q;i++)
    {
        scanf("%d%d%d",&query[i].x,&query[i].y,&query[i].d);
        query[i].ind=i;
        query[i].xy=query[i].x+query[i].y;
        query[i].xyd=query[i].x+query[i].y+query[i].d;
        indq[i]=i;
    }

    tot=1;
    tr[1].l=tr[1].r=tr[1].v=0;
    sort(indq,indq+q,qcmpxyd);
    sort(inda,inda+n,cmpxy);
    int h=0;
    for (int i=0;i<q;i++)
    {
        while ((h<n)&&(a[inda[h]].x+a[inda[h]].y<=query[indq[i]].x+query[indq[i]].y+query[indq[i]].d)) insert(1,0,300000,a[inda[h++]].y);
        ans[query[indq[i]].ind]+=find(1,0,300000,query[indq[i]].y,query[indq[i]].y+query[indq[i]].d);
    }

    tot=1;
    tr[1].l=tr[1].r=tr[1].v=0;
    sort(indq,indq+q,qcmpx);
    sort(inda,inda+n,cmpx);
    h=0;
    for (int i=0;i<q;i++)
    {
        while ((h<n)&&(a[inda[h]].x<query[indq[i]].x)) insert(1,0,300000,a[inda[h++]].y);
        ans[query[indq[i]].ind]-=find(1,0,300000,query[indq[i]].y,query[indq[i]].y+query[indq[i]].d);
    }
    for (int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

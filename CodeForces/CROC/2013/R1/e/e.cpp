#include<stdio.h>
struct node
{
    int l,r,v;
} tr[5000000];
int a[100001],b[100001],c[100001],c1[100001];
int tot=0,tot1=0;
int n,m;

int newnode()
{
    tr[++tot].l=tr[tot].r=tr[tot].v=-1;
    return tot;
}

void ins(int o,int l,int r,int p,int q,int s)
{
    if ((p<=l)&&(r<=q)) {tr[o].v=s;return;}
    if (tr[o].v>=0){
    int tmp=tr[o].v;tr[o].v=-1;
    if (tr[o].l<0) tr[o].l=newnode();tr[tr[o].l].v=tmp;
    if (tr[o].r<0) tr[o].r=newnode();tr[tr[o].r].v=tmp;}
    int mid=(l+r)/2;
    if (p<=mid)
    {if (tr[o].l<0) tr[o].l=newnode();ins(tr[o].l,l,mid,p,q,s);}
    if (q>mid)
    {if (tr[o].r<0) tr[o].r=newnode();ins(tr[o].r,mid+1,r,p,q,s);}
}

int find(int o,int l,int r,int p)
{
    if (l==r) return tr[o].v;
    int mid=(l+r)/2;
    if (tr[o].v>=0) return tr[o].v;
    if (p<=mid)
    {
        if (tr[o].l<0) return -1;
        return find(tr[o].l,l,mid,p);
    }
    if (p>mid)
    {
        if (tr[o].r<0) return -1;
        return find(tr[o].r,mid+1,r,p);
    }
}

int main()
{
    newnode();
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==1)
        {
            int d,e,f;
            scanf("%d%d%d",&d,&e,&f);
            c[tot1]=d;c1[tot1]=e;
            ins(1,1,n,e,e+f-1,tot1);
            tot1++;
        } else
        {
            int d,e,ans;scanf("%d",&d);
            e=find(1,1,n,d);
            if (e<0) ans=b[d]; else ans=a[c[e]+d-c1[e]];
            printf("%d\n",ans);
        }
    }
}

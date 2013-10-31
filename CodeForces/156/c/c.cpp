#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    int l,r;
    bool s;
} tr[4000000];
int tot=0;
long long two=2,one=1;

inline node pos(long long x)
{
    node ans;
    long long l=1,r=x,xx=x-one;
    while (l<r)
    {
        long long mid=(l+r)>>1;mid++;
        if (((x/mid)/mid)==0) r=mid-one; else l=mid;
    }
    ans.r=r;
    l=1;r++;
    while (l<r)
    {
        long long mid=(l+r)>>1;
        if (mid==0) l=mid+one; else
        if (((((xx/mid)/mid)/mid)/mid)==0) r=mid; else l=mid+one;
    }
    ans.l=l;
    if (ans.r==x) ans.r--;
    return ans;
}

bool find(int o,int l,int r,int p,int q)
{
    if (q<p) return false;
    if ((p<=l)&&(r<=q)) return tr[o].s;
    int mid=(l+r)/2;
    bool ans=true;
    if (p<=mid) ans&=find(tr[o].l,l,mid,p,q);
    if (mid<q) ans&=find(tr[o].r,mid+1,r,p,q);
    return ans;
}

inline int newnode()
{
    tot++;
    tr[tot].l=tr[tot].r=0;
    tr[tot].s=true;
    return tot;
}

void ins(int o,int l,int r,int p,int s)
{
    if (l==r)
    {
        tr[o].s=s;
        return;
    }
    int mid=(l+r)/2;
    if (p<=mid)
    {
        if (tr[o].l==0) tr[o].l=newnode();
        ins(tr[o].l,l,mid,p,s);
    } else
    {
        if (tr[o].r==0) tr[o].r=newnode();
        ins(tr[o].r,mid+1,r,p,s);
    }
    tr[o].s=true;
    if ((tr[o].l>0)&&(!tr[tr[o].l].s)) tr[o].s=false;
    if ((tr[o].r>0)&&(!tr[tr[o].r].s)) tr[o].s=false;
}

int main()
{
    int m=881917;
    tot=1;
    tr[1].l=tr[1].r=0;tr[1].s=true;
    for (int i=1;i<=m;i++)
    {
        node tmp=pos(i);
        bool s=!find(1,1,m,tmp.l,tmp.r);
        ins(1,1,m,i,s);
    }
    int n;scanf("%d",&n);
    int ans=0;
    while (n--)
    {
        long long x;
        scanf("%I64d",&x);
        //cin>>x;
        node tmp=pos(x);
        bool s=find(1,1,m,tmp.l,tmp.r);
        if (s) ans^=1;
    }
    if (ans==0) printf("Rublo\n");
    else printf("Furlo\n");
    return 0;
}

#include<stdio.h>

struct node
{
    int ls,rs,size,fa,res,val;
};

node tree[110000];
int n,m,tot,root;
int ans[110000];

void init(int o,int l,int r)
{
    int mid=(l+r)/2;
    tree[o].val=mid;
    tree[o].ls=tree[o].rs=-1;
    tree[o].size=r-l+1;
    tree[o].res=0;
    if (l<=mid-1)
    {
        tot++;
        tree[o].ls=tot;
        tree[tot].fa=o;
        init(tot,l,mid-1);
    }
    if (mid+1<=r)
    {
        tot++;
        tree[o].rs=tot;
        tree[tot].fa=o;
        init(tot,mid+1,r);
    }
}

void swip(int o)
{
    tree[o].res=0;
    int l=tree[o].ls,r=tree[o].rs;
    tree[o].ls=r;tree[o].rs=l;
    if (l!=-1) tree[l].res^=1;
    if (r!=-1) tree[r].res^=1;
}

int get_num(int root,int num)
{
    if (tree[root].res==1) swip(root);
    int l=tree[root].ls,r=tree[root].rs;
    if ((l!=-1)&&(tree[l].size>=num))
    {
        return get_num(l,num);
    } else {if (l!=-1) num-=tree[l].size;}
    if (num==1) return root;
    num--;
    return get_num(r,num);
}

void zig(int o)
{
    int fa=tree[o].fa,fa1=tree[fa].fa;
    if (fa==root) {root=o;} else
    {
        if (tree[fa1].ls==fa) {tree[fa1].ls=o;}
        else {tree[fa1].rs=o;}
    }
    node tmp=tree[fa];
    tree[fa].fa=o;
    tree[fa].ls=tree[o].rs;
    tree[tree[o].rs].fa=fa;
    int sum=1;
    if (tree[fa].ls!=-1) sum+=tree[tree[fa].ls].size;
    if (tree[fa].rs!=-1) sum+=tree[tree[fa].rs].size;
    tree[fa].size=sum;

    tree[o].fa=tmp.fa;
    tree[o].rs=fa;
    sum=1;
    if (tree[o].ls!=-1) sum+=tree[tree[o].ls].size;
    if (tree[o].rs!=-1) sum+=tree[tree[o].rs].size;
    tree[o].size=sum;
}

void zag(int o)
{
    int fa=tree[o].fa,fa1=tree[fa].fa;
    if (fa==root) {root=o;} else
    {
        if (tree[fa1].ls==fa) {tree[fa1].ls=o;}
        else {tree[fa1].rs=o;}
    }
    node tmp=tree[fa];
    tree[fa].fa=o;
    tree[fa].rs=tree[o].ls;
    tree[tree[o].ls].fa=fa;
    int sum=1;
    if (tree[fa].ls!=-1) sum+=tree[tree[fa].ls].size;
    if (tree[fa].rs!=-1) sum+=tree[tree[fa].rs].size;
    tree[fa].size=sum;

    tree[o].fa=tmp.fa;
    tree[o].ls=fa;
    sum=1;
    if (tree[o].ls!=-1) sum+=tree[tree[o].ls].size;
    if (tree[o].rs!=-1) sum+=tree[tree[o].rs].size;
    tree[o].size=sum;
}

void op(int o)
{
    if (o==root) return;
    if (tree[o].fa==root)
    {
        if (tree[root].ls==o) {zig(o);}
        else {zag(o);}
        return;
    }

    int u,v,w;
    w=tree[o].fa;
    u=0;
    if (tree[w].rs==o) {u=1;}
    v=0;
    if (tree[tree[w].fa].rs==w) {v=1;}
    if (u==v)
    {
        if (u==0)
        {
            zig(w);
            zig(o);
        } else
        {
            zag(w);
            zag(o);
        }
    } else
    {
        if (u==0)
        {
            zig(o);
            zag(o);
        } else
        {
            zag(o);
            zig(o);
        }
    }

    op(o);
}

void splay(int root,int num)
{
    int o=get_num(root,num);
    if (o!=root) op(o);
}

int del()
{
    int ans=tree[root].ls;
    if (ans!=-1)
    {
        tree[root].size-=tree[ans].size;
        tree[root].ls=-1;
        tree[ans].fa=-1;
    }
    return ans;
}

void ins(int o)
{
    tree[root].size+=tree[o].size;
    tree[root].ls=o;
    tree[o].fa=root;
}

void out(int o)
{
    if (tree[o].res==1) swip(o);
    if (tree[o].ls!=-1) out(tree[o].ls);
    ans[0]++;
    ans[ans[0]]=tree[o].val;
    if (tree[o].rs!=-1) out(tree[o].rs);
}

int main()
{
    tot=0;
    scanf("%d%d",&n,&m);
    init(0,1,n+1);
    root=0;

    for (int i=0;i<m;i++)
    {
        int x,y,z,a,b,c;
        scanf("%d%d%d",&x,&y,&z);
        splay(root,x+1);
        a=del();
        splay(root,y+1);
        b=del();
        if (b!=-1) tree[b].res^=1;
        if (a!=-1) ins(a);
        splay(root,z+1);
        c=del();
        if (b!=-1) ins(b);
        splay(root,1);
        if (c!=-1) ins(c);
    }
    ans[0]=0;
    out(root);
    for (int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);

    return 0;
}

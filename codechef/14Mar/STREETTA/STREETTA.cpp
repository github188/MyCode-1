#include<stdio.h>
struct node
{
    int left,right;
    long long a1,b1,a2,b2;
    bool has_item;
} Tree[30000000];
int tot=0;

int CreateNewNode()
{
    tot++;
    Tree[tot].left=Tree[tot].right=0;
    Tree[tot].a1=Tree[tot].a2=0;
    Tree[tot].b1=Tree[tot].b2=0;
    Tree[tot].has_item=false;
    return tot;
}

int GetMaxPos(int L,int R,long long ta,long long tb,long long a,long long b,int status)
{
    int left=L,right=R;
    while (left<right)
    {
        int mid=(left+right)/2+1;
        long long tvalue=(long long)(mid-L)*tb+ta,value=(long long)(mid-L)*b+a;
        if (status==0)
        {
            if (tvalue>=value) left=mid;
            else right=mid-1;
        } else
        {
            if (tvalue<value) left=mid;
            else right=mid-1;
        }
    }
    return left;
}

void InsertItem(int o,int L,int R,int u,int v,long long a,long long b)
{
    if ((u<=L)&&(R<=v))
    if (!Tree[o].has_item)
    {
        Tree[o].has_item=true;
        Tree[o].a1=a+(long long)(L-u)*b;Tree[o].b1=b;
        return;
    }
    else
    {
        long long new_max,old_max;
        new_max=(long long)(R-u)*b+a;
        old_max=(long long)(R-L)*Tree[o].b1+Tree[o].a1;
        if (Tree[o].a1>=a+(long long)(L-u)*b)
        {
            if (old_max>=new_max) return;
            int new_u=GetMaxPos(L,R,Tree[o].a1,Tree[o].b1,a+(long long)(L-u)*b,b,0)+1;
            a=(long long)(new_u-u)*b+a;
            u=new_u;
        } else
        if (old_max>=new_max)
        {
            v=GetMaxPos(L,R,Tree[o].a1,Tree[o].b1,a+(long long)(L-u)*b,b,1);
        } else
        {
            Tree[o].a1=a+(long long)(L-u)*b;
            Tree[o].b1=b;
            return;
        }
    }
    int mid=(L+R)/2;
    if (u<=mid)
    {
        if (Tree[o].left==0) Tree[o].left=CreateNewNode();
        InsertItem(Tree[o].left,L,mid,u,v,a,b);
    }
    if (v>mid)
    {
        if (Tree[o].right==0) Tree[o].right=CreateNewNode();
        InsertItem(Tree[o].right,mid+1,R,u,v,a,b);
    }
}

void InsertTax(int o,int L,int R,int u,int v,long long a,long long b)
{
    if ((u<=L)&&(R<=v))
    {
        Tree[o].a2+=a+(L-u)*b;
        Tree[o].b2+=b;
        return;
    }
    int mid=(L+R)/2;
    if (u<=mid)
    {
        if (Tree[o].left==0) Tree[o].left=CreateNewNode();
        InsertTax(Tree[o].left,L,mid,u,v,a,b);
    }
    if (v>mid)
    {
        if (Tree[o].right==0) Tree[o].right=CreateNewNode();
        InsertTax(Tree[o].right,mid+1,R,u,v,a,b);
    }
}

void FindMaxCost(int o,int L,int R,int pos,long long &item,long long &tax,bool &has_item)
{
    if (Tree[o].has_item)
    {
        if ((!has_item)||((long long)(pos-L)*Tree[o].b1+Tree[o].a1>item)) item=(long long)(pos-L)*Tree[o].b1+Tree[o].a1;
        has_item=true;
    }
    tax+=(long long)(pos-L)*Tree[o].b2+Tree[o].a2;
    if (L==R) return;
    int mid=(L+R)/2;
    if (pos<=mid)
    {
        if (Tree[o].left>0) FindMaxCost(Tree[o].left,L,mid,pos,item,tax,has_item);
    }
    if (pos>mid)
    {
        if (Tree[o].right>0) FindMaxCost(Tree[o].right,mid+1,R,pos,item,tax,has_item);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    CreateNewNode();
    for (int i=0;i<m;i++)
    {
        int x;scanf("%d",&x);
        if (x==1)
        {
            int u,v,a,b;scanf("%d%d%d%d",&u,&v,&a,&b);
            InsertItem(1,1,n,u,v,b,a);
        } else
        if (x==2)
        {
            int u,v,a,b;scanf("%d%d%d%d",&u,&v,&a,&b);
            InsertTax(1,1,n,u,v,b,a);
        } else
        {
            int pos;scanf("%d",&pos);
            long long item=0,tax=0;
            bool has_item=false;
            FindMaxCost(1,1,n,pos,item,tax,has_item);
            if (has_item) printf("%lld\n",item+tax); else printf("NA\n");
        }
    }
    return 0;
}

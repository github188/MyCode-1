#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
    int l,r,min,max;
} tr[500000];
int n,q,l,r,tot;

int newnode()
{
    tr[++tot].l=tr[tot].r=tr[tot].max=0;tr[tot].min=1e9;
    return tot;
}

void insert(int o,int p,int q,int pos,int v)
{
    if (p==q)
    {
        tr[o].min=tr[o].max=v;
        return;
    }
    int mid=((p+q)>>1);
    if (pos<=mid)
    {
        if (tr[o].l==0) tr[o].l=newnode();
        insert(tr[o].l,p,mid,pos,v);
    } else
    {
        if (tr[o].r==0) tr[o].r=newnode();
        insert(tr[o].r,mid+1,q,pos,v);
    }
    tr[o].min=tr[o].min<v?tr[o].min:v;
    tr[o].max=tr[o].max>v?tr[o].max:v;
}

double findmin(int o,int p,int q,int l,int r)
{
    if ((l<=p)&&(q<=r)) return tr[o].min;
    int mid=((p+q)>>1);
    double ans=1e9;
    if (l<=mid)
    {
        double tmp=findmin(tr[o].l,p,mid,l,r);
        ans=ans<tmp?ans:tmp;
    }
    if (mid<r)
    {
        double tmp=findmin(tr[o].r,mid+1,q,l,r);
        ans=ans<tmp?ans:tmp;
    }
    return ans;
}

double findmax(int o,int p,int q,int l,int r)
{
    if ((l<=p)&&(q<=r)) return tr[o].max;
    int mid=((p+q)>>1);
    double ans=0;
    if (l<=mid)
    {
        double tmp=findmax(tr[o].l,p,mid,l,r);
        ans=ans>tmp?ans:tmp;
    }
    if (mid<r)
    {
        double tmp=findmax(tr[o].r,mid+1,q,l,r);
        ans=ans>tmp?ans:tmp;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    tot=0;
    newnode();
    for (int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        insert(1,0,n-1,i,x);
    }
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d",&l,&r);
        int tmp=findmin(1,0,n-1,l,r);
        double tmpmax=(findmax(1,0,n-1,l,r)+tmp)/2.0;
        if (l>0) tmpmax=max(tmpmax,tmp+findmax(1,0,n-1,0,l-1));
        if (r<n-1) tmpmax=max(tmpmax,tmp+findmax(1,0,n-1,r+1,n-1));
        printf("%.1f\n",tmpmax);
    }
    return 0;
}

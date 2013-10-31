#include<stdio.h>
using namespace std;
int n,tot;
struct node
{
    int l,r,num;
    long long sum,mul;
} tr[1000000];
long long mod=1000000007;
long long a;

int newnode()
{
    tot++;
    tr[tot].l=tr[tot].r;
    tr[tot].sum=0;tr[tot].mul=1;
    tr[tot].num=0;
    return tot;
}

void insert(int o,int l,int r,int p)
{
    long long pp=p;
    if (l==r)
    {
        tr[o].mul=(tr[o].mul*pp)%mod;
        tr[o].sum=(tr[o].sum*pp+pp*pp)%mod;
        tr[o].num++;
        return;
    }
    int mid=(l+r)/2;
    if (p<=mid)
    {
        if (tr[o].l==0) tr[o].l=newnode();
        insert(tr[o].l,l,mid,p);
    } else
    {
        if (tr[o].r==0) tr[o].r=newnode();
        insert(tr[o].r,mid+1,r,p);
    }
    tr[o].num=tr[o].sum=0;
    tr[o].mul=1;
    if (tr[o].l!=0)
    {
        tr[o].num+=tr[tr[o].l].num;
        tr[o].sum+=tr[tr[o].l].sum;
        tr[o].mul*=tr[tr[o].l].mul;
    }
    if (tr[o].r!=0)
    {
        tr[o].num+=tr[tr[o].r].num;
        tr[o].sum=(tr[o].sum*tr[tr[o].r].mul+tr[tr[o].r].sum)%mod;
        tr[o].mul=(tr[o].mul*tr[tr[o].r].mul);
    }
}

int main()
{
    tot=0;
    scanf("%d",&n);
    scanf("%I64d",&a);a%=mod;
    printf("%I64d\n",a);
    newnode();
    insert(1,0,mod-1,a);
    for (int i=1;i<n;i++)
    {
        scanf("%I64d",&a);
        long long b=(tr[1].sum+a)%mod;
        printf("%I64d\n",b);
        insert(1,0,mod-1,b);
    }
    return 0;
}

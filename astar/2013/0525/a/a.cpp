#include<stdio.h>
#include<math.h>
struct node
{
    int l,r;
    bool s;
} tr[1000000];
int tot;
int l[50000],sum[50000];
int w,n,x,y,z;

int newnode()
{
    tot++;
    tr[tot].l=tr[tot].r=0;tr[tot].s=false;
    return tot;
}

void ins(int o,int l,int r,int p)
{
    tr[o].s=true;
    if (l==r) return;
    int mid=(l+r)/2;
    if (p<=mid)
    {
        if (tr[o].l==0) tr[o].l=newnode();
        ins(tr[o].l,l,mid,p);
    } else
    {
        if (tr[o].r==0) tr[o].r=newnode();
        ins(tr[o].r,mid+1,r,p);
    }
}

bool find(int o,int l,int r,int p,int q)
{
    if ((p<=l)&&(r<=q)) return tr[o].s;
    int mid=(l+r)/2;
    bool ans=false;
    if (p<=mid)
    {
        if (tr[o].l!=0) ans|=find(tr[o].l,l,mid,p,q);
    }
    if (mid<q)
    {
        if (tr[o].r!=0) ans|=find(tr[o].r,mid+1,r,p,q);
    }
    return ans;
}

bool check(int len)
{
    tot=0;
    newnode();
    int h1=0,h2=0;
    while ((l[h1]==len)&&(h1<n)) {h1++;h2++;}
    if (h1==n) return true;
    for (int i=1;i<n;i++)
    {
        while ((h1<i)&&(sum[i]-sum[h1]+l[h1]+i-h1>w)) h1++;
        while ((h2<i)&&((sum[i]-sum[h2]+(i-h2-1)*len>=w)&&((h2+1<i)||(l[i]==w)))) h2++;
        if (i==n-1)
        {
            return find(1,0,n-1,h1-1,i-1);
        } else
        if (((h1==0)&&(sum[i]+len*i>=w))||(((h1!=i)||(l[i]==w))&&(find(1,0,n-1,h1-1,h2-1)))) ins(1,0,n-1,i);
    }
    return true;
}

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d%d%d%d%d",&w,&n,&x,&y,&z);
        int p=floor(double(w-1)/2.0);
        l[0]=sum[0]=x%p+1;
        for (int i=1;i<n;i++) {l[i]=(l[i-1]*y+z)%p+1;sum[i]=sum[i-1]+l[i];}
        int l=0,r=w;
        while (l<r)
        {
            int mid=(l+r)/2;
            if (check(mid)) r=mid; else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}

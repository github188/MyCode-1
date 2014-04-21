#include<stdio.h>
#include<string.h>
char s[10000000];
long long a[10000000],b[10000000],c[10000000];
long long ans,maxn;
struct node
{
    int l,r;
    long long num;
} tr[20000000];
int tot=0;
long long maxm=1000000000;

void mergesort(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int h1=l,h2=mid+1,h3=0;
    while ((h1<=mid)&&(h2<=r))
    {
        if (a[h1]<=a[h2])
        {
            b[h3++]=a[h1++];
        } else
        {
            b[h3]=a[h2++];
            ans+=(long long)(mid-h1+1);
            h3++;
        }
    }
    while (h1<=mid) b[h3++]=a[h1++];
    while (h2<=r) b[h3++]=a[h2++];
    for (int i=l;i<=r;i++) a[i]=b[i-l];
}

int newnode()
{
    tot++;
    tr[tot].l=tr[tot].r=tr[tot].num=0;
    return tot;
}

void insert(int o,int p,int q,int v)
{
    tr[o].num++;
    if (p==q) return;
    int mid=(p+q)/2;
    if (v<=mid)
    {
        if (tr[o].l==0) tr[o].l=newnode();
        insert(tr[o].l,p,mid,v);
    } else
    {
        if (tr[o].r==0) tr[o].r=newnode();
        insert(tr[o].r,mid+1,q,v);
    }
}

long long find_mi(int o,int p,int q,int v)
{
    if (q<v) return tr[o].num;
    int mid=(p+q)/2;
    if (mid<v)
    {
        int ans=0;
        if (tr[o].l>0) ans=tr[tr[o].l].num;
        if (tr[o].r>0) ans+=find_mi(tr[o].r,mid+1,q,v);
        return ans;
    } else if (tr[o].l>0) return find_mi(tr[o].l,p,mid,v);
}

long long find_ma(int o,int p,int q,int v)
{
    if (v<p) return tr[o].num;
    int mid=(p+q)/2;
    if (v<=mid)
    {
        int ans=0;
        if (tr[o].r>0) ans=tr[tr[o].r].num;
        if (tr[o].l>0) ans+=find_ma(tr[o].l,p,mid,v);
        return ans;
    } else if (tr[o].r>0) return find_ma(tr[o].r,mid+1,q,v);
}

int main()
{
    maxm*=maxm;
    while(gets(s))
    {
        int n=0,m=strlen(s);
        ans=0;maxn=0;
        int h=0;
        while (h<m)
        {
            long long num=0,sign=1,ten=10;
            if (s[h]=='-') sign=-1;
            while ((h<m)&&(s[h]!=','))
            {
                num=num*ten+(long long)(s[h++]-'0');
            }
            h++;
            c[n]=sign*num;
            a[n++]=sign*num;
        }
        mergesort(0,n-1);
        for (int i=0;i<n;i++)
        {
            tot=0;
            newnode();
            insert(1,-maxm,maxm,c[i]);
            int len=0,ma=0,mi=0;
            for (int j=i+1;j<n;j++)
            {
                len++;
                long long temp=find_mi(1,-maxm,maxm,c[j]);
                temp-=find_ma(1,-maxm,maxm,c[j]);
                temp+=(long long)(-mi+ma);
                if (c[j]<c[i]) mi++;
                if (c[j]>c[i]) ma++;
                maxn=(maxn>-temp)?maxn:-temp;
                insert(1,-maxm,maxm,c[j]);
            }
        }
        printf("%lld\n",ans-maxn);
    }
    return 0;
}

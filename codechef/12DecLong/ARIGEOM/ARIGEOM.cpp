#include<stdio.h>
#include<iostream>
using namespace std;
long long a[10000],b[10000],c[10000],f[100001][17];
bool d[100001];
int n,bn,cn;
bool mark;

long long gcd(long long o,long long p)
{
    if (o<p) {long long q=o;o=p;p=q;}
    if (p==0) return o;
    return gcd(p,o%p);
}

int g(long long o,long long p)
{
    int ans=0;long long q=1;
    if (p==1) return (o==p);
    while (q<o) {ans++;q*=p;}
    if (q!=o) ans=-1;return ans;
}

inline bool work(long long &o,long long &p,long long x,long long y)
{
    if (o<x)
    {
        long long q=o;o=x;x=q;
        q=p;p=y;y=q;
    }
    if (o==x) return (p==y);
    bool mark=false;
    for (int i=2;i<=16;i++)
    {
        long long oo=f[o][i],pp=f[p][i];
        if (oo*pp==0) continue;
        long long xx=g(x,oo),yy=g(y,pp);
        if ((xx>0)&&((xx==yy)||((pp==1)&&(y==1)))) mark=true;
        if (mark)
        {
            o=oo;p=pp;
            break;
        }
    }
    return mark;
}

void work1(int o)
{
    int p=b[1]-b[0];
    while (o<n)
    {
        if (a[o]==b[bn-1]+p) b[bn++]=a[o++];
        else c[cn++]=a[o++];
    }
    if (cn==0) {cn=2;c[0]=a[0];c[1]=a[1];mark=true;return;}
    if (cn==1)
    {
        if (c[0]==a[0]) {c[cn++]=a[n-1];}
        else {c[cn]=c[0];c[0]=a[0];cn++;}
        mark=true;return;
    }
    long long u=c[1],v=c[0];
    u/=gcd(c[1],c[0]);v/=gcd(c[1],c[0]);
    for (int i=2;i<cn;i++)
    {
        long long x=c[i],y=c[i-1];
        x/=gcd(c[i],c[i-1]);y/=gcd(c[i],c[i-1]);
        if (!work(u,v,x,y)) return;
    }
    if (u==v) return;
    long long tmp=c[cn-1];
    cn=1;long long uu=100000;
    while (true)
    {
        long long f=c[cn-1]*u;
        if ((f%v)>0) break;f/=v;
        if (f>uu) break;
        if (d[f]) {c[cn++]=f;} else break;
        if (c[cn-1]==tmp) break;
    }
    if (c[cn-1]==tmp) mark=true;
}

void work2(int o)
{
    long long u=c[1],v=c[0];
    u/=gcd(c[1],c[0]);v/=gcd(c[1],c[0]);
    while (o<n)
    {
        if ((((c[cn-1]*u)%v)==0)&&((c[cn-1]*u/v)==a[o])) c[cn++]=a[o++];
        else b[bn++]=a[o++];
    }
    if (bn==0) {bn=2;b[0]=a[0];b[1]=a[1];mark=true;return;}
    if (bn==1)
    {
        if (b[0]==a[0]) {b[bn++]=a[n-1];}
        else {b[bn]=b[0];b[0]=a[0];bn++;}
        mark=true;return;
    }
    long long p=b[1]-b[0];
    for (int i=2;i<bn;i++) p=gcd(p,b[i]-b[i-1]);
    long long tmp=b[bn-1];
    bn=1;
    while (true)
    {
        if (b[bn-1]+p>100000) break;
        if (!d[b[bn-1]+p]) break;
        b[bn]=b[bn-1]+p;bn++;
        if (b[bn-1]==tmp) break;
    }
    if (b[bn-1]==tmp) mark=true;
}

int main()
{
    //freopen("1.txt","r",stdin);
    for (int i=1;i<=16;i++) f[1][i]=1;
    long long uu=100000;
    int v=16;long long num=2;
    while (v>1)
    {
        long long u=num;
        for (int i=2;i<=v;i++)
        {
            u*=num;
            if (u>uu) {v=i-1;break;}
            f[u][i]=num;
        }
        num++;
    }

    int t;scanf("%d",&t);
    while (t--)
    {
        for (int i=0;i<=100000;i++) d[i]=false;
        scanf("%d",&n);
        for (int i=0;i<n;i++) {int tmp;scanf("%d",&tmp);a[i]=tmp;d[tmp]=true;}
        bn=cn=0;
        if (n<4)
        {
            cout<<a[0]<<" "<<a[1]<<endl<<a[0]<<" "<<a[n-1]<<endl;
            continue;
        }
        mark=false;
        if (!mark)
        {
            bn=cn=0;
            b[0]=a[0];
            b[1]=a[1];
            bn=2;
            work1(2);
        }
        if (!mark)
        {
            bn=cn=0;
            b[0]=a[0];
            b[1]=a[2];
            bn=2;
            c[0]=a[1];
            cn=1;
            work1(3);
        }
        if (!mark)
        {
            bn=cn=0;
            b[0]=a[1];
            b[1]=a[2];
            bn=2;
            c[0]=a[0];
            cn=1;
            work1(3);
        }
        if (!mark)
        {
            bn=cn=0;
            c[0]=a[0];
            c[1]=a[1];
            cn=2;
            work2(2);
        }
        if (!mark)
        {
            bn=cn=0;
            c[0]=a[0];
            c[1]=a[2];
            cn=2;
            b[0]=a[1];
            bn=1;
            work2(3);
        }
        if (!mark)
        {
            bn=cn=0;
            c[0]=a[1];
            c[1]=a[2];
            cn=2;
            b[0]=a[0];
            bn=1;
            work2(3);
        }
        for (int i=0;i<bn-1;i++) cout<<b[i]<<" ";cout<<b[bn-1]<<endl;
        for (int i=0;i<cn-1;i++) cout<<c[i]<<" ";cout<<c[cn-1]<<endl;
    }
    return 0;
}

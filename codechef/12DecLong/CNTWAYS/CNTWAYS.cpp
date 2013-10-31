#include<stdio.h>
#include<iostream>
using namespace std;
long long x,y,q;
long long p=1000000007,one=1;
long long f[800001];

void extend_Eulid(long long a,long long b)
{
    if(b==0) {x=1;y=0;q=a;}
    else
    {
        extend_Eulid(b,a%b);
        long long temp = x;
        x = y;
        y = temp - a/b*y;
        //if (b==0) {cout<<"f"<<endl;}
    }
}

inline long long C(long long a,long long b,long long p)
{
    long long ans=1;
    if (a-b<b) b=a-b;
    for (int i=1;i<=b;i++)
    {
        long long ii=i,one=1;
        ans=ans*(a-ii+one);
        if (ans>=p) ans%=p;
        ans=ans*f[i];
        if (ans>=p) ans%=p;
    }
    return ans;
}

inline void work1(long long n,long long m,long long a,long long b)
{
    long long ans,tmp;
    ans=C(n+m,m,p);
    tmp=C(n-a,0,p)*C(a+m-one,m,p);
    for (long long i=0;i<b;i++)
    {
        ans=ans-tmp;
        if (ans<0) ans+=p;
        long long u=0;
        tmp=tmp*(n-a+i+one);
        if (tmp>=p) tmp%=p;
        int v=i;v++;
        tmp=tmp*f[v];
        if (tmp>=p) tmp%=p;
        tmp=tmp*(m-i);
        if (tmp>=p) tmp%=p;
        if (a+m-one-i>0)
        {
            int u=a+m-i-one;
            tmp=tmp*f[u];
            if (tmp>=p) tmp%=p;
        }
    }
    cout<<ans<<endl;
}

inline void work2(long long n,long long m,long long a,long long b)
{
    long long ans,tmp;
    ans=0;
    tmp=C(n-a+b,b,p)*C(a+m-b-one,a-one,p)%p;
    for (long long i=b;i<=m;i++)
    {
        ans+=tmp;
        if (ans>=p) ans-=p;
        tmp=tmp*(n-a+i+one)%p;
        tmp=tmp*f[i+one];
        if (tmp>=p) tmp%=p;
        tmp=tmp*(m-i)%p;
        if (a+m-i-one>0)
        {
            tmp=tmp*f[a+m-i-one];
            if (tmp>=p) tmp%=p;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int tt;scanf("%d",&tt);
    for (long long i=1;i<=800000;i++)
    {
        extend_Eulid(i,p);
        if ((x>=p)||(x<=-p)) x%=p;
        if (x<0) {x+=p;}
        f[i]=x;
    }
    while (tt--)
    {
        long long n,m,a,b,ans,tmp;
        cin>>n>>m>>a>>b;
        //if (m-b>b)
        work1(n,m,a,b);
        //else work2(n,m,a,b);
    }
    return 0;
}

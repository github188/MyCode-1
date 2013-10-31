#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct edge
{
    int x,y;
    long long z;
};
char c[100000];
int a[100001],fa[100001];
edge e[400000];
int n,m;

bool cmp(edge a,edge b)
{
    if (a.z<b.z) return true;
    return false;
}

int fa1(int x)
{
    if (x==fa[x]) return x;
    fa[x]=fa1(fa[x]);
    return fa[x];
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d",&n,&m);gets(c);
        gets(c);
        int u=0;
        for (int i=0;i<n;i++)
        if (c[i]=='H')
        {
            u++;
            a[i+1]=u;
        } else {a[i+1]=0;}
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d%d",&x,&y,&e[i].z);
            e[i].x=a[x];
            e[i].y=a[y];
        }
        for (int i=0;i<=u;i++) fa[i]=i;

        sort(e,e+m,cmp);
        long long ans=0;
        if (u>0)
        for (int i=0;i<m;i++)
        if (fa1(e[i].x)!=fa1(e[i].y))
        {
            ans+=e[i].z;
            int x=fa1(e[i].x),y=fa1(e[i].y);
            fa[x]=y;
            u--;
            if (u<=0) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node
{
    int x,y;
};

node a[100000];
int k,n,m;

bool cmp(node a,node b)
{
    if ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y))) return true;
    return false;
}

int work(int x,int y)
{
    int l,r,u,v;
    l=0;r=k-1;
    while (l<r)
    {
        int mid=(l+r)/2+1;
        if ((a[mid].x<x)||((a[mid].x==x)&&(a[mid].y<y))) {l=mid;}
        else {r=mid-1;}
    }
    u=l;
    if ((x==a[0].x)&&(y==a[0].y)) u--;

    l=0;r=k-1;
    while (l<r)
    {
        int mid=(l+r)/2+1;
        if ((a[mid].x<x)||((a[mid].x==x)&&(a[mid].y<=y))) {l=mid;}
        else {r=mid-1;}
    }
    v=l;

    return v-u;
}

int main()
{
    int tt=0;
    while (true)
    {
        scanf("%d%d%d",&k,&n,&m);
        if (k==0) break;

        for (int i=0;i<k;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+k,cmp);

        int ans=0;
        for (int i=0;i<k;i++)
        {
            int sum=0;
            sum+=work(a[i].x,a[i].y)+work(a[i].x-1,a[i].y)+work(a[i].x+1,a[i].y)+work(a[i].x,a[i].y-1)+work(a[i].x,a[i].y+1);
            if (sum<3) ans++;
        }
        tt++;
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}

#include<stdio.h>
using namespace std;
int q[2][400000][2];
int a[400000],h[2],t[2];

bool cmp1(int o,int p)
{
    if (o<p) return true;
    return false;
}
bool cmp2(int o,int p)
{
    if (o>p) return true;
    return false;
}

void ins(int a[][400000][2],int p,int num,int q,bool (*fun)(int,int))
{
    t[p]++;
    a[p][t[p]][0]=num;
    a[p][t[p]][1]=q;
    while ((t[p]>h[p])&&(fun(a[p][t[p]][0],a[p][t[p]-1][0])))
    {
        t[p]--;
        a[p][t[p]][0]=a[p][t[p]+1][0];
        a[p][t[p]][1]=a[p][t[p]+1][1];
    }
}

int main()
{
    int n,m;
    int ans=0;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    h[0]=h[1]=0;
    t[0]=t[1]=-1;
    for (int i=0;i<m;i++)
    {
        ins(q,0,a[i],i,cmp1);
        ins(q,1,a[i],i,cmp2);
    }
    if (q[1][h[1]][0]-q[0][h[0]][0]+1==m) ans++;
    for (int i=m;i<n;i++)
    {
        if (q[0][h[0]][1]==i-m) h[0]++;
        if (q[1][h[1]][1]==i-m) h[1]++;
        ins(q,0,a[i],i,cmp1);
        ins(q,1,a[i],i,cmp2);
        if (q[1][h[1]][0]-q[0][h[0]][0]+1==m) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

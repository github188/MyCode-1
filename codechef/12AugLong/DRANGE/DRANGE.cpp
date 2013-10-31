#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct st{int x,y,z;}a[30000];

bool cmp(st a,st b) { return (a.y<b.y); }

int main()
{
    int tt;scanf("%d",&tt);while (tt>0) {tt--;
    int n,m,tot;tot=0;
    scanf("%d%d",&n,&m);
    a[tot].x=1;a[tot].y=1;a[tot++].z=0;
    a[tot].x=1;a[tot].y=n;a[tot++].z=0;
    for (int i=0;i<m;i++)
    {
        int u,v,w,x;
        scanf("%d%d%d%d",&u,&v,&w,&x);
        a[tot].x=u;a[tot].y=v;a[tot++].z=x;
        if (w<n) {a[tot].x=3-u;a[tot].y=w+1;a[tot++].z=x;}
    }
    int min=1000000007,max=-min;
    sort(a,a+tot,cmp);
    int sum=0,k=0;
    while (k<tot)
    {
        if ((k>0)&&(a[k].y-1>a[k-1].y))
        {
            min=min<(a[k].y-1+sum)?min:(a[k].y-1+sum);
            max=max>(a[k].y-1+sum)?max:(a[k].y-1+sum);
        }
        int y=a[k].y;
        sum+=(a[k].x==1?a[k].z:-a[k].z);k++;
        while ((k<tot)&&(a[k].y==a[k-1].y)) {sum+=(a[k].x==1?a[k].z:-a[k].z);k++;}
        min=min<(y+sum)?min:(y+sum);
        max=max>(y+sum)?max:(y+sum);
    }
    printf("%d\n",max-min);
    }
    return 0;
}

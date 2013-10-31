#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int n,m,k;
long long a[100001];
struct node
{
    int x,y;
    long long d,v;
} b[100001],c[100001];
long long d[100001];
bool cmp(node a,node b) {return (a.x<b.x);}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d%d%I64d",&b[i].x,&b[i].y,&b[i].d);
    for (int i=1;i<=k;i++) scanf("%d%d",&c[i].x,&c[i].y);
    sort(c+1,c+k+1,cmp);
    int v=0,l=1;
    for (int i=1;i<=m;i++)
    {
        while ((l<=k)&&(c[l].x==i))
        {
            v++;
            d[c[l++].y]++;
        }
        b[i].v=v;
        v-=d[i];
    }
    sort(b+1,b+1+m,cmp);
    for (int i=1;i<=n;i++) d[i]=0;
    long long u=0;l=1;
    for (int i=1;i<=n;i++)
    {
        while ((l<=m)&&(b[l].x==i))
        {
            u+=b[l].d*b[l].v;
            d[b[l++].y]+=b[l].d*b[l].v;
        }
        a[i]+=u;
        u-=d[i];
    }
    for (int i=1;i<n;i++) printf("%I64d ",a[i]);printf("%I64d\n",a[n]);
    return 0;
}

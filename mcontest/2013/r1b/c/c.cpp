#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct node
{
    double x,y;
} a[50000],b[50000];
int n;
double pos=0;
bool cmp(node a,node b)
{
    return a.x<b.x;
}

bool check(double len)
{
    for (int i=0;i<n;i++)
    {
        if (a[i].y>len) return false;
        double tmp=sqrt(len*len-a[i].y*a[i].y);
        b[i].x=a[i].x-tmp;
        b[i].y=a[i].x+tmp;
    }
    sort(b,b+n,cmp);
    pos=b[0].y;
    for (int i=1;i<n;i++)
    {
        if (b[i].x>pos) return false;
        pos=b[i].y<pos?b[i].y:pos;
    }
    return true;
}

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        double l,r;r=1e9,l=0;
        for (int i=0;i<80;i++)
        {
            double mid=(l+r)/2.0;
            if (check(mid)) r=mid; else l=mid;
        }
        check(r);
        printf("Case #%d: %.6f\n",t,pos);
    }
    return 0;
}

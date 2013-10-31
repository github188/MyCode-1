#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct index
{
    double pos;
    int val;
} a[110000];
double x[50001],y[50001],z[50001];
int n,size;
double eps=1e-9;

bool cmp(index a,index b)
{
    return a.pos<b.pos;
}

int main()
{
    double pi=acos(-1);
    double L,R,l,r;
    scanf("%d%lf%lf",&n,&L,&R);
    for (int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
        z[i]=z[i]/180.0*pi;
    }
    r=y[0];
    for (int i=1;i<n;i++) if (y[i]>r) r=y[i];
    while (fabs(r-l)>eps)
    {
        double mid=(r+l)/2.0;
        size=0;
        for (int i=0;i<n;i++)
        if (y[i]>mid)
        {
            double len=tan(z[i])*(y[i]-mid);
            a[size].pos=x[i]-len;//-eps;
            a[size++].val=1;
            a[size].pos=x[i]+len;//+eps;
            a[size++].val=-1;
        }
        sort(a,a+size,cmp);
        if ((a[0].pos>L)||(a[size-1].pos<R))
        {
            r=mid;
            continue;
        }
        int tmp=0;
        bool check=true;
        for (int i=0;i<size;i++)
        {
            tmp+=a[i].val;
            if ((tmp==0)&&(a[i].pos>=L)&&(a[i].pos<=R))
            {
                check=false;
                break;
            }
        }
        if (check) {l=mid;} else {r=mid;}
    }
    printf("%.6f\n",(r+l)/2.0);
    return 0;
}

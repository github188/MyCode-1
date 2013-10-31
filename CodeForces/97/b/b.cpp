#include<stdio.h>
#include<math.h>

double a[10][2];
bool use[10];
int b[10];

bool cz(int o,int p,int q)
{
    double x1=a[o][0]-a[q][0],y1=a[o][1]-a[q][1];
    double x2=a[p][0]-a[q][0],y2=a[p][1]-a[q][1];
    double ans=x1*x2+y1*y2;
    if (fabs(ans)<1e-10) return true;
    return false;
}

bool len(int o,int p,int q)
{
    double x1=a[o][0]-a[q][0],y1=a[o][1]-a[q][1];
    double x2=a[p][0]-a[q][0],y2=a[p][1]-a[q][1];
    double ans=(x1*x1+y1*y1)-(x2*x2+y2*y2);
    if (fabs(ans)<1e-10) return true;
    return false;
}

bool check()
{
    if (!cz(b[4],b[2],b[1])) return false;
    if (!cz(b[4],b[2],b[3])) return false;
    if (!cz(b[8],b[6],b[5])) return false;
    if (!cz(b[8],b[6],b[7])) return false;
    if (!len(b[4],b[2],b[3])) return false;
    return true;
}

bool work(int o)
{
    if (o==8)
    {
        if (check())
        {
            printf("YES\n");
            for (int i=1;i<=3;i++) printf("%d ",b[i]);printf("%d\n",b[4]);
            for (int i=5;i<=7;i++) printf("%d ",b[i]);printf("%d\n",b[8]);
            return true;
        }
        return false;
    }

    for (int i=1;i<=8;i++)
    if (!use[i])
    {
        b[o+1]=i;
        use[i]=true;
        if (work(o+1)) return true;
        use[i]=false;
    }
    return false;
}

int main()
{
    for (int i=1;i<=8;i++)scanf("%lf%lf",&a[i][0],&a[i][1]);
    bool ans=work(0);
    if (!ans) printf("NO\n");
    return 0;
}

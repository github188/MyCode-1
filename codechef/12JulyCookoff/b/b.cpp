#include<stdio.h>
#include<math.h>

double a[10000][2];
int n,t;

double dis(int o,int p)
{
    return sqrt((a[o][0]-a[p][0])*(a[o][0]-a[p][0])+(a[o][1]-a[p][1])*(a[o][1]-a[p][1]));
}

bool check(int i,int j)
{
    double x=a[j][0]-a[i][0],y=a[j][1]-a[i][1];
    double u=1.0;
    for (int k=0;k<4;k++)
    if ((k!=i)&&(k!=j))
    {
       double xx=a[k][0]-a[i][0],yy=a[k][1]-a[i][1];
       u*=(x*yy-xx*y);
    }
    if (u<0) return false;
    return true;
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%lf%lf",&a[i][0],&a[i][1]);
        double ans=0;
        if (n>4)
        {
            for (int i=0;i<n;i++)
             for (int j=i+1;j<n;j++) if (dis(i,j)>ans) ans=dis(i,j);
            printf("%.6f\n",ans);
        } else
        {
            for (int i=0;i<n;i++)
             for (int j=i+1;j<n;j++)
             if ((dis(i,j)>ans)&&(check(i,j))) ans=dis(i,j);
            printf("%.6f\n",ans);
        }
    }
    return 0;
}

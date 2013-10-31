#include<stdio.h>
#include<math.h>
double a[3000][3000],b[3000][2];
bool f[3000][3000];
int n;

inline void dis(int o,int p)
{
    a[o][p]=sqrt((b[o][0]-b[p][0])*(b[o][0]-b[p][0])+(b[o][1]-b[p][1])*(b[o][1]-b[p][1]));
}
bool check(double o)
{
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) f[i][j]=false;
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if (a[i][j]>=o) f[i][j];
    for (int i=0;i<n;i++)

    return false;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lf%lf",&b[i][0],&b[i][1]);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) dis(i,j);
    double l=1e5,r=0;
    for (int t=0;t<45;t++)
    {
        double mid=(l+r)/2;
        if (check(mid)) l=mid; else r=mid;
    }
    printf("%.6f\n",((l+r)/2.0)/2.0);
    return 0;
}

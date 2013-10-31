#include<stdio.h>
#include<math.h>
double pi=3.141592653589793;
double r,r1,r2,r3;

double work(double r,double rp)
{
    double area=0;
    double z=sqrt((r+rp)*(r+rp)-(r-rp)*(r-rp)),x=z*rp/(r-rp);
    area=(x+z)*r;
    return area;
}

int main()
{
    int tt=0;
    while (scanf("%lf%lf%lf%lf",&r,&r1,&r2,&r3)!=EOF)
    {
        if (r<0) break;
        printf("Case %d: ",++tt);
        double ans=work(r,r1)+work(r,r2)+work(r,r3);
        printf("%.2f\n",ans);
    }
    return 0;
}

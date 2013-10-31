#include<stdio.h>
#include<math.h>
using namespace std;
double l1,l2,l3,l4,l5,ans;
double eps=1e-8;

double area(double a,double b,double c)
{
     double p=(a+b+c)/2.0;
     double S=sqrt(p*(p-a)*(p-b)*(p-c));
     return S;
}

void work()
{
    double area1=area(l1,l2,l5)*2.0;
    ans=ans<(area1-area1*l2/(2.0*l1))?ans:(area1-area1*l2/(2.0*l1));
    for (double f=l2)
}

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        ans=1e9;
        scanf("%lf%lf%lf%lf%lf",&l1,&l2,&l3,&l4,&l5);
        if (fabs(l1-l2)<eps)
        {
            ans=area(l1,l2,l5);
            printf("Case #%d: %.5f\n",t,ans);
            continue;
        }
        if (l1<l2)
        {
            double p;
            p=l1;l1=l2;l2=p;
            p=l3;l3=l4;l3=p;
        }
        double h,d,area1;
        h=area(l1,l2,l5)*2.0/l1;
        d=sqrt(l2*l2-h*h);
        if (l1>=d+d)
        {
            area1=(l1+d+d+l1)*h/4.0;
            ans=ans<area1?ans:area1;
        }
        h=area(l1,l2,l5)*2.0/l2;
        d=sqrt(l1*l1-h*h);
        if (l2>=d+d)
        {
            area1=(l2+d+d+l2)*h/4.0;
            ans=ans<area1?ans:area1;
        }
        work();
        printf("Case #%d: %.5f\n",t,ans);
    }
    return 0;
}

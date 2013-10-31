#include<stdio.h>
#include<math.h>
double eps=1e-12;
double y11,y2,yw,xb,yb,R;
struct pp
{
    double x,p;
};

double dis(double a,double b,double c,double d)
{
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}

pp f1(double x,double y,double h,double R,double s)
{
    double l=0,r=x;
    while (r-l>1e-10)
    {
        double mid=(l+r)/2;
        double tmp=h-(h-y)*mid/(x-mid);
        if (tmp>s) {l=mid;continue;}
        if (mid*(s-tmp)/dis(0,tmp,mid,h)<=R) {l=mid;continue;}
        r=mid;
    }
    pp ans;
    ans.x=(l+r)/2.0;
    ans.p=h-(h-y)*ans.x/(x-ans.x);
    return ans;
}

pp f2(double x,double y,double h,double R,double s)
{
    double l=0,r=x;
    while (r-l>1e-10)
    {
        double mid=(l+r)/2.0;
        double tmp=h-(h-y)*mid/(x-mid);
        if (tmp<=s+R) {r=mid;continue;}
        //if (mid*(tmp-s)/dis(0,s,mid,h)<R+eps) {r=mid;continue;}
        l=mid;
    }
    pp ans;
    ans.x=(l+r)/2.0;
    ans.p=h-(h-y)*ans.x/(x-ans.x);
    return ans;
}

int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&y11,&y2,&yw,&xb,&yb,&R);
    pp u,d;
    u=f1(xb,yb,yw-R,R,y2);
    d=f2(xb,yb,yw-R,R,y11);
    if (u.p<d.p) {printf("-1\n");}
    else printf("%.9f\n",(u.x+d.x)/2.0);
    return 0;
}

#include<math.h>
#include<stdio.h>

int main()
{
    double n,R,r;
    scanf("%lf%lf%lf",&n,&R,&r);
    if (n==0) {printf("YES\n");return 0;}
    if (r>R+1e-10) {printf("NO\n");return 0;}
    if (fabs(r-R)<1e-10)
    {
        if (fabs(1-n)<1e-10) {printf("YES\n");return 0;}
        printf("NO\n");
    } else
    if (r+r<R+1e-10)
    {
        double s=asin(r/(R-r)),pi=asin(1)*4;
        s*=2;
        s=pi/s;
        if (s>n-1e-10) {printf("YES\n");} else {printf("NO\n");}
    } else
    {

        if (fabs(1-n)<1e-10) {printf("YES\n");return 0;}
        printf("NO\n");
    }
    return 0;
}

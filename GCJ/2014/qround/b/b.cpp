#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

double work(int y,double c,double f,double x)
{
    double z=y,ans=x/(2.0+f*z);
    for (int i=0;i<y;i++)
    {
        z=i;ans+=c/(2.0+f*z);
    }
    return ans;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        double c,f,x;
        scanf("%lf%lf%lf",&c,&f,&x);
        double ans=x/2.0;
        int y=(int)((f*x-2.0*c)/(f*c));
        if (y-1>0) ans=min(ans,work(y-1,c,f,x));
        if (y>0) ans=min(ans,work(y,c,f,x));
        if (y+1>0) ans=min(ans,work(y+1,c,f,x));
        printf("Case #%d: %.7f\n",t,ans);
    }
    return 0;
}

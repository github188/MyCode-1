#include<stdio.h>
#include"ISS.h"
double beta=-72;
ISS a;

int main()
{
    freopen("1.csv","w",stdout);

    double yaw = a.getInitialOrientation(beta);
    for (int i=0;i<93;i++)
    {
        vector<double> ans=a.getStateAtMinute(i);
        printf("%.3f",(i*360.0)/92.0);printf(",%.3f",beta);printf(",%.3f",yaw);
        for (int j=0;j<20;j+=2) printf(",%.3f",ans[j]);
        printf("\n");
    }
    return 0;
}

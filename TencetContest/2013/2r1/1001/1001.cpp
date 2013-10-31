#include<stdio.h>
int t,q;
double x;

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        int xx;
        scanf("%d",&xx);x=xx;x=60.0-xx;
        scanf("%d",&q);
        while (q--)
        {
            int c;double y;int yy;
            scanf("%d%d",&c,&yy);y=yy;
            if (c==1) printf("%.2f\n",y*x); else
            if (c==2) printf("%.2f\n",y*3600/x); else
            printf("%.2f\n",(12*3600*60*y)/(60.0-x));
        }
    }
    return 0;
}

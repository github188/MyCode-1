#include<stdio.h>
#include<math.h>
int n,m;
double dx[5]={-1000007,1000007,1000007,-1000007,-123045};
double dy[5]={-1000007,-1000007,1000007,1000007,543201};

int main()
{
    scanf("%d%d",&n,&m);
    if (((n>4)&&(m==3))) printf("-1\n");
    else
    {
        double ang=(180.0*(m-2.0))/(double)(m);
        ang=(180.0-ang)/180.0*acos(-1);
        n-=m;
        double x,y,xx,yy;
        int pos=0;
        x=y=yy=0;xx=1009;
        printf("%.0f %.0f\n",x,y);
        for (int i=2;i<=m;i++)
        {
            printf("%.0f %.0f\n",xx,yy);
            if (n>0)
            {
                printf("%.0f %.0f\n",(x+xx)/3.0+dx[pos],(y+yy)/2.0+dy[pos]);
                pos=(pos+1)%5;
                n--;
            }
            double ox=xx-x,oy=yy-y;
            double px=cos(ang)*ox-sin(ang)*oy,py=+sin(ang)*ox+cos(ang)*oy;
            x=xx;y=yy;
            xx=x+px;yy=y+py;
        }
            if (n>0)
            {
                printf("%.0f %.0f\n",(x+xx)/3.0+dx[pos],(y+yy)/2.0+dy[pos]);
                pos=(pos+1)%5;
                n--;
            }
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double r[1000],x[1000],y[1000];
int n,tt;
double w,l;
double max(double o,double p)
{
    if (o<p) return p;return o;
}

bool check(int i,double l,double rr)
{
    if ((x[i]+r[i]>l+1e-10)&&(x[i]-r[i]<rr-1e-10)) return true;
    return false;
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%lf%lf",&n,&w,&l);
        for (int i=0;i<n;i++) scanf("%lf",&r[i]);
        for (int i=0;i<n-1;i++)
         for (int j=i+1;j<n;j++)
          if (r[i]<r[j])
          {
              double k=r[i];
              r[i]=r[j];
              r[j]=k;
          }
        double u;
        bool cc=false;
        //if (w<l) {u=w;w=l;l=u;cc=true;}
        x[0]=y[0]=0;
        double xx=r[0],yy=1.0;
        for (int i=1;i<n;i++)
        {
            double lx,rx,ox;
            lx=xx;rx=xx+r[i]*2.0*yy;
            ox=xx+r[i]*yy;
            xx=rx;
            if ((ox>w)||(ox<0.0))
            {
                if (yy<0)
                {
                    yy=1.0;
                    xx=r[i];
                    lx=0.0;rx=r[i];
                    ox=lx;
                } else
                {
                    yy=-1.0;
                    xx=w-r[i];
                    lx=xx;rx=w;
                    ox=rx;
                }
            }
            double yy=0.0;
            for (int j=0;j<i;j++)
            if (check(j,lx,rx)) yy=max(y[j]+r[j],yy);
            x[i]=ox;
            y[i]=yy;
            if (yy>1e-10) y[i]+=r[i];
            if (cc)
            {
                double u=x[i];
                x[i]=y[i];
                y[i]=u;
            }
        }
        printf("Case #%d:",t);
        for (int i=0;i<n;i++) printf(" %.5f %.5f",x[i],y[i]);
        printf("\n");
    }
    return 0;
}

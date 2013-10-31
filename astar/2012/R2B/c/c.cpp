#include<stdio.h>
#include<math.h>
double x[100000],y[100000],xx[100000],yy[00000];
struct point{double x,y;};
struct line{point a,b;};

double max(double x,double y)
{
    if (x>y) return x;return y;
}

bool check(int o,int p)
{
    double t=(yy[o]-y[o])/(xx[o]-x[o]),s=(yy[p]-y[p])/(xx[p]-x[p]);
    if (fabs(s-t)<1e-10) return false;
    return true;
}

double intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret.x;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lf%lf%lf%lf",&x[i],&y[i],&xx[i],&yy[i]);
    for (int i=0;i<n;i++)
    if (xx[i]==x[i]) {printf("%.2f\n",x[i]);} else
    {
        double ans=-1000000000.0;
        for (int j=0;j<n;j++)
        if (check(i,j))
        {
            line u,v;
            u.a.x=x[i];
            u.a.y=y[i];
            u.b.x=xx[i];
            u.b.y=yy[i];
            v.a.x=x[j];
            v.a.y=y[j];
            v.b.x=xx[j];
            v.b.y=yy[j];
            ans=max(ans,intersection(u,v));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

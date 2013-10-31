#include<stdio.h>
#include<math.h>
int n;
double x[100],y[100],a[100],b[100],t[100][2];

void work(int i,int j,int k)
{
    double x1,y1,x2,y2,a1,b1,a2,b2;
    x1=x[j]-x[i];
    y1=y[j]-y[i];
    x2=x[k]-x[i];
    y2=y[k]-y[i];
    a1=a[j]-a[i];
    b1=b[j]-b[i];
    a2=a[k]-a[i];
    b2=b[k]-b[i];
    double aa,bb,cc;
    aa=a1*b2-a2*b1;
    bb=x1*b2+a1*y2-x2*b1-a2*y1;
    cc=x1*y2-x2*y1;
    if (bb*bb-4.0*aa*cc<0.0) {t[k][0]=t[k][1]=-1;return;}
    if (fabs(aa)<1e-10)
    {
        t[k][1]=-1.0;
        if (fabs(bb)<1e-10)
        {
            t[k][0]=t[k][1]=-1.0;return;
        }
        t[k][0]=-cc/bb;
        return;
    }
    if (fabs(bb)<1e-10)
    {
        t[k][1]=-1.0;
        t[k][0]=sqrt(-cc/aa);
        return;
    }
    double tmp=bb*bb-4.0*aa*cc;
    double xx=(-bb+sqrt(tmp))/(2.0*aa);
    double yy=(-bb-sqrt(tmp))/(2.0*aa);
    if ((xx<0)||(xx>1.0)) {t[k][0]=-1;} else {t[k][0]=xx;}
    if ((yy<0)||(yy>1.0)) {t[k][1]=-1;} else {t[k][1]=yy;}
    if (t[k][1]>=0.0)
    {
        double u=t[k][1];
        t[k][1]=t[k][0];
        t[k][0]=u;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lf%lf%lf%lf",&x[i],&y[i],&a[i],&b[i]);
    int ans=0;
    for (int i=0;i<n;i++)
     for (int j=i+1;j<n;j++)
     {
         for (int k=0;k<n;k++)
         if ((k!=i)&&(k!=j)) {work(i,j,k);}
         t[i][0]=t[i][1]=t[j][0]=t[j][1]=-1;
         for (int k=0;k<n;k++){
         if (t[k][0]>=0.0)
         {
          int tmp=2;
           for (int l=0;l<n;l++)
            if ((k!=l)&&((fabs(t[k][0]-t[l][0])<1e-10)||(fabs(t[k][0]-t[l][1])<1e-10))) tmp++;
          if (tmp>ans) ans=tmp;
          if (ans==8)
          {
              int uu=1;
          }
         }
         if (t[k][1]>=0.0)
         {
          int tmp=2;
           for (int l=0;l<n;l++)
            if ((k!=l)&&((fabs(t[k][1]-t[l][0])<1e-10)||(fabs(t[k][1]-t[l][1])<1e-10))) tmp++;
          if (tmp>ans) ans=tmp;
         }}
     }
    printf("%d\n",ans);
    return 0;
}

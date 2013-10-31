#include<stdio.h>

double f[101][101],g[101][101],a[101];
int n,m;
double r;

double min(double o,double p)
{
    if (o<p) {return o;} else {return p;}
}

int main()
{
    scanf("%d%d%lf",&n,&m,&r);
    if ((r==0)&&(n==1)) {printf("0.00000\n");return 0;}

    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {f[i][j]=g[i][j]=-1;}
    for (int i=0;i<n;i++) {f[i][i]=0;scanf("%lf",&a[i]);a[i]=a[i]/10000;}
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);x--;y--;
        scanf("%lf",&g[x][y]);
        f[x][y]=f[y][x]=g[y][x]=g[x][y];
    }

    for (int k=0;k<n;k++)
     for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
       if ((f[i][k]>=-0.5)&&(f[k][j]>=-0.5))
       {
           if (f[i][j]<0) {f[i][j]=f[i][k]+f[k][j];}
           else {f[i][j]=min(f[i][j],f[i][k]+f[k][j]);}
       }

    double ans=-1;
    bool check=true;
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++) if (f[i][j]<0) {check=false;}

    if (check)
    for (int i=0;i<n;i++)
     for (int j=i+1;j<n;j++)
      if (g[i][j]>=2*r)
      {
          double len=g[i][j]-r-r;
          double sum;

          sum=0;
          for (int k=0;k<n;k++)
          if (f[i][k]<f[k][j]+len)
          {
              sum+=(f[i][k]+r)*a[k];
          } else
          {
              sum+=(f[k][j]+len+r)*a[k];
          }
          if (ans<0) {ans=sum;} else {ans=min(ans,sum);}

          sum=0;
          for (int k=0;k<n;k++)
          if (f[i][k]+len<f[k][j])
          {
              sum+=(f[i][k]+r+len)*a[k];
          } else
          {
              sum+=(f[k][j]+r)*a[k];
          }
          if (ans<0) {ans=sum;} else {ans=min(ans,sum);}
      }

    if (ans<0) {printf("-1\n");} else {printf("%.5f\n",ans);}
    return 0;
}

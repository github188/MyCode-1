#include<stdio.h>
#include<math.h>

double f[2000][2000];
int n,m;

double max(double o,double p)
{
       if (o>p) {return o;}return p;
}

int main()
{
    scanf("%d%d",&m,&n);
    f[0][0]=1;
    for (int i=1;i<=1000;i++) {f[i][0]=1;double ii=i;ii+=1.0;f[0][i]=1.0/ii;}
    for (int i=2;i<=2000;i++)
     for (int j=1;j<=i-1;j++)
      if ((j<=1000)&&(i-j<=1000))
      {
         int x,y;
         x=j;y=i-j;
         double u,v;u=y;u+=1.0;u=1.0/u;
         v=1-u;
         f[x][y]=max(u,(1.0-f[y-1][x]));
      }
    
    printf("%.9f %.9f\n",f[m][n],1-f[m][n]);
    return 0;
}

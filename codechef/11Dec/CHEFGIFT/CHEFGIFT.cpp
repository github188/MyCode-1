#include<stdio.h>

int a[100][100],c[100][100],f[100][100];
int n,m;

int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int d;
        scanf("%d%d%d",&d,&n,&m);
        for (int i=0;i<m;i++)
          for (int j=0;j<n;j++)
          {
              scanf("%d",&a[i][j]);
          }
        for (int i=0;i<m;i++)
          for (int j=0;j<m;j++)
          {
              scanf("%d",&c[i][j]);
              f[i][0]=a[i][0];
          }

        for (int k=0;k<m;k++)
         for (int i=0;i<m;i++)
          for (int j=0;j<m;j++)
           c[i][j]=min(c[i][j],c[i][k]+c[k][j]);

        for (int i=1;i<n;i++)
         for (int j=0;j<m;j++)
         {
           f[j][i]=f[j][i-1]+a[j][i];
           for (int k=0;k<m;k++)
            if (k!=j) {f[j][i]=min(f[j][i],f[k][i-1]+c[k][j]+a[j][i]);}
         }

        int ans=f[0][n-1];
        for (int i=1;i<m;i++) ans=min(ans,f[i][n-1]);
        if (ans>d) {printf("-1\n");} else {printf("%d\n",d-ans);}
    }
    return 0;
}

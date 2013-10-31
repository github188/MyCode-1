#include<stdio.h>
int n,m;
int t[50],l[50],f[500][500];

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d%d",&t[i],&l[i]);
        for (int i=0;i<500;i++) for (int j=0;j<500;j++) f[i][j]=m*10000;
        f[0][0]=m;
        int ans=500;
        for (int i=0;i<500;i++)
          for (int j=0;j<500;j++)
          if (f[i][j]<=m)
          {
              if (j!=0)
              {
                  int x=f[i][j]/j;
                  if ((f[i][j]%j)>0) x++;
                  x+=i;
                  if (x<ans) ans=x;
              }
              for (int k=0;k<n;k++)
              {
                  int y=f[i][j]-j*t[k];
                  if (y<=0) continue;
                  int x=j+l[k];
                  if (x>m) x=m;
                  if ((f[i+t[k]][x]==-1)||(f[i+t[k]][x]>y)) f[i+t[k]][x]=y;;
              }
          }
        printf("%d\n",ans);
    }
    return 0;
}

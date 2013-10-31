#include<stdio.h>
int f[200][40001][2];
int n,a,b;

int min(int o,int p)
{
    return o<p?o:p;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    for (int i=0;i<n;i++)
      for (int j=0;j<=a;j++) f[i][j][0]=f[i][j][1]=-1;
    int h;
    scanf("%d",&h);
    int sum=h;
    int h1=h;
    if (h<=a) f[0][h][0]=0;
    if (h<=b) f[0][0][1]=0;
    for (int i=0;i<n-1;i++)
    {
     scanf("%d",&h);
     for (int j=0;j<=a;j++)
      {
          if (f[i][j][0]!=-1)
          {
              if ((j+h<=a)&&((f[i+1][j+h][0]==-1)||(f[i+1][j+h][0]>f[i][j][0])))
              {
                  f[i+1][j+h][0]=f[i][j][0];
              }
              if ((sum-j+h<=b)&&((f[i+1][j][1]==-1)||(f[i+1][j][1]>f[i][j][0]+min(h1,h))))
              f[i+1][j][1]=f[i][j][0]+min(h1,h);
          }
          if (f[i][j][1]!=-1)
          {
              if ((j+h<=a)&&((f[i+1][j+h][0]==-1)||(f[i+1][j+h][0]>f[i][j][1]+min(h1,h))))
              {
                  f[i+1][j+h][0]=f[i][j][1]+min(h1,h);
              }
              if ((sum-j+h<=b)&&((f[i+1][j][1]==-1)||(f[i+1][j][1]>f[i][j][1])))
              f[i+1][j][1]=f[i][j][1];
          }
      }
     h1=h;
     sum+=h;
    }

    int ans=-1;
    for (int i=0;i<=a;i++)
    {
        if ((f[n-1][i][0]!=-1)&&((ans==-1)||(ans>f[n-1][i][0]))) ans=f[n-1][i][0];
        if ((f[n-1][i][1]!=-1)&&((ans==-1)||(ans>f[n-1][i][1]))) ans=f[n-1][i][1];
    }
    printf("%d\n",ans);
    return 0;
}

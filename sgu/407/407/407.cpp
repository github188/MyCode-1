#include<stdio.h>
int f[2][5010][200];

void add(int o,int p,int q,int r)
{
   for (int i=1;i<=f[o][p][0];i++) f[o][p][i]+=f[q][r][i];
   if (f[o][p][0]<f[q][r][0])
   {
      for (int i=f[o][p][0]+1;i<=f[q][r][0];i++) f[o][p][i]=f[q][r][i];
      f[o][p][0]=f[q][r][0];
   }
   f[o][p][f[o][p][0]+1]=0;
   for (int i=1;i<=f[o][p][0];i++)
   if (f[o][p][i]>9)
   {
     f[o][p][i+1]=f[o][p][i]/10;
     f[o][p][i]=f[o][p][i]%10;
   }
   while (f[o][p][f[o][p][0]+1]>0)
   {
     f[o][p][0]++;
     f[o][p][f[o][p][0]+1]=f[o][p][f[o][p][0]]/10;
     f[o][p][f[o][p][0]]=f[o][p][f[o][p][0]]%10;
   }
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  f[0][0][0]=1;
  f[0][0][1]=1;
  for (int i=1;i<=m;i++)
  {
     int k=(i&1),l=1-k;
     for (int j=0;j<=n;j++) f[k][j][0]=0;
     if (f[l][0][0]>0)
     {
        for (int j=1;j<=n;j++) add(k,j,l,0);
     }
     for (int j=1;j<=n;j++)
     if (f[l][j][0]>0)
     {
       add(k,0,l,j);
       int u=j+1;if (u>n) u=1;
       add(k,u,l,j);
       u=j-1;if (u==0) u=n;
       add(k,u,l,j);
     }
  }
  m=(m&1);
  for (int i=f[m][0][0];i>0;i--) printf("%d",f[m][0][i]);printf("\n");
  return 0;
}

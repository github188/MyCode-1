#include<stdio.h>
long long mod=1000000007;
int n,m,k;
long long f[10][10][1024];
int a[2000],b[10][10];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&b[i][j]);
    if (n+m-1>k) {printf("0\n");return 0;}
    a[0]=0;
    for (int i=0;i<(1<<k);i++)
      for (int j=0;j<k;j++) a[i|(1<<j)]=a[i]+1;
    if (b[0][0]==0) for (int i=0;i<k;i++) f[0][0][1<<i]=1;
    else f[0][0][1<<(b[0][0]-1)]=1;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
     if ((i!=0)||(j!=0))
     {
         int l=0,r=k-1;
         if (b[i][j]>0) l=r=b[i][j]-1;
         for (int c=l;c<=r;c++)
         {
             if (i==0)
             {
                 for (int x=0;x<(1<<k);x++)
                 if (((x&(1<<c))==0)&&(f[i][j-1][x]))
                 {
                     f[i][j][x|(1<<c)]+=f[i][j-1][x];
                     if (f[i][j][x|(1<<c)]>=mod) f[i][j][x|(1<<c)]-=mod;
                 }
             } else
             if (j==0)
             {
                 for (int x=0;x<(1<<k);x++)
                 if (((x&(1<<c))==0)&&(f[i-1][j][x]))
                 {
                     f[i][j][x|(1<<c)]+=f[i-1][j][x];
                     if (f[i][j][x|(1<<c)]>=mod) f[i][j][x|(1<<c)]-=mod;
                 }
             } else
             {
                 for (int x=0;x<(1<<k);x++)
                 if (((x&(1<<c))==0)&&(f[i][j-1][x]))
                 for (int y=0;y<(1<<k);y++)
                 if (((y&(1<<c))==0)&&(f[i-1][j][y]))
                 {
                     f[i][j][(x|y|(1<<c))]+=f[i][j-1][x]*f[i-1][j][y];
                     if (f[i][j][(x|y|(1<<c))]>=mod)f[i][j][(x|y|(1<<c))]%=mod;
                 }
             }
         }
     }
    long long ans=0;
    for (int i=0;i<(1<<k);i++) ans=(ans+f[n-1][m-1][i])%mod;
    int aa=ans;
    printf("%d\n",aa);
    return 0;
}

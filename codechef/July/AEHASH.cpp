#include<stdio.h>
#include<iostream>
using namespace std;
long long f[51][51][1001],g[51][51][1001];
long long mod=1000000007;
int a,e,va,t;

int main()
{
    f[1][1][1]=1;
    for (int i=1;i<=1000;i++) {g[1][1][i]=1;}
    for (int i=1;i<=50;i++) {f[i][0][0]=1;for (int j=0;j<=1000;j++) {g[i][0][j]=1;}}
    for (int i=1;i<=50;i++) f[0][i][0]=g[0][i][0]=1;
    
    for (int i=2;i<=50;i++)
     for (int j=1;j<=i;j++)
      for (int k=j+1;k<=200;k++)
      {
          int u=j;
          int v=(i>>1);
          if ((v+1)<u) {u=v+1;}
          for (int l=0;l<=u;l++) 
          {
              f[i][j][k]=(mod+f[i][j][k]+(g[v][l][k-j]*g[i-v][j-l][k-j])%mod-(g[v][l][k-j-1]*g[i-v][j-l][k-j-1])%mod)%mod;
          }
          
          g[i][j][k]=(g[i][j][k-1]+f[i][j][k])%mod;
      }
    
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          scanf("%d%d%d",&a,&e,&va);
          if ((a+e<2)||(a==0)) {if (a==va) {printf("%d\n",1);} else {printf("0\n");}}
          else
          {
              long long ans=0;
              int u=a;int i=a+e;int k=va;
              if (va<=a) {printf("0\n");continue;}
              if (((a+e)/2+1)<u) {u=i/2+1;}int v=i/2;
              for (int l=0;l<=u;l++) 
              {
                ans=(mod+ans+(g[v][l][k-a]*g[i-v][a-l][k-a])%mod-(g[v][l][k-a-1]*g[i-v][a-l][k-a-1])%mod)%mod;
              }
              
              cout<<ans<<endl;
          }
    }
    return 0;
}

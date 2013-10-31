#include<stdio.h>
#include<iostream>
using namespace std;
long long mod=1000000007;
long long g[2][2],f[2][2],tmp[2][2];
int n;

void work(int o)
{
    if (o==1)
    {
        for (int i=0;i<2;i++)
         for (int j=0;j<2;j++) g[i][j]=f[i][j];
        return;
    }
    work(o/2);
    for (int i=0;i<2;i++)
     for (int j=0;j<2;j++)
     {
         tmp[i][j]=0;
         for (int k=0;k<2;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j])%mod;
     }

    for (int i=0;i<2;i++)
     for (int j=0;j<2;j++) g[i][j]=tmp[i][j];
    if ((o&1)==0) return;
    for (int i=0;i<2;i++)
     for (int j=0;j<2;j++)
     {
         tmp[i][j]=0;
         for (int k=0;k<2;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j])%mod;
     }

    for (int i=0;i<2;i++)
     for (int j=0;j<2;j++) g[i][j]=tmp[i][j];
}

int main()
{
    f[0][0]=0;f[0][1]=3;
    f[1][0]=1;f[1][1]=2;
    int t;scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        if (n==2) {printf("12\n");continue;}
        work(n-2);long long tt=12;
        g[1][1]*=tt;
        g[1][1]%=mod;
        cout<<g[1][1]<<endl;
    }
    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
long long mod=1000000007;
long long f[15][2001],c[2101][2101];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) f[1][i]=1;
    for (int i=2;i<15;i++)
        for (int j=1;j<=n;j++)
            for (int l=2;l<=j;l++)
            if (j%l==0)
            {
                f[i][j]=(f[i][j]+f[i-1][j/l])%mod;
            }
    long long ans=0;
    c[0][0]=1;
    for (int i=1;i<=2100;i++)
        for (int j=0;j<=i;j++)
        {
            c[i][j]=c[i-1][j];
            if (j>0) c[i][j]=(c[i][j]+c[i-1][j-1])%mod;
        }
    for (int i=1;i<15;i++)
        for (int j=1;j<=n;j++) ans=(ans+f[i][j]*c[k-1][i-1])%mod;
    cout<<ans<<endl;
    return 0;
}

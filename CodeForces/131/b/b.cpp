#include<iostream>
using namespace std;
long long a[10];
long long f[2][10][200][200];
long long c[200][200];
int n;
long long mod=1000000007;


int main()
{
    for (int i=0;i<2;i++) for (int j=0;j<10;j++) for (int k=0;k<200;k++) for (int l=0;l<200;l++) f[i][j][k][l]=0;
    c[0][0]=1;
    for (int i=1;i<=100;i++)
      for (int j=0;j<=i;j++)
      {
          c[i][j]+=c[i-1][j];
          if (j!=0) c[i][j]+=c[i-1][j-1];
          c[i][j]%=mod;
      }
    cin>>n;
    int sum=0;
    for (int i=0;i<10;i++) {cin>>a[i];sum+=a[i];}
    if (sum>n) {cout<<0<<endl;return 0;}
    long long ans=0;
    int tmp=a[9];
    for (int i=sum;i<=n;i++)
      if (i>0)
      for (int j=a[9];j<=i;j++)
      {
          if (j<i) f[0][9][i][j]=c[i-1][j];
          if (j>0) f[1][9][i][j]=c[i-1][j-1];
      }
    for (int i=9;i>0;i--)
    {
        for (int j=sum;j<=n;j++)
         for (int k=tmp;k<=j;k++)
          {
              if (f[0][i][j][k]!=0)
              {
                  for (int l=a[i-1];l<=j-k;l++)
                  {
                      if (j-k-1>=l) f[0][i-1][j][k+l]=(f[0][i-1][j][k+l]+(f[0][i][j][k]*c[j-k-1][l])%mod)%mod;
                      if ((i-1>0)&&(l>0)) f[1][i-1][j][k+l]=(f[1][i-1][j][k+l]+(f[0][i][j][k]*c[j-k-1][l-1])%mod)%mod;
                  }
              }

              if (f[1][i][j][k]!=0)
              {
                  for (int l=a[i-1];l<=j-k;l++)
                  f[1][i-1][j][k+l]=(f[1][i-1][j][k+l]+(f[1][i][j][k]*c[j-k][l])%mod)%mod;
              }
          }
        tmp+=a[i-1];
    }
    for (int i=sum;i<=n;i++) if (i>0)
     ans=(ans+f[1][0][i][i])%mod;
    //if ((n==1)&&(sum==1)&&(a[0]==1)) ans++;
    //if (sum==0) {ans++;ans%=mod;}
    cout<<ans<<endl;
    return 0;
}

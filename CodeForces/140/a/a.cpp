#include<iostream>
using namespace std;
long long f[3][3],g[3][3],tmp[3][3];
long long mod,n;

void work(long long o)
{
    if (o==1)
    {
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) g[i][j]=f[i][j];
        return;
    }
    work(o>>1);
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<2;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j])%mod;
      }
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) g[i][j]=tmp[i][j];
    if ((o&1)==0) return;
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<2;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j])%mod;
      }
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) g[i][j]=tmp[i][j];
}

int main()
{
    cin>>n>>mod;
    f[0][0]=1;f[0][1]=2;
    f[1][0]=0;f[1][1]=3;
    work(n);
    cout<<g[0][1]%mod<<endl;
    return 0;
}

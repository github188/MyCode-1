#include<iostream>
using namespace std;
long long f[3][3],g[3][3],tmp[3][3];
long long mod,l,r,k;
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

long long calc(long long o,long long p)
{
    return o/p;
}

int main()
{

    f[0][0]=0;f[0][1]=1;
    f[1][0]=1;f[1][1]=1;
    cin>>mod>>l>>r>>k;
    long long ll=1,rr=r;
    long long two=2,one=1;
    /*while (ll<rr)
    {
        long long mid=(ll+rr)/two+one;
        if ((calc(r,mid)-calc(l-one,mid))>=k) ll=mid; else rr=mid-one;
    }*/
    ll=(r-l+one)/(k-one);
    while (calc(r,ll)-calc(l-one,ll)<k) ll--;
    work(ll);
    cout<<g[1][0]<<endl;

    return 0;
}

#include<iostream>
using namespace std;
long long mod=1000000007;
long long g[11][11],f[11][11][11][11];
long long eight=8;

inline long long t(long long o)
{
    if (o<0) o+=mod;
    return o;
}

long long work(long long m)
{

}

int main()
{
    g[1][0]=8;g[1][1]=2;
    for (int i=2;i<=10;i++)
    {
        for (int j=0;j<=i;j++)
        {
            g[i][j]=g[i-1][j]*eight%mod;
            if (j>0) g[i][j]=(g[i][j]+g[i-1][j-1]+g[i-1][j-1])%mod;
        }
    }
    //for (int i=1;i<=9;i++) g[i][0]=t(g[i][0]-1);
    long long n;
    cin>>n;
    long long a[11];a[0]=0;
    while (n>0) {a[++a[0]]=n%10;n/=10;}
    for (int i=0;i<=a[0]-1;i++) f[1][i][1][i]=g[a[0]-1][i];
    if (a[0]>1) f[1][0][1][0]--;
    //f[1][0][1][0]--;
    long long k,l;k=0;
    for (int i=a[0];i>0;i--)
    {
        int u=0;if (i==a[0]) u++;
        if (i==1)
        {
            long long q=a[i];if (a[0]>1) q++;
            if (a[i]>=4) f[1][k+1][1][k+1]++,q--;
            if (a[i]>=7) f[1][k+1][1][k+1]++,q--;
            f[1][k][1][k]+=q;
            f[1][k][1][k]%=mod;
            f[1][k+1][1][k+1]%=mod;
            break;
        }
        for (int j=u;j<a[i];j++)
        {
            int tmp=0;if ((j==4)||(j==7)) tmp++;
            for (int l=k+tmp;l<=a[0];l++) f[1][l][1][l]=(f[1][l][1][l]+g[i-1][l-k-tmp])%mod;
        }
        if ((a[i]==4)||(a[i]==7)) k++;
    }

    for (int i=2;i<=6;i++)
      for (int j=0;j<=a[0];j++)
      {
          for (int k=j;k<=a[0];k++)
           for (int l=0;l<j;l++)
            for (int m=1;m<i;m++)
              if (f[i-1][l][m][k-j]>0)
               f[i][j][1][k]=(f[i][j][1][k]+(f[i-1][l][m][k-j]*f[1][j][1][j]*work(m))%mod)%mod;
          long long one=1;
          for (long long k=2;k<=i;k++)
           for (int l=j;l<=a[0];l++)
              if (f[i-1][j][k-1][l-j]>0)
               f[i][j][k][l]=(f[i][j][k][l]
                             +(f[i-1][j][k-1][l-j]*t(f[1][j][1][j]-k+one))%mod)%mod;
      }
    long long oo=720;
    long long ans=0;
    for (int i=1;i<=a[0];i++)
      for (int j=0;j<i;j++)
       for (int k=1;k<=6;k++)
        for (int l=j;l<i;l++)
         ans=(ans+oo*(f[1][i][1][i]*(f[6][j][k][l]*work(k)%mod)%mod)%mod)%mod;
    cout<<ans<<endl;
    return 0;
}

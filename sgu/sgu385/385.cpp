#include<iostream>
#include <iomanip>
using namespace std;
long double f[101][101][101],a[101][101],g[101][101];
int n;

int main()
{
    for (int i=1;i<=100;i++)
      for (int j=1;j<=i;j++)
      {
          a[i][j]=1;
          for (int k=i;k>=i-j+1;k--)
          {
              long double l=k;
              a[i][j]*=l;
          }
          long double l=j;
          a[i][j]/=l;
      }

    cin>>n;
    for (int i=2;i<=n;i++)
      for (int j=2;j<=i;j++)
      {
       g[i][j]=0;
       for (int k=1;k<=i/j;k++)
       if ((i==j)&&(k==1))
       {
           f[i][j][k]=a[n][i];
           g[i][j]+=f[i][j][k];
       } else
       if ((j<=i-2)&&(k>1))
       {
           long double kk=k;
           f[i][j][k]=(f[i-j][j][k-1]*a[n-i+j][j])/kk;
           g[i][j]+=f[i][j][k];
       } else
       if (j<=i-2)
       {
           int k=j-1;if (i-j<k) k=i-j;
           for (int l=2;l<=k;l++) f[i][j][1]+=g[i-j][l];
           f[i][j][1]*=a[n-i+j][j];
           g[i][j]+=f[i][j][1];
       }
      }
    long double au,ad;au=ad=0;
    for (int i=2;i<=n;i++)
      for (int j=1;j<=n/i;j++)
      {
          long double ii=i,jj=j;
          au+=f[n][i][j]*ii*jj;
          ad+=f[n][i][j];
      }
     cout << fixed << setprecision(10) << au/ad << endl;

    return 0;
}

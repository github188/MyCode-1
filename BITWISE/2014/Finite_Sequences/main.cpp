#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

long long mod=1000000007;
long long a[3][3],b[3],c[3][3];

void mulMat(long long c[][3],long long a[][3])
{
  long long d[3][3];
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) d[i][j]=0;
  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    	for (int k=0;k<3;k++)
            d[i][j]=(d[i][j]+c[i][k]*a[k][j])%mod;
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) c[i][j]=d[i][j];
}

void powerMat(long long c[][3],long long a[][3],long long n)
{
  if (n==0)
  {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) c[i][j]=0;
    c[0][0]=c[1][1]=c[2][2]=1;
    return;
  }
  if (n==1)
  {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) c[i][j]=a[i][j];
    return;
  }
  powerMat(c,a,n/2);
  mulMat(c,c);
  if (n&1) mulMat(c,a);
}

int main() {
    ifstream fin;fin.open("a.in");
    ofstream fout;fout.open("a.out");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  	int t;fin>>t;
  	while (t--)
    {
      long long n,k;fin>>n>>k;
      if (n<k) {fout<<0<<endl;continue;}
      if (n==k) {fout<<1<<endl;continue;}
      a[0][0]=0;a[0][1]=1;a[0][2]=1;
      a[1][0]=0;a[1][1]=2;a[1][2]=1;
      a[2][0]=0;a[2][1]=0;a[2][2]=2;
      b[0]=1;b[1]=1;b[2]=1;
      powerMat(c,a,n-k);
      fout<<(c[0][0]+c[0][1]+c[0][2])%mod<<endl;
    }
    return 0;
}

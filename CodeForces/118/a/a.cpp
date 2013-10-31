#include<iostream>
using namespace std;
long long a[2][2],b[2][2];
long long mod=1000000007,n=0;

void work(long long n)
{
    if (n==1)
    {
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]=a[i][j];
        return;
    }
    long long two=2,one=1;
    work(n/two);
    long long c[2][2];
    c[0][0]=b[0][0]*b[0][0]+b[0][1]*b[1][0];
    c[0][1]=b[0][0]*b[0][1]+b[0][1]*b[1][1];
    c[1][0]=b[1][0]*b[0][0]+b[1][1]*b[1][0];
    c[1][1]=b[1][0]*b[0][1]+b[1][1]*b[1][1];
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]=c[i][j];

    if ((n&one)!=0)
    {

      long long c[2][2];
      c[0][0]=b[0][0]*a[0][0]+b[0][1]*a[1][0];
      c[0][1]=b[0][0]*a[0][1]+b[0][1]*a[1][1];
      c[1][0]=b[1][0]*a[0][0]+b[1][1]*a[1][0];
      c[1][1]=b[1][0]*a[0][1]+b[1][1]*a[1][1];
      for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]=c[i][j];
    }
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]%=mod;
}

int main()
{
    cin>>n;
    if (n==0) {cout<<1<<endl;}
    else
    {
        a[0][0]=a[1][1]=3;
        a[0][1]=a[1][0]=1;
        b[0][0]=b[1][1]=1;
        work(n);
        cout<<b[0][0]<<endl;
    }
    return 0;
}

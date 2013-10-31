#include<iostream>
using namespace std;
int n,tt;
long long mod=1000000007;
long long a[100];
long long b[500],nb[500];
int ExtendedEuclid( long long f,long long d ,long long *result)
{
long long x1,x2,x3,y1,y2,y3,t1,t2,t3,q;

x1 = y2 = 1;
x2 = y1 = 0;
x3 = ( f>=d )?f:d;
y3 = ( f>=d )?d:f;

while( 1 )
{
  if ( y3 == 0 )
  {
   *result = x3; /* 两个数不互素则result为两个数的最大公约数，此时返回值为零 */
   return 0;
  }
  if ( y3 == 1 )
  {
   *result = y2; /* 两个数互素则resutl为其乘法逆元，此时返回值为1 */
   return 1;
  }
  q = x3/y3;
  t1 = x1 - q*y1;
  t2 = x2 - q*y2;
  t3 = x3 - q*y3;
  x1 = y1;
  x2 = y2;
  x3 = y3;
  y1 = t1;
  y2 = t2;
  y3 = t3;
}
}
int main()
{
    b[0]=b[1]=1;
    for (long long i=2;i<=447;i++) b[i]=(b[i-1]*i)%mod;
    nb[1]=1;
    for (long long i=2;i<=47;i++)
    {
        ExtendedEuclid(i,mod,&nb[i]);
        while (nb[i]<0) nb[i]+=mod;
    }

    cin>>tt;
    while (tt--)
    {
        cin>>n;
        int sum=0;
        for (int i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
        long long f=1,ans=b[sum];
        for (int i=0;i<n;i++) ans=(ans*nb[a[i]])%mod;
    }
    return 0;
}

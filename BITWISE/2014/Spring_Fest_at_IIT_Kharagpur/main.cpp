#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long mod=1000000007,two=2;
long long f[30001],g[30001];
long long ext_gcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0){  x=1,y=0;  return a;  }
	long long d=ext_gcd(b,a%b,x,y) , temp=x;
	x=y,y=temp-a/b*y;  return d;
}

long long get_ni(long long a,long long p){ //∑µªÿx,ax=1 (mod p) apª•÷ 
	long long x,y;
	ext_gcd(a,p,x,y);
	while (x<0) x+=mod;
	return x;
}

long long work(long long p,long long q)
{
    long long ans=(f[p]*g[p-q])%mod;
    ans=(ans*g[q])%mod;
    return ans;
}

int main()
{
    f[1]=1;g[0]=1;
    for (long long i=2;i<=30000;i++) f[i]=(f[i-1]*i)%mod;
    for (long long i=1;i<=30000;i++)
    {
        long long temp=get_ni(i,mod);
        g[i]=(g[i-1]*temp)%mod;
    }
  	int t;scanf("%d",&t);
  	while (t--)
    {
        long long n;cin>>n;
        long long ans=work(n*3,2*n)-two*work(n*3,n*2+1)+work(n*3,n*2+2);
        cout<<ans<<endl;
    }
    return 0;
}

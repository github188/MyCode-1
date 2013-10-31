#include<iostream>
using namespace std;
long long mod=1000000007;
long long one=1,two=2,three=3;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if( b == 0 )
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		long long x1,y1;
		long long d = exgcd ( b , a % b , x1 , y1 );
		x = y1;
		y= x1 - a / b * y1;
		return d;
	}
}
long long rev(long long o)
{
    long long x,y;
    exgcd(o,mod,x,y);
    if (x<0) x+=mod;
    return x;
}

long long mul(long long o,long long p)
{
    if (p==0) return 1;
    if (p==1) return o;
    long long ans=mul(o,p>>1);
    ans=(ans*ans)%mod;
    if (p&1) ans=(ans*o)%mod;
    return ans;
}

int main()
{
    long long n,k;
    cin>>n>>k;
    if (n==1) {if (k==1) cout<<1<<endl; else cout<<0<<endl;} else
    if (k==1) cout<<mul(n,n-2)<<endl; else
    if (k==2)
    {
        long long ans;
        cout<<ans<<endl;
    } else
    {
        long long ans;
        cout<<ans<<endl;
    }
    return 0;
}

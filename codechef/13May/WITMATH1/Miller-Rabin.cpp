#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct MillerRabin
{
    long long MultiBigger(long long a,long long b,long long mod)
    {
        long long one=1;
        if (a<b) {long long c=a;a=b;b=c;}
        if (b==0) return 0;
        if (b==1) return a;
        long long ans=MultiBigger(a,b>>1,mod);
        ans=(ans+ans);//%mod;
        while (ans>=mod) ans-=mod;
        if (b&one) ans=(ans+a);//%mod;
        while (ans>=mod) ans-=mod;
        return ans;
    }

    long long pow1(long long base,long long d,long long mod)
    {
        long long ans=1;
        if (d==1) return base;
        ans=pow1(base,d>>1,mod);
        ans=MultiBigger(ans,ans,mod);
        if (d&1) ans=MultiBigger(ans,base,mod);
        return ans;
    }

    bool check(long long num,int time)
    {
        long long two=2,one=1;
        if ((num<=one)||((num>two)&&(!(num&one)))) return 0;
        int r=0;
        long long d=num-one;
        while ((d&one)==0) {r++;d>>=1;}
        while (time--)
        {
            long long base=(long long)rand()%(num-one)+one;
		    long long x=pow1(base,d,num);
		    for (int j=0;j<r;j++)
		    {
			    long long x1=x;x=MultiBigger(x1,x1,num);
			    if ((x==one)&&(x1!=one)&&(x1!=num-one)) return false;
		    }
		    if (x != one) return false;
        }
        return true;
    }
};

MillerRabin g;
long long a[100];

int main()
{
    int tt;cin>>tt;
    srand(time(NULL));
    int u=0;
    while (tt--)
    {
        long long n;cin>>n;
        while (true)
        {
            bool check=g.check(n,20);
            if (check)
            {
                cout<<n<<endl;
                break;
            }
            n--;
        }
    }
    return 0;
}

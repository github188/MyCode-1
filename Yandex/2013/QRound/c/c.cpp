#include<iostream>
using namespace std;
long long n,m,ans1,ans2,two=2,one=1;

int main()
{
    cin>>n;
    ans1=n*n+n;ans1/=two;
    ans2=0;
    {
        if (n==one) ans2=one;
        else
        {
                long long ans=0,v=2,w=1;
                n++;
                do
                {
                    long long t=(n/v);
                    if (v==two)
                    {
                        ans|=w*(t&one);
                    } else
                    {
                        t=n%v;
                        if (t>w) ans|=w*((t-w)&one);
                    }
                    v+=v;
                    w+=w;
                } while (w<n);
                long long zero=0;
                if (ans==zero) ans2=0;
                else
                {
                    long long v=1;
                    while (v<n) v+=v;
                    long long sum=0;
                    for (long long u=0;u<=10000000;u++) if (u<n) if (((n-u)^ans)>=n) sum++;
                    ans2=(n-sum)/two;
                }
        }

    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

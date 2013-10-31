#include<iostream>
using namespace std;

long long a[20];
long long l,r;

long long work(long long o)
{
    long long ans=0;
    if (o<10) return o;
    ans=9;
    int digit[100];
    digit[0]=0;
    long long ten=10;
    while (o>0)
    {
        long long p=o%ten;
        digit[++digit[0]]=p;
        o/=ten;
    }
    long long nine=9;
    for (int i=2;i<digit[0];i++) ans+=a[i-2]*nine;
    long long u=digit[digit[0]],v=u-1;
    ans+=v*a[digit[0]-2];
    if (digit[digit[0]]<=digit[1])
    {
        long long w=0;
        for (int i=digit[0]-1;i>1;i--)
        {
            long long x=digit[i];
            w=w*ten+x;
        }
        w++;
        ans+=w;
    } else
    {
        long long w=0;
        for (int i=digit[0]-1;i>1;i--)
        {
            long long x=digit[i];
            w=w*ten+x;
        }
        //w++;
        ans+=w;
    }
    return ans;
}

int main()
{
    cin>>l>>r;
    a[0]=1;a[1]=10;
    for (int i=2;i<20;i++) a[i]=a[i-1]*a[1];l--;
    long long ans=work(r)-work(l);
    cout<<ans<<endl;
    return 0;
}

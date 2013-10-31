#include<stdio.h>

long long work(long long o,long long mod)
{
    if (o==0) return 1;
    if (o==1) return 2;
    long long f=work(o/2,mod);
    f*=f;
    f%=mod;
    if ((o&1)==1)
    {
        f+=f;
        f%=mod;
    }
    return f;
}

int main()
{
  int tt;
  scanf("%d",&tt);
  while (tt>0)
  {
    tt--;
    int n;scanf("%d",&n);
    long long ans=2,mod=1000000007;
    if (n!=1)
    {
        long long u=n/2;
        if ((n&1)==0) u--;
        long long tmp=work(u+1,mod);
        tmp-=2;
        if (tmp<0) tmp+=mod;
        tmp+=tmp;
        tmp%=mod;
        if ((n&1)==0) tmp+=work(n/2,mod);
        ans=(ans+tmp)%mod;
    }
    int a=ans;
    printf("%d\n",a);
  }
  return 0;
}

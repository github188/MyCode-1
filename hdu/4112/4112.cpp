#include<stdio.h>
long long n,m,k;

long long work(long long o)
{
  long long ans=0,p=1,two=2;
  while (p<o)
  {
     p*=two;
     ans++;
  }
  return ans;
}

int main()
{
  int t,tt;
  scanf("%d",&tt);
  for (int t=1;t<=tt;t++)
  {
    scanf("%lld%lld%lld",&n,&m,&k);
    printf("Case #%d:",t);
    long long ans1=n*m*k;
    ans1--;
    long long ans2=work(n)+work(m)+work(k);
    printf(" %ll4d\n %lld\n",ans1,ans2);
  }
  return 0;
}

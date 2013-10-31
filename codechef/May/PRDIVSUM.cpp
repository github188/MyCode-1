#include<stdio.h>

int gcd(int o,int p)
{
    if (p==0) {return o;}
    else {return gcd(p,o%p);}
}

bool check(int u,int v)
{
     long long o,p;
     o=u;p=v;
     long long max1=1000000000;
     o+=p;o=o*p;
     if (o<=max1) {return true;}
     return false;
}

int main()
{
    long long ans;ans=0;
    for (int i=2;i<=3;i++)
      for (int j=1;j<i;j++)
       if ((gcd(i,j)==1)&&(check(i,j))) {ans++;}
    printf("%lld",ans);
    int n;
    scanf("%d",&n);
    return 0;
}

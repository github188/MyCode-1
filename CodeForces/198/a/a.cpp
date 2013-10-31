#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
long long a[100000];
long long n,c,d,e,f,a0,a1;

long long gcd(long long o,long long p)
{
    if (o<p) {long long q=o;o=p;p=q;}
    if (p==0) return o;
    return gcd(p,o%p);
}

int main()
{
    scanf("%I64d",&n);
    for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
    std::sort(a,a+n);
    c=0;d=1;
    e=0;f=n-1;
    a1=n;
    for (int i=1;i<n;i++) e+=a[i];
    for (int i=0;i<n;i++)
    {
        a0+=d*a[i]-c+e-f*a[i];
        d++;f--;
        c+=a[i];e-=a[i+1];
    }
    long long tmp=gcd(a0,a1);a0/=tmp;a1/=tmp;
    printf("%I64d %I64d\n",a0,a1);
    return 0;
}

#include<stdio.h>
long long a[2000000];
bool b[2000001];
int tt,t;
long long n;

int main()
{
    a[0]=0;
    for (int i=2;i<=2000000;i++)
    if (!b[i])
    {
        a[0]++;
        a[a[0]]=i;
        int j=i+i;
        while (j<=2000000)
        {
              b[j]=true;
              j+=i;
        }
    }
    
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%lld",&n);
        long long max,min;
        max=1;min=0;
        for (int i=1;i<=a[0];i++)
        if (a[i]<=n)
        {
                    min++;
                    long long m=n;long long ai=a[i];long long one=1;
                    while (m>=ai) {max+=one;m/=ai;}
        }
        if (n==1) {max=0;}
        printf("Case #%d: %lld\n",t,max-min);
    }
    return 0;
}

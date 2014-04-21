//Token sort.
#include<stdio.h>
#include<string.h>

bool used[1000000];
long long mod=1000000;
int main()
{
    int test;scanf("%d",&test);
    while (test--)
    {
        memset(used,false,sizeof(used));
        int n,a,b,c,d;scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        long long s=d,a1=a,b1=b,c1=c;used[s]=true;
        n--;
        while (n--)
        {
            s=a1*s*s+b1*s+c1;
            if (s>=mod) s%=mod;
            used[s]=!used[s];
        }
        long long ans=0,current=-1;
        for (int i=999999;i>=0;i--)
        if (used[i])
        {
            if (current<0) current=i; else {ans+=current-i;current=-1;}
        }
        if (current>0) ans+=current;
        printf("%lld\n",ans);
    }
    return 0;
}

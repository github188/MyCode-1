#include<stdio.h>

char s[1000];
long long l[1000];
int n;
long long A,B,C;

long long mul(long long a,long long b)
{
    if (b==0) return 0;
    if (b==1) return a;
    long long ans=mul(a,b>>1);
    ans+=ans;if (ans>=C) ans%=C;
    if (b&1) ans+=a;if (ans>=C) ans%=C;
    return ans;
}

int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%lld",&l[i]);
        scanf("%lld%lld%lld",&A,&B,&C);A%=C;B%=C;
        scanf("%s",s);
        int h=0,t=n-1,d=0,f=0;
        long long coe=1,con=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='R') d^=1; else
            if (s[i]=='A') {f++;con+=A;if (con>=C) con%=C;} else
            {
                f++;
                coe=mul(coe,B);
                con=mul(con,B);
            }
            int p=h;if (d==1) p=t;
            if (f) l[p]%=C;
            l[p]=mul(l[p],coe);if (l[p]>=C) l[p]%=C;
            l[p]+=con;if (l[p]>=C) l[p]%=C;
            printf("%lld",l[p]);
            if (i<n-1) printf(" "); else printf("\n");
            if (d) t--; else h++;
        }
    }
    return 0;
}

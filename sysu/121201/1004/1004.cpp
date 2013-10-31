#include<stdio.h>
int a[1001][1001];
int w,h,n;
int mod=2552;

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d%d%d",&w,&h,&n);
        for (int i=0;i<=w;i++) a[i][0]=1;
        for (int i=0;i<=h;i++) a[0][i]=1;
        for (int i=1;i<=w;i++) for (int j=1;j<=h;j++) a[i][j]=(a[i-1][j]+a[i][j-1])%mod;
        while (n--)
        {
            int m;scanf("%d",&m);
            int ans=a[w][h];
            while (m--)
            {
                int x,y,xx,yy;
                scanf("%d%d%d%d",&x,&y,&xx,&yy);
                ans-=(a[x][y]*a[w-xx][h-yy]);
                ans%=mod;
                ans=(ans+mod)%mod;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

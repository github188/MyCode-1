#include<stdio.h>

int maxl=1000000007;
int a[5001][5001];

int main()
{
    a[0][0]=1;
    for (int i=1;i<=5000;i++)
    for (int j=0;j<=i;j++)
    {
        a[i][j]=a[i-1][j]+a[i-1][j-1];
        if (a[i][j]>=maxl) a[i][j]-=maxl;
    }

    while (true)
    {
        int n,k,x,y;
        scanf("%d %d",&n,&k);
        if (n==0) break;k++;

        int ans=0;
        x=k/2+(k&1);y=k/2;
        long long u,v,w,xx=maxl;
        u=a[n-2][x-1];v=a[n-2][y-1];w=(u*v)%xx;
        ans=w;
        ans+=ans;
        if (ans>=maxl) ans-=maxl;

        printf("%d\n",ans);
    }
    return 0;
}

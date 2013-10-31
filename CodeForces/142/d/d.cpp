#include<stdio.h>
int f[5001][5001],sum[50001],h[50001];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        sum[i]=sum[i-1]+h[i];
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=i;j++) f[i][j]=n+n;
    f[1][1]=0;
    for (int i=2;i<=n;i++)
    {
        int tmp=h[i],tmp1=h[i-1];
        int k=i-2;
        while ((k>=1)&&(tmp1+h[k]<=tmp)) tmp1+=h[k--];
        if ((tmp1<=tmp)&&(tmp1>0)) f[i][i]=f[i-1][k+1];
        for (int j=i-1;j>=1;j--)
        {tmp+=h[j];
            if (k<j) {tmp1-=h[j];}
            if (k>=j) k=j-1;
            while ((k>=1)&&(tmp1+h[k]<=tmp)) tmp1+=h[k--];
            if ((tmp1<=tmp)&&(tmp1>0)) f[i][j]=f[j-1][k+1]+i-j<f[i][j+1]?f[j-1][k+1]+i-j:f[i][j+1];
            f[i][j]=f[i][j]<f[i][j+1]?f[i][j]:f[i][j+1];
        }
        f[i][1]=f[i][1]<i-1?f[i][1]:i-1;
    }

    int ans=n-1;
    for (int i=1;i<=n;i++) if (f[n][i]<ans) ans=f[n][i];
    printf("%d\n",ans);
    return 0;
}

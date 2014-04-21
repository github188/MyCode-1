#include<stdio.h>
long long c[40][40];
int ans[100];

int main()
{
    c[0][0]=1;
    for (int i=1;i<=33;i++)
        for (int j=0;j<=i;j++)
        {
            c[i][j]=c[i-1][j];
            if (j>0) c[i][j]+=c[i-1][j-1];
        }
    int t;scanf("%d",&t);
    while (t--)
    {
        int n,m,kk;long long k;
        scanf("%d%d%d",&n,&m,&kk);k=kk;
        ans[0]=0;
        while (n+m>1)
        {
            if (c[n+m-1][n-1]<k)
            {if (m==0) {k=0;break;}k-=c[n+m-1][n-1];ans[++ans[0]]=1;m--;}
            else {if (n==0) {k=0;break;}ans[++ans[0]]=0;n--;}
        }
        if (k!=1) printf("Impossible\n"); else
        {
            if (n==1) ans[++ans[0]]=0; else ans[++ans[0]]=1;
            for (int i=1;i<=ans[0];i++) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}

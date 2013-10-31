#include<stdio.h>

int t[4001],d[4001],a[4001][4001];
int n,k,ans;

inline int max(int o,int p)
{
    if (o>p) return o;
    return p;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d%d",&t[i],&d[i]);
    if (n==k) {printf("86400\n");return 0;}
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j]=-1;
    ans=0;a[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        int ul=k;
        if (i<ul) ul=i;
        for (int j=0;j<=ul;j++)
        {
            if (a[i-1][j]!=-1)
            {
                if (a[i-1][j]<t[i])
                {
                   ans=max(ans,t[i]-a[i-1][j]-1);
                   a[i][j]=t[i]+d[i]-1;
                } else
                {
                    a[i][j]=a[i-1][j]+d[i];
                }
            }
            if (j!=0)
            {
                if (a[i-1][j-1]<t[i])
                {
                   ans=max(ans,t[i]-a[i-1][j-1]-1);
                   if ((a[i][j]==-1)||(a[i][j]>a[i-1][j-1])) a[i][j]=a[i-1][j-1];
                } else
                {
                   if ((a[i][j]==-1)||(a[i][j]>a[i-1][j-1])) a[i][j]=a[i-1][j-1];
                }
            }
        }

    }

    for (int i=0;i<=k;i++) ans=max(ans,86400-a[n][i]);

    printf("%d\n",ans);

    return 0;
}

#include<stdio.h>
#include<string.h>
int c[1000][1000],f[1000][1000],dist[1000];
bool use[1000];
int main()
{
int n;
while (scanf("%d",&n)!=EOF)
{
for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&c[i][j]);
int ans=c[0][n-1];
f[0][n-1]=f[n-1][0]=f[0][n]=f[n][0]=f[0][n+1]=f[n+1][0]=f[n-1][n+1]=f[n+1][n-1]=f[n][n+1]=f[n+1][n]=-1;
for (int i=1;i<n-1;i++)
{
    f[0][i]=f[i][0]=c[0][i];
    f[i][n+1]=f[n+1][i]=c[i][n-1];
    f[i][n-1]=f[n-1][i]=c[i][0];
    f[i][n]=f[n][i]=c[n-1][i];
    for (int j=1;j<n-1;j++) if (i!=j) f[i][j]=c[i][j];
}
    memset(use,false,sizeof(use));
    for (int i=0;i<=n+1;i++) dist[i]=-1;
    dist[0]=0;
    while (true)
    {
        bool check=false;
        int k=-1,l=-1;
        for (int i=0;i<=n+1;i++)
        if ((!use[i])&&(dist[i]>-1)&&((k==-1)||(dist[i]<l)))
        {k=i;l=dist[i];check=true;}
        if (!check) break;
        for (int j=0;j<=n+1;j++)
        if ((f[k][j]!=-1)&&((dist[j]==-1)||(dist[j]>dist[k]+f[k][j]))) dist[j]=dist[k]+f[k][j];
        use[k]=true;
    }
    if ((ans>dist[n+1])&&(dist[n+1]>-1)) ans=dist[n+1];
printf("%d\n",ans);
}

return 0;
}

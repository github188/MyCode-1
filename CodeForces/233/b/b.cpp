#include<stdio.h>
double f[2][2001][2001];
bool a[2001],b[2001];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        a[x]=true;b[y]=true;
    }
    int rn=0,cn=0;
    for (int i=1;i<=n;i++) if (a[i]) rn++;
    for (int i=1;i<=n;i++) if (b[i]) cn++;
    int l=0;
    f[0][rn][cn]=double(rn*cn)/double(n*n);
    f[0][rn+1][cn]=double((n-rn)*cn)/double(n*n);
    f[0][rn][cn+1]=double(rn*(n-cn))/double(n*n);
    f[0][rn+1][cn+1]=double((n-rn)*(n-cn))/double(n*n);
    double ans=f[0][n][n];
    for (int k=0;k<=20;k++){
    for (int i=rn;i<=n;i++)
        for (int j=cn;j<=n;j++) f[l^1][i][j]=0;f[l][n][n]=0;
    for (int i=rn;i<=n;i++)
        for (int j=cn;j<=n;j++)
    {
        double ti=i,tj=j,tn=n,tnn=n*n;
        f[l^1][i][j]+=ti*tj/tnn*f[l][i][j];
        f[l^1][i+1][j]+=(tn-ti)*tj/tnn*f[l][i][j];
        f[l^1][i][j+1]+=ti*(tn-tj)/tnn*f[l][i][j];
        f[l^1][i+1][j+1]+=(tn-ti)*(tn-tj)/tnn*f[l][i][j];

    }ans=ans+f[l^1][n][n];l^=1;}
    printf("%.5f\n",ans);
    return 0;
}

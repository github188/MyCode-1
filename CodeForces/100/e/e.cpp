#include<stdio.h>
long long f[5001][5001];
int n,m,p;

int main()
{
    scanf("%d%d%d",&n,&m,&p);

    f[1][1]=1;
    long long pp=p;
    for (int i=2;i<=5000;i++)
     for (int j=2;j<=i;j++)
     {
         long long jj=j,jj1=jj-1;
         f[i][j]=(f[i-1][j-1]*jj+f[i-1][j]*jj1)%pp;
     }

    return 0;
}

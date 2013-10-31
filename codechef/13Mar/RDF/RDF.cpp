#include<stdio.h>
double f[101][100001];

int main()
{
    for (int i=1;i<=100000;i++) f[0][i]=i;
    for (int i=1;i<=100;i++)
     for (int j=1;j<=100000;j++) f[i][j]=(f[i][j-1]*((double)j-1.0)+f[i-1][j-1])/(double)(j);
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        int n,k;scanf("%d%d",&n,&k);
        if (k<=100) printf("%.6f\n",f[k][n]);
        else printf("0\n");
    }
    return 0;
}

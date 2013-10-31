#include<stdio.h>
int a[60][60][60],b[60][60],c[1001][60][60];
int n,m,r;

int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++) for (int k=0;k<n;k++) {scanf("%d",&a[i][j][k]);b[j][k]=a[i][j][k];}
        for (int j=0;j<n;j++)
         for (int k=0;k<n;k++)
          for (int l=0;l<n;l++)
           if (a[i][k][j]+a[i][j][l]<a[i][k][l]) a[i][k][l]=a[i][k][j]+a[i][j][l];
    }
    for (int i=0;i<m;i++)
     for (int j=0;j<n;j++)
      for (int k=0;k<n;k++) if (a[i][j][k]<b[j][k]) b[j][k]=a[i][j][k];
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=1;k<=1000;k++) c[k][i][j]=-1;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) c[0][i][j]=b[i][j];


    for (int i=1;i<=80;i++)
     for (int j=0;j<n;j++)
      for (int k=0;k<n;k++)
       for (int l=0;l<n;l++)
        if ((c[i][k][l]<0)||((c[i-1][k][j]+b[j][l]<c[i][k][l])&&(c[i-1][k][j]>=0))) c[i][k][l]=c[i-1][k][j]+b[j][l];

    while (r>0)
    {
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        if (k>80) k=80;
        printf("%d\n",c[k][s-1][t-1]);
        r--;
    }

    return 0;
}

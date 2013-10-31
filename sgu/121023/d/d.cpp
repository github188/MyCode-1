#include<stdio.h>
#include<string.h>

int a[1000001][7];

int main()
{
    memset(a,-1,sizeof(a));
    for (int i=1;i<=6;i++) {a[21][i]=1;}
    for (int i=21;i<=1000000;i++)
     for (int j=1;j<=6;j++)
     if (a[i][j]>0)
     {
         int l=i-j;
         for (int k=1;k<=6;k++)
         {
             int m=l+14+k;
             if ((m<=1000000)&&((a[m][k]<0)||(a[m][k]>a[i][j]+1))) a[m][k]=a[i][j]+1;
         }
     }
    int n;
    scanf("%d",&n);
    int ans=-1;
    for (int i=1;i<=6;i++)
    if (a[n][i]>0)
    {
        if ((ans<0)||(ans>a[n][i])) {ans=a[n][i];}
    }
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
int a[31][31][31];

int main()
{
    int ans=0;
    for (int i=1;i<=30;i++) a[i][1][i]=1;
    for (int i=2;i<=30;i++)
    for (int j=2;j<=i;j++)
    {

        for (int k=1;k<=i-1;k++)
        {
            for (int l=1;l<=k;l++)
            a[i][j][k]+=a[i-k][j-1][l];
        }
    }

    for (int i=1;i<=30;i++) for (int j=1;j<=30;j++) ans+=a[5][i][j];
    printf("%d",ans);
    return 0;
}

#include<stdio.h>
#include<string.h>
int n,m;
char c[10][60];
int a[10][10];

int main()
{
    scanf("%d%d",&n,&m);gets(c[0]);
    for (int i=0;i<m;i++) gets(c[i]);
    int ans=0;a[0][0]=1;
    for (int i=1;i<=6;i++)
       for (int j=0;j<=i;j++)
       {
           a[i][j]=a[i-1][j];
           if (j!=0) a[i][j]+=a[i-1][j-1];
       }

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<9;j++)
        {
            int u=0;
            int x0,x1,x2,x3,x4,x5;
            x0=j*4;x1=x0+1;x2=x1+1;x3=x2+1;
            x4=53-j*2;x5=x4-1;
            if (c[i][x0]=='0') u++;
            if (c[i][x1]=='0') u++;
            if (c[i][x2]=='0') u++;
            if (c[i][x3]=='0') u++;
            if (c[i][x4]=='0') u++;
            if (c[i][x5]=='0') u++;
            ans+=a[u][n];
         }
    }

    printf("%d\n",ans);
    return 0;
}

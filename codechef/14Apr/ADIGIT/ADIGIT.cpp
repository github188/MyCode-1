#include<stdio.h>
int f[100001][10];
char a[100000];

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    scanf("%s",a);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<10;j++) f[i+1][j]=f[i][j];
        f[i+1][a[i]-'0']++;
    }
    while (m--)
    {
        int ans=0,x=0;scanf("%d",&x);x--;
        for (int i=0;i<10;i++)
        if (i<a[x]-'0') ans+=(a[x]-'0'-i)*f[x][i]; else ans+=(i-a[x]+'0')*f[x][i];
        printf("%d\n",ans);
    }
    return 0;
}

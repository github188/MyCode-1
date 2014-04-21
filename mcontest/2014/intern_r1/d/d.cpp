#include<stdio.h>
#include<string.h>
char s[200000][256];
int f[300][300];
int n;
int min(int o,int p)
{
    return (o<p?o:p);
}

int check(int u,int v)
{
    if (strlen(s[u])+5<strlen(s[v])) return 65;
    if (strlen(s[u])-5>strlen(s[v])) return 65;
    int x=strlen(s[u]),y=strlen(s[v]);
    memset(f,0,sizeof(f));
    for (int i=1;i<=x;i++) f[i][0]=i;
    for (int i=1;i<=y;i++) f[0][i]=i;
    for (int i=0;i<x;i++)
    for (int j=0;j<y;j++)
    {
        f[i+1][j+1]=6;
        if (s[u][i]==s[v][j]) f[i+1][j+1]=f[i][j];
        f[i+1][j+1]=min(min(f[i][j+1]+1,f[i+1][j]+1),f[i+1][j+1]);
    }
    return f[x+1][y+1];
}

int main()
{
    n=0;
    while (gets(s[n++])) {int o=0;if(n==5)break;}
    int fans=0;
    for (int i=0;i<n;i++)
    {
        int ans=0;
        for (int j=0;j<n;j++)
            if (i!=j)
             {
                 int t=check(i,j);
                if ((t&1)&&(t<7)) ans++;
             }
        if (fans<ans) fans=ans;
    }
    printf("%d\n",fans);
    return 0;
}

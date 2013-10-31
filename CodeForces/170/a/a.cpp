#include<stdio.h>
bool f[200][200],used[200];
int a[200][200];
int n,m;

void dfs(int o)
{
    used[o]=true;
    for (int i=0;i<n;i++)
    if ((!used[i])&&(f[o][i])) dfs(i);
}

int main()
{
    scanf("%d%d",&n,&m);bool ch=true;
    for (int i=0;i<n;i++)
    {
        int k;scanf("%d",&k);
        if (k>0) ch=false;
        while (k--)
        {
            int x;scanf("%d",&x);
            a[x][++a[x][0]]=i;
        }
    }
    for (int i=1;i<=m;i++)
     for (int j=1;j<=a[i][0];j++)
      for (int k=j+1;k<=a[i][0];k++) f[a[i][j]][a[i][k]]=f[a[i][k]][a[i][j]]=true;
    int ans=-1;
    for (int i=0;i<n;i++)
    if (!used[i]) {ans++;dfs(i);}
    if (ch) ans++;
    printf("%d\n",ans);
    return 0;
}

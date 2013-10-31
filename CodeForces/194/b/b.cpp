#include<stdio.h>
bool a[1001],b[1001];
int n;

int main()
{
    int m;scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        a[x]=b[y]=true;
    }
    int ans=0;
    if (n%2==1)
    {
        if (!(a[n/2+1]&b[n/2+1])) ans++;
    }
    for (int i=2;i<=n/2;i++)
    {
        int x=i,y=n-i+1;
        if (!a[x]) ans++;
        if (!a[y]) ans++;
        if (!b[x]) ans++;
        if (!b[y]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

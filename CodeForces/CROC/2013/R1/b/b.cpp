#include<stdio.h>
int a[100001];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        a[x]++;a[y]++;
    }
    int x=0,y=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==1) x++;
        if (a[i]>2) y++;
    }
    if ((x==2)&&(y==0)) printf("bus topology\n"); else
    if ((x==0)&&(y==0)) printf("ring topology\n"); else
    if ((x+y==n)&&(y==1)) printf("star topology\n"); else
    printf("unknown topology\n");
    return 0;
}

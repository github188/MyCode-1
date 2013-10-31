#include<stdio.h>
int t,n,m;
int l[101];

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=100;i++) l[i]=0;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            l[y]+=x;
        }
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            l[y]-=x;
        }

        for (int i=1;i<=100;i++)
        if (l[i]<0) ans-=l[i];
        printf("%d\n",ans);
    }
    return 0;
}

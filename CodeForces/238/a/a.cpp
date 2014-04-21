#include<stdio.h>
int a[1000];

int main()
{
    int ans=0;
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            {
                int x;scanf("%d",&x);
                if (i==j)
                {
                    a[i]=x;ans^=x;
                }
            }
    int q;scanf("%d",&q);
    while (q--)
    {
        int x;scanf("%d",&x);
        if (x<3)
        {
            int y;scanf("%d",&y);--y;
            a[y]^=1;ans^=1;
        } else printf("%d",ans);
    }
    printf("%d\n");
    return 0;
}

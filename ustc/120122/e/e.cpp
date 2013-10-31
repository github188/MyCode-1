#include<stdio.h>
int a[1000][7];
int r,g,b,n,m,x,y;

int main()
{
    int tt=0;
    while(true)
    {
        scanf("%d%d",&n,&m);
        if (n+m==0) break;
        tt++;
        printf("Case %d:\n",tt);
        for (int i=0;i<n;i++)
           for (int j=0;j<7;j++) scanf("%d",&a[i][j]);

        while (m>0)
        {
            m--;
            scanf("%d%d",&x,&y);
            r=g=b=255;
            for (int i=0;i<n;i++)
            if ((a[i][0]<=x)&&(a[i][1]<=y)&&(a[i][2]>=x)&&(a[i][3]>=y))
            {
                r=a[i][4];
                g=a[i][5];
                b=a[i][6];
            }
            printf("%d %d %d\n",r,g,b);
        }
        printf("\n");
    }
    return 0;
}

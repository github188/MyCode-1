#include<stdio.h>
struct rect
{
    int x1,x2,y1,y2,r,g,b;
} a[1000];

int main()
{
    int n,m;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n+m==0) break;
        for (int i=0;i<n;i++) scanf("%d%d%d%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].r,&a[i].g,&a[i].b);
        while (m--)
        {
            int j=n-1,r=255,g=255,b=255;
            int x,y;scanf("%d%d",&x,&y);
            while (j>=0)
            {
                if (((a[j].x2-x)>=0)&&((x-a[j].x1)>=0)&&((a[j].y2-y)>=0)&&((y-a[j].y1)>=0))
                {
                    r=a[j].r;
                    g=a[j].g;
                    b=a[j].b;
                    break;
                }
                j--;
            }
            printf("%d %d %d\n",r,g,b);
        }
    }
    return 0;
}

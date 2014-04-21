#include<stdio.h>
#include<algorithm>

struct node
{
    int x,y;
    bool operator<(node b) const
    {
        return x<b.x;
    }
};

int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        node a[2001];
        int n,k,s;
        scanf("%d%d%d",&n,&k,&s);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].y=i;
        }
        std::sort(a+1,a+1+n);
        int l=1,r=n;
        for (int i=1;i<=n;i++)
        {
            if (i&1) printf("%d",a[r--].y); else printf("%d",a[l++].y);
            if (i<n) printf(" "); else printf("\n");
        }
    }
    return 0;
}

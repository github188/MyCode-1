#include<stdio.h>
#include<algorithm>
using namespace std;

struct st
{
    int x,y;
} a[100],b[100];
int n,tt;

bool cmp(st a,st b)
{
    if (a.y>b.y) return true;
    return false;
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            a[i].x=i+1;
            a[i].y=0;
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (x==1) a[i].y++;
            }
        }
        sort(a,a+n,cmp);
        for (int i=0;i<n;i++)
        {
            b[i].x=i+1;
            b[i].y=0;
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (x==1) b[i].y++;
            }
        }
        sort(b,b+n,cmp);
        for (int i=0;i<n;i++)
        {
            printf("%d",a[i].x);
            if (i!=n-1) {printf(" ");} else printf("\n");
        }
        for (int i=0;i<n;i++)
        {
            printf("%d",b[i].x);
            if (i!=n-1) {printf(" ");} else printf("\n");
        }
    }
    return 0;
}

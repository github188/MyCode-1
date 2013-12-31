#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
} a[300000];
int n;

bool cmp1(node a,node b)
{
    return a.x<b.x;
}
bool cmp2(node a,node b)
{
    return a.y<b.y;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    sort(a,a+n,cmp1);
    int cur=a[0].x,ans=cur;
    for (int i=1;i<n;i++)
    {
        if (a[i].x<=cur) a[i].x=++cur;
        else cur=a[i].x;
        ans+=cur;
    }
    sort(a,a+n,cmp2);
    for (int i=0;i<n-1;i++) printf("%d ",a[i].x);
    printf("%d\n",a[n-1].x);
    return 0;
}

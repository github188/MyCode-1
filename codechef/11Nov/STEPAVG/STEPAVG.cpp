#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct st
{
    int x,y;
};
st a[1000];

bool cmp(st a,st b)
{
    if (a.x>b.x) return true;return false;
}

int main()
{
    int n,k,tt,c;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) {scanf("%d",&a[i].x);a[i].y=i;}
        sort(a+1,a+1+n,cmp);
        c=n;
        for (int i=1;i<=n-1;i++)
        {
            int d=c;if (c==n) {d=a[n].y;}
            printf("%d %d\n",a[i].y,d);
            c++;
        }
    }
    return 0;
}

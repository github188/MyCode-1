#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct st
{
    int no,val;
};
st a[100000];
int b[100000];
int n,t;

bool cmp(st a,st b)
{
    if (a.val>b.val) return true;
    return false;
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            a[i].no=i;a[i].val=b[i];
        }
        sort(a,a+n,cmp);
        int j=0,ans=0;
        for (int i=0;i<n-1;i++)
        {
            if (i==a[j].no)
            {
                j++;
                while (a[j].no<i) j++;
            }
            if (a[j].val-b[i]>ans) ans=a[j].val-b[i];
        }
        if (ans==0) {printf("UNFIT\n");} else {printf("%d\n",ans);}
    }
    return 0;
}

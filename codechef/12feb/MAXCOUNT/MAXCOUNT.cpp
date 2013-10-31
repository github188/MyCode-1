#include<stdio.h>
#include<string.h>

int a[10001];

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        memset(a,0,sizeof(a));
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int m;scanf("%d",&m);a[m]++;
        }
        int ans=0;
        for (int i=1;i<=10000;i++)
        if (a[i]>a[ans]) ans=i;
        printf("%d %d\n",ans,a[ans]);
    }
    return 0;
}

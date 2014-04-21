#include<stdio.h>
#include<algorithm>

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n;scanf("%d",&n);
        double naomi[1001],ken[1001];
        for (int i=0;i<n;i++) scanf("%lf",&naomi[i]);
        std::sort(naomi,naomi+n);
        for (int i=0;i<n;i++) scanf("%lf",&ken[i]);
        std::sort(ken,ken+n);
        int ans1=0,ans2=n;

        int h=0;
        for (int i=0;i<n;i++)
        {
            while ((h<n)&&(naomi[h]<=ken[i])) h++;
            if (h>=n) break;
            ans1++;h++;
        }

        h=0;
        for (int i=0;i<n;i++)
        {
            while ((h<n)&&(naomi[i]>=ken[h])) h++;
            if (h>=n) break;
            ans2--;h++;
        }

        printf("Case #%d: %d %d\n",t,ans1,ans2);
    }
    return 0;
}

#include<stdio.h>

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int m,n,ans;
        scanf("%d",&n);
        ans=n-1;
        m=10000;
        if (m>=n) m=n-1;
        for (int i=1;i<=m;i++)
        if ((n%i)==0)
        {
            int k=i,l=n/i;
            if (k<l)
            {
                int j=k;k=l;l=j;
            }
            if (k-l<ans) ans=k-l;
        }
        printf("%d\n",ans);
    }
    return 0;
}

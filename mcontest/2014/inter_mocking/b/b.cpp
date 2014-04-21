#include<stdio.h>

bool check(int len,int n,int a[])
{
    for (int i=0;i<=n-len-len;i++)
        for (int j=i+len;j<=n-len;j++)
        {
            bool ans=true;
            for (int k=0;k<len;k++)
                if (a[i+k]!=a[j+k]) {ans=false;break;}
            if (ans) return ans;
        }
    return false;
}

int main()
{
    int a[300];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int l=0,r=n/2;
    while (l<r)
    {
        int mid=(l+r)/2+1;
        if (check(mid,n,a)) l=mid; else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}

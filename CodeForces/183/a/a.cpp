#include<stdio.h>
int a[100000],b[100000],c[100000];
int n;

int main()
{
    scanf("%d",&n);
    if (n&1)
    {
        int k=n-2;
        for (int i=0;i<n;i++)
        {
            a[i]=i;
            if (k<0) k=n-1;
            b[i]=k;k-=2;
            c[i]=(a[i]+b[i])%n;
        }
        for (int i=0;i<n-1;i++) printf("%d ",a[i]);printf("%d\n",a[n-1]);
        for (int i=0;i<n-1;i++) printf("%d ",b[i]);printf("%d\n",b[n-1]);
        for (int i=0;i<n-1;i++) printf("%d ",c[i]);printf("%d\n",c[n-1]);
    } else printf("-1\n");
    return 0;
}

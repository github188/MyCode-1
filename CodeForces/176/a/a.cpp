#include<stdio.h>
int a[200000];
int n;

int main()
{
    scanf("%d",&n);
    if ((n-(n&1))%4==2) printf("-1\n");
    else
    {
        if (n&1) a[n/2+1]=n/2+1;
        for (int i=1;i<=n/2;i+=2)
        {
            a[i]=i+1;
            a[i+1]=n-i+1;
            a[n-i+1]=n-i;
            a[n-i]=i;
        }
        for (int i=1;i<n;i++) printf("%d ",a[i]);printf("%d\n",a[n]);
    }
    return 0;
}

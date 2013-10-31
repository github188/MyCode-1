#include<stdio.h>
/*
int c(int n,int r)
{
    int ans=1;
    for (int i=1;i<=r;i++)
    {
        ans=ans*(n-i+1);
        ans/=i;
    }
    return ans;
}
*/

int a[200];
int main()
{
    a[1]=0;a[2]=1;
    for (int i=3;i<=100;i++)
    {
        a[i]=(i-1)*(a[i-1]+a[i-2]);
        printf("%d\n",a[i]);
    }
    return 0;
}

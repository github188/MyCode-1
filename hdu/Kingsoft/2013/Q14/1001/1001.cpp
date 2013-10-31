#include<stdio.h>

int rev(int o)
{
    int a[20];a[0]=0;
    int p=1;if (o<0) {o=-o;p=-p;}
    while (o) {a[++a[0]]=o%10;o/=10;}
    int ans=0;
    for (int i=1;i<=a[0];i++) ans=ans*10+a[i];
    ans*=p;
    return ans;
}

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        int x,y,a,b;
        scanf("%d%d",&x,&y);
        a=(x+y)/2;
        b=(x-y)/2;
        printf("%d %d\n",rev(a)+rev(b),rev(a)-rev(b));
    }
    return 0;
}

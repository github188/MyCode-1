#include<stdio.h>

int main()
{
    int a,b,ans=0;
    scanf("%d%d",&a,&b);
    while (a>=b)
    {
        ans+=b;
        a=a-b+1;
    }
    ans+=a;
    printf("%d\n",ans);
    return 0;
}

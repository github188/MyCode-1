#include<stdio.h>

int main()
{
    int n,ans;
    //freopen("1.in","r",stdin);
    //freopen("2.out","w",stdout);
    while (true) {
    scanf("%d",&n);
    if (n==0) {break;}
    ans=0;
    for (int i=1;i<n;i++)
    {
        int b=i,c=0,d=i;
        while (b>0)
        {
            c=c*10+b%10;
            b/=10;
        }
        if (c+d==n) {ans++;}
    }
    printf("%d\n",ans);}
    return 0;
}

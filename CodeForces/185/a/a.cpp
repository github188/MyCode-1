#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if (n*(n-1)<=2*k)
    {
        printf("no solution\n");
        return 0;
    }
    printf("%d %d\n%d %d\n",0,0,0,2001);
    int l=2001,x=0,y=2001;
    n-=2;
    while (n--)
    {
        x++;y+=l;l++;
        printf("%d %d\n",x,y);
    }
    return 0;
}

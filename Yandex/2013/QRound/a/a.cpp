#include<stdio.h>
int a[3];
int n,l,x,y;

int main()
{
    scanf("%d%d",&n,&l);
    a[0]=a[1]=0;
    while (n--)
    {
        scanf("%d%d",&x,&y);
        if (y<0) a[x]++;
        else if (y>l) a[x]+=3; else a[x]+=2;
    }
    printf("%d:%d\n",a[1],a[2]);
    return 0;
}

#include<stdio.h>
int a,b,x,y;

int main()
{
    scanf("%d%d%d%d",&a,&b,&x,&y);
    for (int i=29;i>=1;i--)
    if (a>(1<<i))
    {
        a-=(1<<i);
        b-=(1<<i);
    } else {break;}
    for (int i=29;i>=1;i--)
    if (x>(1<<i))
    {
        x-=(1<<i);
        y-=(1<<i);
    } else {break;}
    return 0;
}

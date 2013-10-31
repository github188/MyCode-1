#include<stdio.h>

int main()
{
    int x,n;
    scanf("%d",&x);
    if (x==1) {n=1;} else
    if (x==2) {n=3;} else
    if (x==3) {n=5;} else
    {
        for (int i=1;i<=100;i++)
        {
            int a=1+4*((i*i)/2+(i*i)%2+i/2);
            if (a>=x) {n=i*2+1;break;}
        }
    }
    printf("%d\n",n);
    return 0;
}

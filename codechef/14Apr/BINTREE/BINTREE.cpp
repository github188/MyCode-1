#include<stdio.h>

void To2Based(int x,int a[])
{
    a[0]=0;
    while (x)
    {
        a[++a[0]]=(x&1);
        x/=2;
    }
}

int main()
{
    int a[50],b[50];
    int t;scanf("%d",&t);
    while (t--)
    {
        int x,y;scanf("%d%d",&x,&y);
        To2Based(x,a);
        To2Based(y,b);
        int h=0;
        while ((h<a[0])&&(h<b[0]))
        {
            if (a[a[0]-h]!=b[b[0]-h]) break;
            h++;
        }
        printf("%d\n",a[0]+b[0]-h*2);
    }
    return 0;
}

#include<stdio.h>

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n,c;
        scanf("%d%d",&n,&c);
        while (n>0)
        {
            int x;
            scanf("%d",&x);
            c-=x;
            n--;
        }
        if (c>=0) {printf("Yes\n");} else {printf("No\n");}
    }
    return 0;
}

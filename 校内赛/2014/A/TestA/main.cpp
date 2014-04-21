#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    freopen("a.in","w",stdout);
    printf("9999\n");
    srand(time(NULL));
    for (int i=0;i<9999;i++)
    {
        int x,y;x=rand()%1000000000;
        if (x==0) x+=2;
        y=rand()%x;
        if (y==0) y=1;
        printf("%d %d\n",x,y);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    freopen("1.txt","w",stdout);
    printf("100000 250000\n");
    srand(time(NULL));
    for (int i=0;i<100000;i++)
    {
        int r=rand();
        printf("%d\n",r);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    freopen("b.in","w",stdout);
    srand(time(NULL));
    printf("9\n");
    for (int i=0;i<9;i++)
    {
        printf("499 499\n");
        for (int j=0;j<499;j++)
        {
            for (int j=0;j<499;j++)
            {
                if (j>0) printf(" ");
                int x=rand()%1000000000;
                printf("%d",x);
            }
            printf("\n");
        }
    }
    return 0;
}

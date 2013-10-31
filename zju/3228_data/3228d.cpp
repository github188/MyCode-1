#include<stdlib.h>
#include<stdio.h>
int main()
{
    freopen("in","w",stdout);
    for (int i=0;i<100000;i++) printf("%c",rand()%26+'a');
    printf("\n100000\n");
    for (int i=0;i<100000;i++)
    {
        printf("0 ");
        for (int i=0;i<6;i++) printf("%c",rand()%26+'a');
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    freopen("d.in","w",stdout);
    printf("100\n");
    srand(time(NULL));
    for (int i=0;i<100;i++)
    {
        int isYes = rand()%2,pos = -1;
        if (isYes) pos=rand()%970;
        for (int j=0;j<1000;j++)
        if (j==pos)
        {
            printf("fbiwarning");
            j+=10;
        } else printf("%c",rand()%26+'a');
        printf("\n");
    }
    return 0;
}

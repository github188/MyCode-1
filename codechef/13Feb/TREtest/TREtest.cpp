#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    freopen("1.out","w",stdout);
    printf("300000 300000\n");
    for (int i=0;i<300000;i++) printf("%d %d\n",rand()%300000+1,rand()%300000+1);
    for (int i=0;i<300000;i++) printf("%d %d %d\n",rand()%300000+1,rand()%300000+1,rand()%300000+1);
    return 0;
}

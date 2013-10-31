#include<stdio.h>
int main()
{
    int u=300000;
    freopen("1.in","w",stdout);
    printf("%d\n",u);
    for (int i=1;i<u;i++) printf("%d %d\n",i,i+1);
    for (int i=0;i<u;i++) printf("1 ");printf("\n");
    return 0;
}

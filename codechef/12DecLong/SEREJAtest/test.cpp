#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    freopen("1.txt","w",stdout);
    printf("100000\n");int u,v;u=v=-1;
    for (int i=0;i<100000;i++)
    {
        u=rand()%1000000007;
        if (u==v)u++;
        printf("%d ",u);
        v=u;
    }
    return 0;
}

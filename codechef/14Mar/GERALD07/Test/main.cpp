#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    freopen("1.txt","w",stdout);
    srand(time(NULL));
    int t=6,n=33333;
    printf("%d\n",t);
    for (int i=0;i<t;i++)
    {
        printf("%d %d %d\n",n,n,n);
        for (int i=0;i<n;i++)
        {
            int x=rand()%n+1,y=rand()%n+1;
            printf("%d %d\n",x,y);
        }
        for (int i=0;i<n;i++)
        {
            int x=rand()%n+1,y=rand()%n+1;
            if (x>y)
            {
                int z=x;x=y;y=z;
            }
            printf("%d %d\n",x,y);
        }
    }
    return 0;
}

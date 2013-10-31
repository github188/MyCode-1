#include<stdio.h>
int main()
{
    int a=103993,b=33102;
    int t;scanf("%d",&t);
    while (t--)
    {
        int k,f=a,g=b;scanf("%d",&k);
        printf("3");
        if (k>0)
        {
            f=f%g;printf(".");
            while (k--)
            {
                printf("%d",f*10/g);
                f=f*10%g;
            }
        }
        printf("\n");
    }
    return 0;
}

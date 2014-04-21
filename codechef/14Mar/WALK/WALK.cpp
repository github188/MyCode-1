//An easy problem. Scanning it.

#include<stdio.h>

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int num;scanf("%d",&num);
        int ans=0;
        for (int i=0;i<num;i++)
        {
            int current;scanf("%d",&current);
            if (current+i>ans) ans=current+i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

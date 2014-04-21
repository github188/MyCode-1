//An easy problem. Scanning it.
#include<stdio.h>

int main()
{
    int test;scanf("%d",&test);
    while (test--)
    {
        int num;scanf("%d",&num);
        long long ans=0;
        long long Big_than_One=0,Num_of_Two=0,Two=2;
        while (num--)
        {
            int current;scanf("%d",&current);
            if (current>1) ans+=Big_than_One++;
            if (current==2) Num_of_Two++;
        }
        ans-=(Num_of_Two*Num_of_Two-Num_of_Two)/Two;
        printf("%lld\n",ans);
    }
    return 0;
}

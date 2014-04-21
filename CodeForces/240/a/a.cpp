#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int x=-1,y=-1;
    if ((n/2>k)||((n==1)&&(k>0)))
    {
        printf("-1\n");
    } else
    if (n/2<k)
    {
        x=k-n/2+1;
        y=x*2;
        printf("%d %d",x,y);
        int j=1;
        for (int i=1;i<n/2;i++)
        {
            while ((j==x)||(j==y)||(j+1==x)||(j+1==y)) j+=2;
            printf(" %d %d",j,j+1);
            j+=2;
        }
        while ((j==x)||(j==y)) j++;
        if (n&1) printf(" %d\n",j);
    } else
    if (n/2==k)
    {
        for (int i=0;i<n;i++)
        {
            printf("%d",i+1);
            if (i<n-1) {printf(" ");} else {printf("\n");}
        }
    }
    return 0;
}

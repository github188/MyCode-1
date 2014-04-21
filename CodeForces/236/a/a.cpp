#include<stdio.h>
int a[30];

int main()
{
    int test;scanf("%d",&test);
    while (test--)
    {
        int n,p;scanf("%d%d",&n,&p);
        int m=0;
        for (int i=2;i<=n;i++)
        {
            a[i]=i+1;
            printf("%d %d\n",1,i);
            m++;
        }
        int k=2;
        while (m<n+n+p)
        {
            if (k>n) k=2;
            if (a[k]>n) {k++;continue;}
            printf("%d %d\n",k,a[k]);
            a[k++]++;
            m++;
        }
    }
    return 0;
}

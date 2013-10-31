#include<stdio.h>
bool prime[100000];
int max=100000;

int main()
{
    for (int i=2;i<max;i++)
    if (!prime[i])
    {
        int j=i;
        while (j+i<max)
        {
            j+=i;
            prime[j]=true;
        }
    }
    int n;scanf("%d",&n);
    for (int i=4;i<=n;i++)
    {
        if ((!prime[i-1])&&(!prime[i+1])) printf("%d\n",i);
    }
    return 0;
}

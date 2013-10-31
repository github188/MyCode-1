#include<stdio.h>
bool isP[11000];
int a[10000];

int main()
{
    for (int i=2;i<=10000;i++)
    if (!isP[i])
    {
        a[0]++;
        a[a[0]]=i;
        int j=i;
        while (j+i<=10000)
        {
            j+=i;
            isP[j]=true;
        }
    }

    int t;scanf("%d",&t);
    while (t>0)
    {
        t--;int n,m,k;
        scanf("%d",&n);m=n;k=n;
        int i=1;
        while ((i<=a[0])&&(k!=1))
        if ((k%a[i])==0)
        {
             while ((k%a[i])==0)
            {
                 k=k/a[i];
            }
            m=m*(a[i]-1)/a[i];
            i++;
        } else {i++;}
        printf("%d\n",m);

    }
    return 0;
}

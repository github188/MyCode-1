#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int a[100];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int sum=0,j=-1;
    for (int i=0;i<n;i++)
    if (sum+a[i]<=710)
    {
        sum+=a[i];
        j=i;
    }
    printf("%d ",j+1);
    if (sum==0) {printf("0\n");}
    else
    {
        int ans=0;
        while (j>=0)
        {
            if (sum-a[j]>=350)
            {
                ans+=sum-350;
                sum-=a[j];
                j--;
            } else
            {
                ans+=sum-350;
                break;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

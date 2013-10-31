#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int a[20001];
int n,m,sum,ans;

int main()
{
    scanf("%d",&n);ans=0;
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);ans+=a[i];}

    int n2=n/2;
    for (int i=3;i<=n2;i++)
    if ((n%i)==0)
    {
        int d=(n-i)/i+1;
        for (int j=0;j<d;j++)
        {
            sum=0;
            for (int k=j;k<n;k+=d)
            {
                sum+=a[k];
            }
            if (sum>ans) ans=sum;
        }
    }

    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int a[100];
int n,k;

bool cmp(int o,int p)
{
    if (o>p) return true;return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    int ans=0,i=0;
    while ((i<n)&&(a[i]>=a[k-1])&&(a[i]>0))
    {
        ans++;
        i++;
    }
    printf("%d\n",ans);
    return 0;
}

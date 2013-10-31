#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[100000];
int q,n,m;

int main()
{
    scanf("%d",&m);
    int min=1e9;
    for (int i=0;i<m;i++)
    {
        int tmp;scanf("%d",&tmp);
        if (tmp<min) min=tmp;
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0,num=0;
    for (int i=n-1;i>=0;i--)
    if (num==min) {i--;num=0;}
    else
    {
        ans+=a[i];
        num++;
    }
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10000],b[10000];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    k=n-k;
    sort(b,b+n);
    printf("%d\n",b[k]);
    int x=k+1,y=k-1,p=1;
    while ((x<n)&&(b[x]==b[k])) {x++;p++;}
    for (int i=0;i<n;i++)
    if (a[i]>b[k]) printf("%d ",i+1); else
    if ((a[i]==b[k])&&(p)) {p--;printf("%d ",i+1);}
    printf("\n");
    return 0;
}

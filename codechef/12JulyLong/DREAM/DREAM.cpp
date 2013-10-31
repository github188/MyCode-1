#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    int value,pos;
} a[100000];
int n,k;

bool cmp(node a,node b) {return ((a.value<b.value)||((a.value==b.value)&&(a.pos<b.pos)));}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].value);
        a[i].pos=i;
    }
    sort(a,a+n,cmp);

    int h=0,ans=0;
    while (h<n)
    {
        int p=a[h].pos;
        ans++;
        while ((h+1<n)&&(a[h+1].value==a[h].value)&&(a[h+1].pos-p<k)) h++;
        h++;
    }
    printf("%d\n",ans);
    return 0;
}

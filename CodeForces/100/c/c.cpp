#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int a[100000];
int n;
int ans[10000][3];

bool ok(int o)
{
    int p=0,q=n-o,r=o,s=0;
    while (o>0)
    {
        o--;
        while (((a[r]==a[p])||(a[r]==a[q]))&&(r<q)) r++;
        if (r>=q) return false;
        ans[s][0]=a[q];
        ans[s][1]=a[r];
        ans[s][2]=a[p];
        p++;q++;r++;s++;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int l,r;l=0;r=n/3;
    while (l!=r)
    {
        int mid=(l+r)/2;
        if (ok(mid+1)) {l=mid+1;}
        else {r=mid;}
    }
    printf("%d\n",l);
    for (int i=0;i<l;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}

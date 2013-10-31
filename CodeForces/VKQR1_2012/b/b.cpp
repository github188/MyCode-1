#include<stdio.h>

int a[5];
int n,ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    ans=a[4];
    ans+=a[3];
    if (a[1]>=a[3]) {a[1]-=a[3];} else {a[1]=0;}
    ans+=a[2]/2;
    if ((a[2]&1)==1)
    {
        ans++;
        if (a[1]>=2) {a[1]-=2;} else {a[1]=0;}
    }
    ans+=a[1]/4;
    if ((a[1]%4)!=0) ans++;
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
int a[100000],b[100000],c[100000];
int n,ans;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (a[0]>=0) b[0]=1;
    if (a[n-1]<=0) c[n-1]=1;
    for (int i=1;i<n;i++) if (a[i]>=0) b[i]=b[i-1]+1; else b[i]=b[i-1];
    for (int i=n-2;i>=0;i--) if (a[i]<=0) c[i]=c[i+1]+1; else c[i]=c[i+1];
    ans=b[0]+c[1];
    for (int i=1;i<n-1;i++) ans=ans<b[i]+c[i+1]?ans:b[i]+c[i+1];
    printf("%d\n",ans);
    return 0;
}

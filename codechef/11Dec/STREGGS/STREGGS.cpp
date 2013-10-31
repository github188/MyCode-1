#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

int a[500],f[500][501];
int n,k;

inline int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d",&n,&k);
        for (int i=0;i<n;i++) for (int j=1;j<=k;j++) f[i][j]=500000001;
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for (int i=0;i<n;i++) f[i][1]=a[i];

        for (int i=2;i<=k;i++)
        {
            for (int j=i-1;j<n;j++)
              for (int l=i-2;l<j;l++) f[j][i]=min(f[j][i],f[l][i-1]+a[j]+a[l]*(j-l-1));
        }

        int ans=f[n-1][k];
        for (int i=k-1;i<n-1;i++) ans=min(ans,f[i][k]+a[i]*(n-1-i));
        printf("%d\n",ans);
    }
    return 0;
}

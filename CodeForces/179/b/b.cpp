#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long f[501][501],g[501][501];
int n;
long long a[501],b[501],stack[501];

long long min(long long o,long long p)
{
    return o<p?o:p;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++) scanf("%I64d",&f[i][j]);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    int size=0;
    for (int i=n;i>=1;i--)
    {
        for (int j=size-1;j>=0;j--)
        {
            g[a[i]][stack[j]]=f[a[i]][stack[j]];
            g[stack[j]][a[i]]=f[stack[j]][a[i]];
        }
        for (int j=size-1;j>=0;j--)
          for (int k=size-1;k>=0;k--)
           if (j!=k)
           {
               g[a[i]][stack[k]]=min(g[a[i]][stack[k]],g[a[i]][stack[j]]+g[stack[j]][stack[k]]);
               g[stack[k]][a[i]]=min(g[stack[k]][a[i]],g[stack[k]][stack[j]]+g[stack[j]][a[i]]);
           }
        for (int j=size-1;j>=0;j--)
          for (int k=size-1;k>=0;k--)
           if (j!=k)
           {
               g[stack[j]][stack[k]]=min(g[stack[j]][stack[k]],g[stack[j]][a[i]]+g[a[i]][stack[k]]);
               g[stack[k]][stack[j]]=min(g[stack[k]][stack[j]],g[stack[k]][a[i]]+g[a[i]][stack[j]]);
           }
        stack[size++]=a[i];
        for (int j=size-1;j>=0;j--)
          for (int k=size-1;k>=0;k--) b[i]+=g[stack[j]][stack[k]];
    }
    for (int i=1;i<n;i++) printf("%I64d ",b[i]);printf("%I64d\n",b[n]);
    return 0;
}

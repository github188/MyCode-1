#include<stdio.h>
int f[1001],a[500],h[500];
int n;

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&h[i]);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=1000;i++) f[i]=1001;
        f[0]=0;
        for (int i=0;i<1000;i++)
          if (f[i]!=1001)
            for (int j=0;j<n;j++)
              if (i+a[j]<=1000) f[i+a[j]]=f[i+a[j]]<f[i]+1?f[i+a[j]]:f[i]+1;
        int ans=0;
        for (int i=0;i<n;i++) ans+=f[h[i]<<1];
        printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>

int a[3000],c[3000];
bool b[3000];

int check(int o)
{
    if (a[o]==-1) {return 1;}
    if (!b[o]) {return c[o];}
    return check(a[o])+1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {scanf("%d",&a[i]);b[i]=true;}
    int ans=0;
    for (int i=1;i<=n;i++)
    if (b[i])
    {
              if (a[i]==-1) {c[i]=1;b[i]=false;}
              else
              {
                  c[i]=check(i);
                  b[i]=false;
              }
              if (c[i]>ans) {ans=c[i];}
    }
    printf("%d\n",ans);
    return 0;
}

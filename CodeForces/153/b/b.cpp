#include<stdio.h>
int a[101],b[101],c[101],d[101],s[101];
int n,k;

bool check()
{
    for (int i=1;i<=n;i++) if (c[i]!=b[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    bool ans=false;
    for (int i=1;i<=n;i++) c[i]=i;
    if (!check()) {
    for (int i=1;i<=n;i++) c[i]=i;
    bool u1,u2;u1=u2=false;
    for (int i=1;i<=k;i++)
    {
        for (int i=1;i<=n;i++) d[i]=c[a[i]];
        for (int i=1;i<=n;i++) c[i]=d[i];
        if ((check())&&(((k-i)&1)==0))
        {
            //if (i==1) u1=true;
            ans=true;break;
        }
    }
    for (int i=1;i<=n;i++) d[a[i]]=i;
    for (int i=1;i<=n;i++) a[i]=d[i];
    for (int i=1;i<=n;i++) c[i]=i;
    for (int i=1;i<=k;i++)
    {
        for (int i=1;i<=n;i++) d[i]=c[a[i]];
        for (int i=1;i<=n;i++) c[i]=d[i];
        if ((check())&&(((k-i)&1)==0))
        {
            //if (i==1) {u2=true;}
            ans=true;break;
        }
    }
    //if ((u1&u2)&&(k!=1)) ans=false;
    }
    if (ans) printf("YES\n"); else printf("NO\n");

    return 0;
}

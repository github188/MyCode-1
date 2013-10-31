#include<stdio.h>
#include<string.h>
int n,m;
char s[100];
int f[3000000],g[3000000];

inline void work(int o,int p,int q)
{
    for (int i=0;i<=n-1;i++)
    {
        int t=((o|(p>>i))&q);
        if (f[t]==0) f[t]=f[o]+1;
        else f[t]=f[t]>f[o]+1?f[o]+1:f[t];
    }
    for (int i=1;i<=m-1;i++)
    {
        int t=((o|(p<<i))&q);
        if (f[t]==0) f[t]=f[o]+1;
        else f[t]=f[t]>f[o]+1?f[o]+1:f[t];
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%s%d",&s,&m);
        memset(f,0,sizeof(f));
        int a,b,c;a=b=0;c=(1<<n)-1;
        for (int i=0;i<n;i++)
        if (s[i]=='*') {a+=(1<<i);b+=(1<<(n-1-i));}

        c=(1<<m)-1;
        if (a!=0) work(0,a,c);
        if (b!=0) work(0,b,c);
        for (int i=1;i<(1<<m);i++)
        if (f[i]!=0)
        {
            if (a!=0) work(i,a,c);
            if (b!=0) work(i,b,c);
        }
        if (f[c]==0) {printf("-1\n");} else printf("%d\n",f[c]);
    }
    return 0;
}

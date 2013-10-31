#include<stdio.h>
int a[1000001];

int main()
{
    int f=1,g=1,mod=1000000007;
    for (int i=1;i<=1000000;i++)
    {
        int gg=g;
        while (gg>0) {a[i]+=(gg&1);gg>>=1;}
        int c=f;f=g;g=g+c;if (g>=mod) g-=mod;
    }
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if (y==a[x]) printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}

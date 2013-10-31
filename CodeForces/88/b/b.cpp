#include<stdio.h>
bool use[10000000];
int main()
{
    int a,b,mod;
    scanf("%d%d%d",&a,&b,&mod);
    if (b>=mod-1) {printf("2\n");}
    else
    {
        int u,v;
        u=1000;u=u*u*u;
        u=u%mod;
        v=0;int s=0;
        while (true)
        {
            s++;v+=u;
            if (u>=mod) {u-=mod;}
            if (use[u]) {
        printf("2\n");return 0;}
        use[u]=true;
            if ((u>=1)&&(u<=mod-b-1)) {break;}
        }
        char c[9];
        printf("1 ");
        for (int i=0;i<9;i++) {c[i]='0';}
        int k=8;
        while (s>0)
        {
            c[k]='0'+s%10;
            s=s/10;
        }

        for (int i=0;i<9;i++) {printf("%c",c[i]);}printf("\n");
    }
    return 0;
}

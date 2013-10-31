#include<stdio.h>
int f[500001],g[500001],h[500001];

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n,k;
        scanf("%d%d",&n,&k);
        f[1]=0;
        for (int i=2;i<=n;i++) f[i]=(f[i-1]+k)%i;
        g[2]=1-f[2];
        for (int i=3;i<=n;i++) g[i]=(g[i-1]+k)%i;
        h[3]=0;
        bool use[3];
        use[0]=use[1]=use[2]=false;
        use[f[3]]=use[g[3]]=true;
        for (int i=0;i<3;i++) if (!use[i]) h[3]=i;
        for (int i=4;i<=n;i++) h[i]=(h[i-1]+k)%i;

        int a,b,c;
        a=f[n];
        b=g[n];
        c=h[n];
        printf("%d %d %d\n",c+1,b+1,a+1);
    }
    return 0;
}

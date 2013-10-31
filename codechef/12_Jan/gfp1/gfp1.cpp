#include<stdio.h>
#include<string.h>

bool f[70000000];
int a[10][10];

void work(int o,int p,int x,int y)
{
    if (o==x)
    {
        int ans=0;
        for (int i=0;i<x;i++)
        for (int j=0;j<y;j++)
        {
            int u=(a[i][j]^1);
            for (int k=0;k<y;k++) u=(u^a[i][k]);
            for (int k=0;k<x;k++) u=(u^a[k][j]);
            ans+=(u<<(i*y+j));
        }
        f[ans]=true;
        return;
    }
    int oo=o,pp=p+1;
    if (pp==y) {oo++;pp=0;}
    a[o][p]=0;
    work(oo,pp,x,y);
    a[o][p]=1;
    work(oo,pp,x,y);
}

int main()
{/*
    int maxl=6,maxr=6;
    for (int i=1;i<=maxl;i++)
    {
       for (int j=1;j<=maxr;j++)
       {
           memset(f,false,sizeof(f));
           work(0,0,i,j);
           int ans=0;
           for (int k=0;k<(1<<(i*j));k++)
           if (f[k]) ans++;
           printf("%d ",ans);
       }
       printf("\n");
    }
*/

    long long mod=1000000007,a=2,b=1;
    while (a!=1)
    {
        a=((a<<1)%mod);
        b++;
    }
    printf("%lld\n",b);

    return 0;
}

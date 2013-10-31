#include<stdio.h>
#include<iostream>
using namespace std;
unsigned long long f[70][70];
int g[70][70],h[70][70];
bool use[70];
int n,m;

void work(int n,int nn,int o,int p)
{
    if (n==0) return;
    if (n==1)
    {
        printf("move %d from %d to %d",h[o][h[o][0]],o,p);
        if (h[p][0]>0) printf(" atop %d",h[p][h[p][0]]);
        printf("\n");
        h[p][++h[p][0]]=h[o][h[o][0]];
        h[o][0]--;
        return;
    }
    int k=0;
    for (int i=1;i<=m;i++)
    if ((!use[i])&&(i!=o)&&(i!=p)) {k=i;break;}
    work(g[n][nn],nn,o,k);
    use[k]=true;
    work(n-g[n][nn],nn-1,o,p);
    use[k]=false;
    work(g[n][nn],nn,k,p);
}

int main()
{
    f[1][3]=1;
    for (int i=2;i<=64;i++)
    {
        unsigned long long one=1,tmp=0;
        tmp=f[i-1][3];
        tmp+=one;
        tmp<<=1;
        tmp-=one;
        f[i][3]=tmp;
        g[i][3]=i-1;
    }
    for (int i=3;i<=65;i++) {f[2][i]=3;f[1][i]=1;g[2][i]=1;}
    unsigned long long ans=0;
    for (int i=4;i<=65;i++)
     for (int j=3;j<=64;j++)
     {
         unsigned long long two=2;
         f[j][i]=f[1][i]*two+f[j-1][i-1];
         int l=1;
         for (int k=2;k<j;k++)
         {
             unsigned long long tmp=f[k][i]*two+f[j-k][i-1];
             if (f[j][i]>tmp) {f[j][i]=tmp;l=k;}
         }
         if (f[j][i]>ans) {ans=f[j][i];}
         g[j][i]=l;
     }
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d%d",&n,&m);
        cout<<f[n][m]<<endl;
        for (int i=1;i<=m;i++) {h[i][0]=0;use[i]=false;}
        for (int i=n;i>0;i--) h[1][++h[1][0]]=i;
        work(n,m,1,m);
        //printf("\n");
    }
    return 0;
}

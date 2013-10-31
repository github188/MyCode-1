#include<iostream>
#include<string.h>
using namespace std;
long long n,mod;
int a[16];
long long f[16],st[16][16],g[16][16],tmp[16][16];

void work(long long n)
{
    if (n==0) return;
    work(n>>1);
    for (int i=0;i<=15;i++)
     for (int j=0;j<=15;j++)
     {
         tmp[i][j]=0;
         for (int k=0;k<=15;k++)
         {
             tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j])%mod;
         }
     }

   for (int i=0;i<=15;i++) for (int j=0;j<=15;j++) g[i][j]=tmp[i][j];

   if ((n&1)==0) return;

    for (int i=0;i<=15;i++)
     for (int j=0;j<=15;j++)
     {
         tmp[i][j]=0;
         for (int k=0;k<=15;k++)
         {
             tmp[i][j]=(tmp[i][j]+g[i][k]*st[k][j])%mod;
         }
     }

   for (int i=0;i<=15;i++) for (int j=0;j<=15;j++) g[i][j]=tmp[i][j];
}

int main()
{
    mod=1000000007;
    int tt;cin>>tt;
    while (tt>0)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(st,0,sizeof(st));
        tt--;
        cin>>n>>a[0];
        for (int i=1;i<=a[0];i++) cin>>a[i];
        f[0]=1;
        for (int i=1;i<=15;i++)
          for (int j=1;j<=a[0];j++)
            if (i-a[j]>=0) f[i]+=f[i-a[j]];
        for (int i=0;i<15;i++) st[i+1][i]=1;
        for (int i=1;i<=a[0];i++) st[16-a[i]][15]=1;
        if (n<=15) {int nn=n;cout<<f[nn]<<endl;continue;}
        for (int i=0;i<=15;i++) g[i][i]=1;
        n-=15;
        work(n);
        long long ans=0;
        for (int i=0;i<=15;i++)
        {
            ans=(ans+f[i]*g[i][15])%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

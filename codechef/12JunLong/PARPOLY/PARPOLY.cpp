#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
long long f[801][801],a[801][801];
int m,n,d;
long long x;
long long c[50],g[801];
long long maxl=1000000007;
long long tmp[801][801];
inline void work(long long a[][801],long long b[][801])
{
        tmp[0][0]=(a[0][0]*b[0][0])%maxl;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<i;j++) tmp[i-j][i]=tmp[i-j-1][i-1];
 tmp[0][i]=0;
        for (int j=0;j<=i;j++) tmp[0][i]=(tmp[0][i]+a[0][j]*b[j][i])%maxl;
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j]=tmp[i][j];
}

void mul1(int o)
{
    if (o==1) return;
    mul1(o/2);
    work(f,f);
    if ((o&1)==1) work(f,a);
}

int main()
{
    int tt;
    cin>>tt;
    while (tt>0)
    {
        tt--;
        cin>>m>>n>>x>>d;
        for (int i=0;i<=m;i++) for (int j=0;j<=n;j++) f[i][j]=0;
        for (int i=0;i<=d;i++) cin>>c[i];
        long long mul=0;
        for (int i=0;i<=n;i++)
        {
            long long tmp=1;
            g[i]=0;
            for (int j=0;j<=d;j++)
            {
                g[i]=(g[i]+tmp*c[j])%maxl;
                tmp=(tmp*mul)%maxl;
            }
            mul=(mul+x)%maxl;
        }
        /*
        for (int i=0;i<=n;i++) f[1][i]=g[i];
        for (int i=1;i<m;i++)
         for (int j=0;j<=n;j++)
          if (f[i][j]!=0)
           for (int k=0;k<=n-j;k++)
            f[i+1][j+k]=(f[i+1][j+k]+f[i][j]*g[k])%maxl;
        */
        for (int i=0;i<=n;i++)
         for (int j=0;j<=i;j++) f[j][i]=a[j][i]=g[i-j];
        mul1(m);
        //long long ans=0;
        //for (int i=0;i<=m;i++) ans=(ans+f[i][n])%maxl;
        cout<<f[0][n]<<endl;
    }
    return 0;
}

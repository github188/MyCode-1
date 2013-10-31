#include<stdio.h>
long long mod=1000000007;
long long a[2100][2100],b[2100],ans[2100];
int n;
long long inv[10001],fact[10001],ifact[10001];
#include <cstdlib>
#include <iostream>
using namespace std;
int d[200001]={};
void get_pri(int n, int k) {
    int i, j,cnt=0,z=k,f=n;
    while (k--) {
        n=f-k;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0){
                    n = n / i;
                    d[i]++;
                }
            }
        }
        if(n!=1)
        d[n]++;
    }
    while(z--){
        int dd=z+1;
        for (i = 2; i * i <= dd; i++) {
            if (dd % i == 0) {
                while (dd % i == 0){
                   dd = dd / i;
                    d[i]--;
                }
            }
        }
        if(dd!=1)
        d[dd]--;
    }
}
long long choose(int n,int r)
{
    if ((r==0)||(n==r)) return 1;
    long long u,v,w;
    long long ans=((u*v)%mod)*w%mod;
    return ans;
}

long long modulo_power(long long o,int p)
{
    if (p==1) return o;
    long long ans=modulo_power(o,p>>1);
    ans=(ans*ans)%mod;
    if (p&1)
    {
        ans=(ans*o)%mod;
    }
    return ans;
}

int main()
{
    get_pri(1000000000);
    for (int i=2;i<=10000;i++) inv[i]=modulo_power(i,1000000005);
    fact[1]=ifact[1]=1;
    for (int i=2;i<=10000;i++)
    {
        long long u=i;
        fact[i] = (fact[i-1]*u)%mod;
        ifact[i] = (ifact[i-1]*inv[i])%mod;
    }
    /*
    c[0][0]=1;
    for (int i=1;i<4100;i++)
      for (int j=0;j<=i;j++)
      {
          c[i][j]=c[i-1][j];
          if (j!=0) c[i][j]+=c[i-1][j-1];
          if (c[i][j]>=mod) c[i][j]-=mod;
      }
    */
    int k;
    scanf("%d%d",&n,&k);
    k--;
    if (k>=0) {
    for (int i=0;i<n;i++) a[0][i]=get_pri(k+i,i);
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++) a[i][j]=0;
        for (int j=i;j<n;j++) a[i][j]=a[0][j-i];
    }} else
    {
        for (int i=0;i<n;i++) a[i][i]=1;
    }
    for (int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        b[i]=x;
    }
    for (int i=0;i<n;i++)
    {
        ans[i]=0;
        for (int j=0;j<n;j++) ans[i]=(ans[i]+b[j]*a[j][i])%mod;
    }
    for (int i=0;i<n;i++)
    {
        int x;
        x=ans[i];printf("%d",x);
        if (x!=n-1) {printf(" ");} else {printf("\n");}
    }

    return 0;
}

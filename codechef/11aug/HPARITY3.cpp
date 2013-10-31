#include<stdio.h>
#include<iostream>
using namespace std;
long long mod=1000000009;
long long mat[9][51],c[2][9],d[9];
bool a[9][51],b[9];

long long work(int n,int m,int tot)
{
     if (n<0) {return 1;}
     if (m==tot) {return mat[tot][n+1];}
     long long ans=0;
     bool bo[9];
     int u=0;
     for (int i=1;i<=tot;i++)
     {
         bo[i]=false;
         if ((a[i][n])&&(!b[i])) {b[i]=bo[i]=true;u++;}
     }
     
     long long kk=m+1;
     ans=(ans+work(n-1,m+u,tot)*kk);
     for (int i=1;i<=tot;i++)
     if (bo[i])
     {
        b[i]=false;
        ans=(ans+work(n-1,m+u-1,tot));
        b[i]=true;
     }
     ans=ans%mod;
     for (int i=1;i<=tot;i++) {b[i]=(b[i]^bo[i]);}
     
     return ans;
}

long long deal(int n)
{
     for (int i=1;i<=n;i++)
          {
              if (d[i]<0) {return 0;}
              b[i]=false;
              long long k;k=d[i];
              long long two=2;
              for (int j=0;j<=50;j++)
              {
                  long long one=(k&1);
                  k=(k>>1);
                  if (one!=0)
                  {
                      a[i][j]=true;
                  } else {a[i][j]=false;}
              }
          }
     return work(50,0,n);
}

int main()
{
    for (int i=1;i<9;i++)
    {
        mat[i][0]=1;
        long long u=i+1;
        for (int j=1;j<=50;j++) { mat[i][j]=(mat[i][j-1]*u)%mod; }
    }
    
    int t=0;
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          int n;
          scanf("%d",&n);
          for (int i=1;i<=n;i++) {cin>>c[0][i];}
          for (int i=1;i<=n;i++) {cin>>c[1][i];}
          
          long long ans=0;
          for (int i=0;i<(1<<n);i++)
          {
              int k=i;
              int num=0;
              for (int j=0;j<n;j++)
              {
                  if ((k&1)==1) {num++;d[j+1]=c[1][j+1]; }
                  else {d[j+1]=c[0][j+1]-1;}
                  k=(k>>1);
              }
              long long u=1;
              if ((num&1)!=(n&1)) {u=-1;}
              ans=(ans+deal(n)*u)%mod;
              
              if (ans<0) {ans+=mod;}
          }
          cout<<ans<<endl;
    }
    return 0;
}

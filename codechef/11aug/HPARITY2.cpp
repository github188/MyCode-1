#include<stdio.h>
long long mod=1000000009;
long long mat[9][51];
bool a[9][51],b[9];

long long work(int n,bool b[],int m,int tot)
{
     if (n<0) {return 1;}
     if (m==tot) {return mat[tot][n+1];}
     long long ans=0;
     bool bo[9];
     int u=0;
     for (int i=1;i<=tot;i++)
     {
         bo[i]=false;
         if ((a[i][n])&&(!b[i])) {bo[i]=true;u++;}
     }
     
     for (int i=1;i<=tot;i++) b[i]=(b[i]|bo[i]);long long kk=m+1;
     ans=(ans+work(n-1,b,m+u,tot)*kk)%mod;
     for (int i=1;i<=tot;i++)
     if (bo[i])
     {
        b[i]=false;
        ans=(ans+work(n-1,b,m+u-1,tot))%mod;
        b[i]=true;
     }
     for (int i=1;i<=tot;i++) {b[i]=(b[i]^bo[i]);}
     
     return ans;
}

int main()
{
    for (int i=1;i<9;i++)
    {
        mat[i][0]=1;
        long long u=i+1;
        for (int j=1;j<=50;j++) { mat[i][j]=(mat[i][j-1]*u)%mod; }
    }
    
    while (true)
    {
          int n;
          scanf("%d",&n);
          for (int i=1;i<=n;i++)
          {
              b[i]=false;
              long long k;scanf("%lld",&k);
              long long two=2;
              for (int j=0;j<=50;j++)
              {
                  long long one=k%two;
                  k=k/two;
                  if (one!=0)
                  {
                      a[i][j]=true;
                  } else {a[i][j]=false;}
              }
          }
          printf("%lld\n",work(49,b,0,n));
    }
    
    return 0;
}

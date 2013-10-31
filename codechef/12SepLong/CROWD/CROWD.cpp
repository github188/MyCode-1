#include<stdio.h>
//#include<iostream>
//using namespace std;
long long f[7][7],g[7][7],tmp[7][7];
long long mod=1000000007;

void work(long long o)
{
    int i,j,k;
    if (o==1)
    {
        for (i=3;i<7;i++)
          for (j=3;j<7;j++) g[i][j]=f[i][j];
        return;
    }
    work(o>>1);
    for (i=3;i<7;i++)
     for (j=3;j<7;j++){tmp[i][j]=0;
      for (k=3;k<7;k++)
      {tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j]);if (tmp[i][j]>=mod) tmp[i][j]%=mod;}}
    for (i=3;i<7;i++)
     for (j=3;j<7;j++) g[i][j]=tmp[i][j];
    if (o&1)
    {
        int i,j,k;
    for (i=3;i<7;i++)
     for (j=3;j<7;j++) {tmp[i][j]=0;
      for (k=3;k<7;k++) {tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j]);if (tmp[i][j]>=mod) tmp[i][j]%=mod;}}
    for (i=3;i<7;i++)
     for (j=3;j<7;j++) g[i][j]=tmp[i][j];
    }
}

int main()
{
    //freopen("1.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    //tt=10000;
    f[3][3]=f[4][3]=f[5][3]=f[3][4]=f[4][5]=f[5][6]=1;
    f[6][6]=2;
    //long long uu=100000;
    //uu=uu*uu*uu;
    while (tt>0)
    {
        long long n,ans;
        int k;
        tt--;
        scanf("%I64d",&n);
        //cin>>n;
        //n=uu;
        if (n<3) {printf("0\n");continue;}
        if (n==3) {printf("1\n");continue;}
        n--;n--;n--;
        work(n);
        //long long
        ans=g[5][6]+g[6][6]+g[4][6]+g[4][6]+g[3][6]+g[3][6]+g[3][6]+g[3][6];
        ans%=mod;
        //int
        k=ans;
        printf("%d\n",k);
    }
    return 0;
}

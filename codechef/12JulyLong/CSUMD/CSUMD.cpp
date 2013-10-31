#include<stdio.h>
#include<iostream>
using namespace std;
long long mod=1000000007;
long long a[2][2],b[2][2];
int t,n;

void mul(long long a[][2],long long b[][2])
{
    long long tmp[2][2];
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) tmp[i][j]=0;
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
       for (int k=0;k<2;k++) tmp[i][j]+=a[i][k]*b[k][j];
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++) a[i][j]=tmp[i][j]%mod;
}

void work(int n)
{
    if (n==1)
    {
        a[0][0]=b[0][0];
        a[0][1]=b[0][1];
        a[1][0]=b[1][0];
        a[1][1]=b[1][1];
        return;
    }
    work(n/2);
    mul(a,a);
    if (n&1) mul(a,b);
}

int main()
{
    b[0][0]=0;b[0][1]=b[1][1]=2;b[1][0]=1;
    scanf("%d",&t);

    while (t--)
    {
        scanf("%d",&n);
        if (n==1) {printf("1\n");} else
        if (n==2) {printf("3\n");} else
        {
            n-=2;
            work(n);
            long long ans=a[0][1]+a[1][1]+a[1][1]+a[1][1];
            ans%=mod;
            cout<<ans<<endl;
        }
    }

    return 0;
}

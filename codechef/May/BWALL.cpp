#include<stdio.h>
long long a[3][3],Mat[3][3];
long long mod=1000000007;

void MaPower(int n)
{
     if (n>1) {MaPower(n/2);} else {return;}
     long long Mat1[3][3];
     for (int i=0;i<3;i++)
      for (int j=0;j<3;j++)
      {
          long long m=0;
          for (int k=0;k<3;k++) m+=Mat[i][k]*Mat[k][j];
          Mat1[i][j]=m%mod;
      }
     
      for (int i=0;i<3;i++)
      for (int j=0;j<3;j++) Mat[i][j]=Mat1[i][j]; 
     if ((n&1)==1)
     {
      for (int i=0;i<3;i++)
      for (int j=0;j<3;j++)
      {
          long long m=0;
          for (int k=0;k<3;k++) m+=Mat[i][k]*a[k][j];
          Mat1[i][j]=m%mod;
      }      
      for (int i=0;i<3;i++)
      for (int j=0;j<3;j++) Mat[i][j]=Mat1[i][j];
     }
}

int ans(int n)
{
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) {Mat[i][j]=a[i][j];}
    MaPower(n);
    long long b,c,d,e;
    d=5;b=1;c=1;
    e=b*Mat[0][2]+c*Mat[1][2]+d*Mat[2][2];
    e=e%mod;
    int ans1=e;
    return ans1;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
          tt--;
          int n;
          scanf("%d",&n);
          a[0][0]=0;a[0][1]=0;a[0][2]=2;
          a[1][0]=1;a[1][1]=0;a[1][2]=4;
          a[2][0]=0;a[2][1]=1;a[2][2]=1;
          
          if (n==1) {printf("1\n");} else
          if (n==2) {printf("5\n");} else
          {printf("%d\n",ans(n-2));}
    }
    
    return 0;
}

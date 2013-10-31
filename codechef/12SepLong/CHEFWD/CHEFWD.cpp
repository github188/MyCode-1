#include<stdio.h>
long long f[5][5],g[5][5],tmp[5][5],v[5],s[5];
long long mod=1000000007,one=1;

void work(long long o)
{
    if (o==0)
    {
        for (int i=0;i<4;i++)
          for (int j=0;j<4;j++) g[i][j]=0;
        for (int i=0;i<4;i++) g[i][i]=1;
        return;
    }
    if (o==one)
    {
        for (int i=0;i<4;i++)
          for (int j=0;j<4;j++) g[i][j]=f[i][j];
        return;
    }
    if (o==2)
    {
        g[0][0]=2;g[0][1]=1;g[0][2]=1;g[0][3]=3;
        g[1][0]=1;g[1][1]=1;g[1][2]=1;g[1][3]=2;
        g[2][0]=0;g[2][1]=0;g[2][2]=1;g[2][3]=1;
        g[3][0]=0;g[3][1]=0;g[3][2]=1;g[3][3]=2;
        return;
    }
    if (o==3)
    {
        g[0][0]=3;g[0][1]=2;g[0][2]=3;g[0][3]=7;
        g[1][0]=2;g[1][1]=1;g[1][2]=2;g[1][3]=5;
        g[2][0]=0;g[2][1]=0;g[2][2]=1;g[2][3]=2;
        g[3][0]=0;g[3][1]=0;g[3][2]=2;g[3][3]=3;
        return;
    }

    work(o>>1);
    for (int i=0;i<2;i++)
      for (int j=2;j<4;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<4;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<2;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
    for (int i=2;i<4;i++)
      for (int j=2;j<4;j++)
      {
          tmp[i][j]=0;
          for (int k=2;k<4;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++) g[i][j]=tmp[i][j];
    if (o&one)
    {
    for (int i=0;i<2;i++)
      for (int j=2;j<4;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<4;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
      {
          tmp[i][j]=0;
          for (int k=0;k<2;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
    for (int i=2;i<4;i++)
      for (int j=2;j<4;j++)
      {
          tmp[i][j]=0;
          for (int k=2;k<4;k++)
          {
              tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j]);
          }
        if (tmp[i][j]>=mod) tmp[i][j]%=mod;
      }
      for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) g[i][j]=tmp[i][j];
    }
}
int main()
{
    f[0][0]=f[0][1]=f[0][3]=f[1][0]=f[1][3]=f[2][3]=f[3][2]=f[3][3]=1;
    v[0]=3;v[1]=2;
    v[2]=1;v[3]=4;
    int t;
    for (int i=0;i<4;i++)
    for (int j=0;j<4;j++) tmp[i][j]=0;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        long long n;
        scanf("%lld",&n);
        if (n==1) {printf("0\n");}
        else if (n==2) {printf("5\n");}
        else if (n==3) {printf("18\n");}
        else
        {
            long long four=3;
            work(n-four);
            long long ans2=0,ans1=0;
            for (int i=0;i<4;i++)
            {
                s[i]=0;
                for (int j=0;j<4;j++)
                {s[i]=(s[i]+v[j]*g[j][i]);
                if (s[i]>=mod) s[i]%=mod;}
            }
            ans2=(s[1]+s[2]+s[3]);
            ans1=(s[3]+ans2);
            ans2=(ans1+ans2);
            if (ans2>=mod) ans2%=mod;
            printf("%lld\n",ans2);
        }
    }
    return 0;
}

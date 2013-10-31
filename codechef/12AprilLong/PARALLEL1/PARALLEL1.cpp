#include<stdio.h>
int a[1001][30],b[1001][30],tot[30],step[30][1100][2],a_t[30],a_s[30][1100][2];

void work(int n,int m,int s,int t)
{
    if (n==1) return;
    if (n==2)
    {
        tot[t]++;
        step[t][tot[t]][0]=s;
        step[t][tot[t]][1]=s+s;
        return;
    }
    int u=n/b[n][m];
    for (int i=1;i<=u;i++)
    {
        int k=i*b[n][m]*s;
        for (int j=1;j<b[n][m];j++)
        {
            int l=k-b[n][m]*s+j*s;
            tot[t]++;
            step[t][tot[t]][0]=l;
            step[t][tot[t]][1]=k;
        }
    }
    work(u,m-b[n][m],s*b[n][m],t+1);
    for (int i=1;i<b[n][m]-1;i++)
    {
        tot[t+i]++;
        step[t+i][tot[t+i]][0]=s*i;
        step[t+i][tot[t+i]][1]=s*i+s;
    }
    for (int i=1;i<=u;i++)
    {
        int k=t+m-1-(b[n][m]-2);
        for (int j=i*s*b[n][m];j+s<(i+1)*s*b[n][m];j+=s)
        if (j+s<=1000)
        {
            tot[k]++;
            step[k][tot[k]][0]=j;
            step[k][tot[k]][1]=j+s;
            k++;
        }
    }
}

int main()
{
    for (int i=0;i<=1000;i++) for (int j=0;j<=20;j++) a[i][j]=-1;
    a[1][0]=0;
    for (int i=0;i<=20;i++) a[1][i]=0;
    for (int i=1;i<=20;i++) a[2][i]=1;
    for (int i=3;i<=1000;i++)
     for (int j=1;j<=20;j++)
      if (j>=i) {a[i][j]=a[i][j-1];b[i][j]=b[i][j-1];} else
      for (int k=1;k<=j;k++)
      {
          int u=i/k,v=i%k;
          if (a[u][j-k]==-1) continue;
          int sum=0;
          sum=i-u-v;
          sum+=i-u-1;
          if (k>=2) sum+=k-2;
          sum+=a[u][j-k];
          if ((a[i][j]==-1)||(a[i][j>sum])) {a[i][j]=sum;b[i][j]=k;}
      }

    work(1000,20,1,1);
    /*
    int ans=0;
    for (int i=1;i<=20;i++) ans+=tot[i];
    printf("%d %d",a[1000][20],ans);*/

    int n;
    scanf("%d",&n);
    for (int i=1;i<=20;i++)
    {
        for (int j=1;j<=tot[i];j++)
        if ((step[i][j][0]<=n)&&(step[i][j][1]<=n))
        {
            a_s[i][a_t[i]][0]=step[i][j][0];
            a_s[i][a_t[i]][1]=step[i][j][1];
            a_t[i]++;
        }
    }
    printf("20\n");
    for (int i=1;i<=20;i++)
    {
        printf("%d",a_t[i]);
        for (int j=0;j<a_t[i];j++) printf(" %d+%d=%d",a_s[i][j][0],a_s[i][j][1],a_s[i][j][1]);
        printf("\n");
    }
    return 0;
}

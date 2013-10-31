#include<stdio.h>
#include<iostream>
using namespace std;

long long a[80][80],b[80][80],c[80][80],l[80][80][80],r[80][80][80];
long long n,m;
long long ans;
long long minimum;
int u;
long long max(long long o,long long p)
{
     if (o>p) {return o;}return p;
}

long long min(long long o,long long p)
{
     if (o<p) {return o;}return p;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
          if (n==0) {break;}
          for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {int u;scanf("%d",&u);a[i][j]=u;}
          for (int i=1;i<=n;i++) { for (int j=1;j<=m;j++) {b[i][j]=a[i][j]+b[i][j-1];c[i][j]=a[i][j]+c[i-1][j];} }
          ans = 100000;
          ans = -(ans*ans);
          minimum = ans;
          for (int i=1;i<=n-2;i++)
           for (int j=i+2;j<=n;j++)
           {
               l[i][j][1]=c[j][1]-c[i-1][1];
               for (int k=2;k<=m;k++) {l[i][j][k]=max(0,l[i][j][k-1])+c[j][k]-c[i-1][k];}
               r[i][j][m]=c[j][m]-c[i-1][m];
               for (int k=m-1;k>0;k--) {r[i][j][k]=max(0,r[i][j][k+1])+c[j][k]-c[i-1][k];}
           }
           
         for (int i=1;i<=m-2;i++)
          for (int j=i+2;j<=m;j++)
           for (int k=1;k<=n-2;k++)
           {
               if ((i==3)&&(j==5))
               {
                  int u;
                  u=1;
               }
               
               long long s = b[k][j-1]-b[k][i]+b[k+2][j-1]-b[k+2][i]+b[k+1][j-1]-b[k+1][i];
               long long sum = b[k+1][j-1]-b[k+1][i];
               ans = max(ans,s-sum+l[k][k+2][i]+r[k][k+2][j]);
               long long mini=sum;
               for (int ll=k+3;ll<=n;ll++)
               {
                   s+=b[ll][j-1]-b[ll][i];
                   sum = min(0,sum)+b[ll-1][j-1]-b[ll-1][i];
                   mini = min(mini,sum);
                   ans = max(ans,s-mini+l[k][ll][i]+r[k][ll][j]);
               }
           }
          
          cout<<ans<<endl;
    }
    
    return 0;
}

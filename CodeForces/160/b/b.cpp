#include<stdio.h>
using namespace std;
double f[100][100];
int n,p;
int a[100];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    f[0][0]=1;
    scanf("%d",&p);
    for (int i=0;i<n;i++)
     for (int j=p-a[i];j>=0;j--)
      for (int k=i;k>=0;k--)
       if (f[j][k]>0) f[j+a[i]][k+1]+=f[j][k]*(double)(k+1)/(double)(n-k);
    double ans=0,nn=n;
    /*
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
     {
         double sum=0;
         for (int k=0;k<=p-a[i];k++) if (f[k][j]>1e-10) sum+=f[k][j];
         for (int k=n;k>=n-j;k--) {sum=sum*(double)(n-k+1)/(double)k;}
         ans+=sum;
     }*/
     for (int i=1;i<=n;i++) for (int j=0;j<=p;j++) ans+=f[j][i];
    printf("%.5f\n",ans);
    return 0;
}

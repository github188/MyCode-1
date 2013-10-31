#include<stdio.h>
#include<string.h>
int n,m;
bool a[1000][1000];
int b[1000][1000],c[1001];
int mi,ma;

bool check(int o)
{
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) a[i][j]=false;
    for (int j=0;j<m;j++)
    {
        c[0]=0;
        for (int i=0;i<n;i++) if (b[i][j]>=o) c[++c[0]]=i;
        for (int k=1;k<c[0];k++)
         for (int l=k+1;l<=c[0];l++)
          {
              int x=c[k],y=c[l];
              if (a[x][y]) return true;
              a[x][y]=true;
          }
    }
    return false;
}

int main()
{
    mi=1e9;ma=0;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++)
    {
        scanf("%d",&b[i][j]);
        mi=mi<b[i][j]?mi:b[i][j];
        ma=ma>b[i][j]?ma:b[i][j];
    }
    while (mi<ma)
    {
        int mid=(mi+ma)/2+1;
        if (check(mid)) mi=mid; else ma=mid-1;
    }
    printf("%d\n",ma);
    return 0;
}

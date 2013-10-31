#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct dd
{
    int x,y;
} d[200];
int a[20][200],b[20][200],c[20][200];
int n,m,k;

bool cmp(dd a,dd b)
{
    if (a.x>b.x) return true;return false;
}

int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<m;j++) cin>>a[i][j]>>b[i][j]>>c[i][j];
    }
    int ans=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if (i!=j)
      {
          int sum=0,tot=0;
          for (int l=0;l<m;l++)
          if (b[j][l]>a[i][l])
          {
              d[tot].x=b[j][l]-a[i][l];
              d[tot].y=c[i][l];
              tot++;
          }
          sort(d,d+tot,cmp);
          int mem=0;
          for (int l=0;l<tot;l++)
          if (mem+d[l].y<k)
          {
              mem+=d[l].y;
              sum+=d[l].x*d[l].y;
          } else {sum+=d[l].x*(k-mem);break;}
          if (sum>ans) ans=sum;
      }
    cout<<ans<<endl;
    return 0;
}

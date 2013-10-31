#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> c;
int b[4000];
int n;
int a[4000][4000],d[4000][4000];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    int s=c.size();
    for (int i=0;i<n;i++)
      for (int j=0;j<s;j++)
       if (b[i]==c[j]) {b[i]=j;break;}
    int ans=0;
    for (int i=0;i<n;i++)
      for (int j=0;j<s;j++) a[i][j]=0,d[i][j]=-1;
    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+1;j<n;j++) if (b[j]!=b[i]) if ((d[b[i]][b[j]]>j)||(d[b[i]][b[j]]==-1)) a[b[i]][b[j]]+=2,d[b[i]][b[j]]=i;
        for (int j=0;j<s;j++) if (a[b[i]][j]==0) a[b[i]][j]=1,d[b[i]][j]=i;
    }
    for (int i=0;i<s;i++) for (int j=0;j<s;j++) if (a[i][j]>ans) ans=a[i][j];
    for (int i=0;i<n;i++)
    {
        int tmp=1;
        for (int j=i+1;j<n;j++) if (b[j]==b[i]) tmp++;
        if (tmp>ans) ans=tmp;
    }
    printf("%d\n",ans);
    return 0;
}

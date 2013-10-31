#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct rect1
{
    int x0,y0,x1,y1;
    char col;
};
vector<rect1> ans;
char s[50][50];
int n;

int main()
{
    scanf("%d",&n);gets(s[0]);
    for (int i=0;i<n;i++) gets(s[i]);
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if (s[i][j]=='B')
      {
          rect1 newrect;
          newrect.col='B';
          newrect.x0=i;
          newrect.y0=j;
          int k=j;
          while ((k+1<n)&&(s[i][k+1]=='B')) k++;
          if (k==j)
          {
              k=i;
              while ((k+1<n)&&(s[k+1][j]=='B')) k++;
              newrect.x1=k;
              newrect.y1=j;
          } else
          {
              newrect.x1=i;
              newrect.y1=k;
          }
          for (int k=newrect.x0;k<=newrect.x1;k++)
           for (int l=newrect.y0;l<=newrect.y1;l++) s[k][l]='W';
          ans.push_back(newrect);
      }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) printf("%d %d %d %d %c\n",ans[i].x0,ans[i].y0,ans[i].x1,ans[i].y1,ans[i].col);
    return 0;
}

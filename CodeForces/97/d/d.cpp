#include<stdio.h>
#include<set>
#include<string.h>
using namespace std;

struct pt
{
    int x,y;
};

char c[1000][1000];
int n,m,tot;
pt a[1000000],d[8];
bool use[1000][1000];

int max(int o,int p)
{
    if (o>p) return o;return p;
}

void find(int x,int y)
{
    pt tmp;tmp.x=x;tmp.y=y;
    a[tot]=tmp;tot++;use[x][y]=true;
    for (int i=0;i<4;i++)
    if ((x+d[i].x>=0)&&(x+d[i].x<n)&&(y+d[i].y>=0)&&(y+d[i].y<m)&&(!use[x+d[i].x][y+d[i].y])&&(c[x+d[i].x][y+d[i].y]=='0')) find(x+d[i].x,y+d[i].y);
}

set<int> set1;

int absq(int o)
{
    if (o<0) o=-o;return o;
}

int check()
{
    set1.clear();
    int sx,sy;
    for (int i=0;i<tot;i++)
    {
        int x=a[i].x,y=a[i].y;
        for (int j=0;j<8;j++)
        if ((x+d[j].x<0)||(y+d[j].y<0)||(x+d[j].x>=n)||(y+d[j].y>=m))
        {
            return 0;
        } else
        if (c[x+d[j].x][y+d[j].y]=='1')
        {
            pt tmp;
            tmp.x=x+d[j].x;tmp.y=y+d[j].y;
            set1.insert(tmp.x*1000+tmp.y);
            sx=tmp.x;sy=tmp.y;
        }
    }
    int ans=1;int ssx=sx,ssy=sy;
    while (true)
    {
        set1.erase(sx*1000+sy);
        int tot=0;
        int tx,ty;
        for (int i=0;i<4;i++)
        {
            pt tmp;
            tmp.x=sx+d[i].x;
            tmp.y=sy+d[i].y;
            set<int>::iterator it=set1.find(tmp.x*1000+tmp.y);
            if (it==set1.end())
            {

            } else
            {
                tot++;
                tx=tmp.x;
                ty=tmp.y;
            }
        }

            if (ans==1)
            {
                if (tot>2) return 0;
            } else {
            if (tot>1) return 0;}
            if (tot==0)
            {
                if (set1.size()!=0) return 0;
                if (absq(ssx-sx+ssy-sy)==1) return ans;
            }
            ans++;
            sx=tx;sy=ty;
    }
}

int main()
{
    d[0].x=0;d[0].y=1;
    d[1].x=0;d[1].y=-1;
    d[2].x=1;d[2].y=0;
    d[3].x=-1;d[3].y=0;
    d[4].x=1;d[4].y=1;
    d[5].x=1;d[5].y=-1;
    d[6].x=-1;d[6].y=1;
    d[7].x=-1;d[7].y=-1;
    memset(use,false,sizeof(use));
    scanf("%d%d",&n,&m);gets(c[0]);
    int ans=0;
    for (int i=0;i<n;i++) gets(c[i]);
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
      if ((c[i][j]=='0')&&(!use[i][j]))
      {
          tot=0;find(i,j);
          ans=max(check(),ans);
      }
    printf("%d\n",ans);
    return 0;
}

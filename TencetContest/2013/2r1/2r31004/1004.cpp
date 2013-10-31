#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char map[100][100];
int n,m;
bool used[100][100];
struct pointt
{
    int x,y,step;
} a[20000];
int tot=0;
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};

inline int dis(int o,int p)
{
    return abs(a[o].x-a[p].x)+abs(a[o].y-a[p].y);
}

inline void insert(int x,int y)
{
    a[tot].x=x;a[tot++].y=y;
}

bool ok(int o)
{
    memset(used,false,sizeof(used));
    tot=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (map[i][j]=='F')
      {
          used[i][j]=true;
          a[tot].step=1;
          a[tot].x=i;
          a[tot++].y=j;
      }
    int h=0;
    while (h<tot)
    {
        if (a[h].step==o) {h++;continue;}
        for (int k=0;k<4;k++)
        if ((dx[k]+a[h].x>=0)&&(dx[k]+a[h].x<n)&&(dy[k]+a[h].y>=0)&&(dy[k]+a[h].y<m)
          &&(!used[dx[k]+a[h].x][dy[k]+a[h].y]))
          {
              pointt tmpt=a[h];
              tmpt.step++;
              tmpt.x+=dx[k];
              tmpt.y+=dy[k];
              a[tot++]=tmpt;
              used[tmpt.x][tmpt.y]=true;
          }
        h++;
    }
    tot=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        if (!used[i][j])
        {
            insert(i,j);
            break;
        }
        for (int j=m-1;j>=0;j--)
        if (!used[i][j])
        {
            insert(i,j);
            break;
        }
    }
    for (int j=0;j<m;j++)
    {
        for (int i=0;i<n;i++)
        if (!used[i][j])
        {
            insert(i,j);
            break;
        }
        for (int i=n-1;i>=0;i--)
        if (!used[i][j])
        {
            insert(i,j);
            break;
        }
    }
    for (int i=0;i<tot;i++)
     for (int j=i+1;j<tot;j++)
     if (dis(i,j)>=o)
      for (int k=j+1;k<tot;k++)
       if ((dis(i,k)>=o)&&(dis(k,j)>=o)) return true;
    return false;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&m);gets(map[0]);
        for (int i=0;i<n;i++) gets(map[i]);
        int l=1,r=n+m+1;
        while (l<r)
        {
            int mid=(l+r)/2+1;
            if (ok(mid)) l=mid; else r=mid-1;
        }
        printf("Case %d: %d\n",t,l);
    }
    return 0;
}

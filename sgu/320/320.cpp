#include<stdio.h>
#include<string.h>

struct vex
{int x,y,z;};

char c[500][500];
bool use_sq[500][500],isLarge[250001],use_v[501][501],use_e[501][501][2],isFill_e[501][501][2];
int n,m,k,num;
int dir[4][2],Num_sq[500][500],tot[2];
vex que[2][250000];

void dfs_sq(int x,int y,int no,int &k)
{
    use_sq[x][y]=true;k++;Num_sq[x][y]=no;
    for (int i=0;i<4;i++)
    {
        int x1=dir[i][0],y1=dir[i][1];
        if ((x+x1>=0)&&(x+x1<n)&&(y+y1>=0)&&(y+y1<m)&&(!use_sq[x+x1][y+y1])&&(c[x][y]==c[x+x1][y+y1])){dfs_sq(x+x1,y+y1,no,k);}
    }
}

bool check(int x,int y,int d,int k)
{
    if (d==0)
    {
        if (use_e[x][y][0]) return false;use_e[x][y][0]=true;
        if ((x-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y]==Num_sq[x-1][y])) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y]==Num_sq[x-1][y-1])&&(k!=2)) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x-1][y]])&&(Num_sq[x][y-1]==Num_sq[x-1][y])&&(k!=3)) return false;
        isFill_e[x][y][0]=true;return true;
    }
    if (d==1)
    {
        if (use_e[x][y-1][0]) return false;use_e[x][y-1][0]=true;
        if ((x-1>=0)&&(x<n)&&(isLarge[Num_sq[x][y-1]])&&(Num_sq[x][y-1]==Num_sq[x-1][y-1])) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y]==Num_sq[x-1][y-1])&&(k!=3)) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x-1][y]])&&(Num_sq[x][y-1]==Num_sq[x-1][y])&&(k!=2)) return false;
        isFill_e[x][y-1][0]=true;return true;
    }
    if (d==2)
    {
        if (use_e[x][y][1]) return false;use_e[x][y][1]=true;
        if ((y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y-1]==Num_sq[x][y])) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y]==Num_sq[x-1][y-1])&&(k!=0)) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x-1][y]])&&(Num_sq[x][y-1]==Num_sq[x-1][y])&&(k!=1)) return false;
        isFill_e[x][y][1]=true;return true;
    }
    if (d==3)
    {
        if (use_e[x-1][y][1]) return false;use_e[x-1][y][1]=true;
        if ((y-1>=0)&&(y<m)&&(isLarge[Num_sq[x-1][y-1]])&&(Num_sq[x-1][y]==Num_sq[x-1][y-1])) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x][y]])&&(Num_sq[x][y]==Num_sq[x-1][y-1])&&(k!=1)) return false;
        if ((x-1>=0)&&(y-1>=0)&&(x<n)&&(y<m)&&(isLarge[Num_sq[x-1][y]])&&(Num_sq[x][y-1]==Num_sq[x-1][y])&&(k!=0)) return false;
        isFill_e[x-1][y][1]=true;return true;
    }
}

bool check1(int x,int y)
{
    if (isLarge[Num_sq[x][y]]) return true;
    bool ans=true;ans^=(isFill_e[x][y][0]|isFill_e[x][y][1]|isFill_e[x+1][y][0]|isFill_e[x][y+1][1]);
    return ans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);gets(c[0]);
    for (int i=0;i<n;i++) gets(c[i]);
    dir[0][0]=0;dir[0][1]=1;dir[1][0]=0;dir[1][1]=-1;dir[2][0]=1;dir[2][1]=0;dir[3][0]=-1;dir[3][1]=0;

    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
      if ((!use_sq[i][j])){num++;int kk=0;dfs_sq(i,j,num,kk); if (kk>=k) isLarge[num]=true;}

    tot[0]=1;tot[1]=0;que[0][0].x=0;que[0][0].y=0;que[0][0].z=15;
    int mark=0;
    while (tot[mark]!=0)
    {
        int next=(mark^1);tot[next]=0;
        for (int i=0;i<tot[mark];i++)
        {
            int x=que[mark][i].x,y=que[mark][i].y;
            for (int j=0;j<4;j++)
            {
                int x1=x+dir[j][0],y1=y+dir[j][1];
                if ((x1>=0)&&(x1<=n)&&(y1>=0)&&(y1<=m)&&(check(x,y,j,que[mark][i].z)))
                  {
                      if (!use_v[x1][y1])
                      {
                          use_v[x1][y1]=true;
                          que[next][tot[next]].x=x1;
                          que[next][tot[next]].y=y1;
                          que[next][tot[next]].z=j;
                          tot[next]++;
                      }
                  }
            }
        }mark=next;
    }

    int ans=0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (check1(i,j)) ans++;printf("%d\n",ans);

    return 0;
}

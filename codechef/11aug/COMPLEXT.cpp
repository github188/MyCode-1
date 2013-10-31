#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

struct edge
{
       int x1,y1,x2,y2,u,v;
};

vector<edge> ans,cur;
int all[30][30][30][30][2];
int n,an;
bool use[100][100];
int a[100][100][4];

int work(int o,int p)
{
    int u,v;u=v=0;
    memset(use,false,sizeof(use));
    memset(a,0,sizeof(a));
    int tot=0;
    while (tot<n*n)
    {
      int x,y;
      if (tot==0) {x=y=1;} else
      {
        int sum=-300;
        for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
          if ((!use[i][j])&&(a[i][j][2]!=0)&&(a[i][j][0]*o+a[i][j][1]*p>sum))
          {
            sum=a[i][j][0]*o+a[i][j][1]*p;
            x=i;y=j;
          }
      }
      tot++;
      use[x][y]=true;
      if (tot!=1)
      {
        edge m;
        m.x1=x;
        m.y1=y;
        m.x2=a[x][y][2];
        m.y2=a[x][y][3];
        cur.push_back(m);
      }
      u+=a[x][y][0];
      v+=a[x][y][1];
      
      if (x>1)
      {
         if ((a[x-1][y][2]==0)||(a[x-1][y][0]*o+a[x-1][y][1]*p<all[x-1][y][x][y][0]*o+all[x-1][y][x][y][1]*p))
         {
            a[x-1][y][0]=all[x-1][y][x][y][0];
            a[x-1][y][1]=all[x-1][y][x][y][1];
            a[x-1][y][2]=x;
            a[x-1][y][3]=y;
         }
      }
      
      if (y>1)
      {
         if ((a[x][y-1][2]==0)||(a[x][y-1][0]*o+a[x][y-1][1]*p<all[x][y-1][x][y][0]*o+all[x][y-1][x][y][1]*p))
         {
            a[x][y-1][0]=all[x][y-1][x][y][0];
            a[x][y-1][1]=all[x][y-1][x][y][1];
            a[x][y-1][2]=x;
            a[x][y-1][3]=y;
         }
      }
      
      if (x<n)
      {
         if ((a[x+1][y][2]==0)||(a[x+1][y][0]*o+a[x+1][y][1]*p<all[x+1][y][x][y][0]*o+all[x+1][y][x][y][1]*p))
         {
            a[x+1][y][0]=all[x+1][y][x][y][0];
            a[x+1][y][1]=all[x+1][y][x][y][1];
            a[x+1][y][2]=x;
            a[x+1][y][3]=y;
         }
      }
      
      if (y<n)
      {         
         if ((a[x][y+1][2]==0)||(a[x][y+1][0]*o+a[x][y+1][1]*p<all[x][y+1][x][y][0]*o+all[x][y+1][x][y][1]*p))
         {
            a[x][y+1][0]=all[x][y+1][x][y][0];
            a[x][y+1][1]=all[x][y+1][x][y][1];
            a[x][y+1][2]=x;
            a[x][y+1][3]=y;
         }
      }
    }
    
    return u*u+v*v;
}

int work1(int o,int p)
{
    int u,v;u=v=0;
    memset(use,false,sizeof(use));
    memset(a,0,sizeof(a));
    int tot=0;
    while (tot<n*n)
    {
      int x,y;
      if (tot==0) {x=y=1;} else
      {
        int sum=-300;
        for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
          if ((!use[i][j])&&(a[i][j][2]!=0)&&(a[i][j][0]*o+a[i][j][1]*p>sum))
          {
            sum=a[i][j][0]*a[i][j][0]*o+a[i][j][1]*a[i][j][1]*p;
            x=i;y=j;
          }
      }
      tot++;
      use[x][y]=true;
      if (tot!=1)
      {
        edge m;
        m.x1=x;
        m.y1=y;
        m.x2=a[x][y][2];
        m.y2=a[x][y][3];
        cur.push_back(m);
      }
      u+=a[x][y][0];
      v+=a[x][y][1];
      
      if (x>1)
      {
         if ((a[x-1][y][2]==0)||(a[x-1][y][0]*o+a[x-1][y][1]*p<all[x-1][y][x][y][0]*o+all[x-1][y][x][y][1]*p))
         {
            a[x-1][y][0]=all[x-1][y][x][y][0];
            a[x-1][y][1]=all[x-1][y][x][y][1];
            a[x-1][y][2]=x;
            a[x-1][y][3]=y;
         }
      }
      
      if (y>1)
      {
         if ((a[x][y-1][2]==0)||(a[x][y-1][0]*o+a[x][y-1][1]*p<all[x][y-1][x][y][0]*o+all[x][y-1][x][y][1]*p))
         {
            a[x][y-1][0]=all[x][y-1][x][y][0];
            a[x][y-1][1]=all[x][y-1][x][y][1];
            a[x][y-1][2]=x;
            a[x][y-1][3]=y;
         }
      }
      
      if (x<n)
      {
         if ((a[x+1][y][2]==0)||(a[x+1][y][0]*o+a[x+1][y][1]*p<all[x+1][y][x][y][0]*o+all[x+1][y][x][y][1]*p))
         {
            a[x+1][y][0]=all[x+1][y][x][y][0];
            a[x+1][y][1]=all[x+1][y][x][y][1];
            a[x+1][y][2]=x;
            a[x+1][y][3]=y;
         }
      }
      
      if (y<n)
      {         
         if ((a[x][y+1][2]==0)||(a[x][y+1][0]*o+a[x][y+1][1]*p<all[x][y+1][x][y][0]*o+all[x][y+1][x][y][1]*p))
         {
            a[x][y+1][0]=all[x][y+1][x][y][0];
            a[x][y+1][1]=all[x][y+1][x][y][1];
            a[x][y+1][2]=x;
            a[x][y+1][3]=y;
         }
      }
    }
    
    return u*u+v*v;
}

int main()
{
    scanf("%d",&n);
    an=0;
    for (int i=1;i<=n;i++)
     for (int j=1;j<n;j++)
     {
         scanf("%d%d",&all[i][j][i][j+1][0],&all[i][j][i][j+1][1]);
         all[i][j+1][i][j][0]=all[i][j][i][j+1][0];
         all[i][j+1][i][j][1]=all[i][j][i][j+1][1];
     }
    for (int j=1;j<=n;j++)
     for (int i=1;i<n;i++)
     {
         scanf("%d%d",&all[i][j][i+1][j][0],&all[i][j][i+1][j][1]);
         all[i+1][j][i][j][0]=all[i][j][i+1][j][0];
         all[i+1][j][i][j][1]=all[i][j][i+1][j][1];
     }
     
    for (int i=-1;i<=1;i++)
     for (int j=-1;j<=1;j++)
      if (i*j!=0)
      {
         cur.clear();
         int sum=work(i,j);
         if (sum>an)
         {
           an=sum;
           ans=cur;
           int u=ans.size();
           int v=1;
         }
         sum=work1(i,j);
         if (sum>an)
         {
           an=sum;
           ans=cur;
           int u=ans.size();
           int v=1;
         }
      }
    
    for (vector<edge>::iterator i=ans.begin();i!=ans.end();i++)
    {
        printf("%d %d %d %d\n",i->x1,i->y1,i->x2,i->y2);
    }
    
    return 0;
}

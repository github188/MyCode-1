#include<stdio.h>
#include<string.h>
#include<map>
#include<stack>
using namespace std;
struct str
{
       int x,y,z;
};

map<int,int> a[25],b[25];
stack<str> s[2],t[2];
int n,m,tt,sx,sy,fx,fy,sum;
int bin[30],f[10][10],g[10][10][2],dx[8],dy[8],place[50][2];

int work(int o,int p,int x,int y,int q)
{
    o=(o^1);
    for (int i=0;i<8;i++)
    if ((x+dx[i]>=0)&&(y+dy[i]>=0)
       &&(x+dx[i]<n)&&(y+dy[i]<m)
       &&(f[x+dx[i]][y+dy[i]]>0))
       {
          int xx,yy;
          xx=x+dx[i];yy=y+dy[i];
          int u=g[xx][yy][1];
          while (u>=g[xx][yy][0])
          {
                if ((p&(1<<u))==0) {break;}
                u--;
          }
          if (u>=g[xx][yy][0])
          {
               map<int,int>::iterator it=a[u].find(p|(1<<u));
               if (it!=a[u].end())
               {
                  it->second+=q;
               } else
               {
                     str tmp;
                     tmp.x=u;
                     tmp.y=(p|(1<<u));
                     tmp.z=q;
                     a[u].insert(pair<int,int>(tmp.y,q));
                     s[o].push(tmp);
               }
          }
       }
    return 0;
}

int work1(int o,int p,int x,int y,int q)
{
    o=(o^1);
    for (int i=0;i<8;i++)
    if ((x+dx[i]>=0)&&(y+dy[i]>=0)
       &&(x+dx[i]<n)&&(y+dy[i]<m)
       &&(f[x+dx[i]][y+dy[i]]>0))
       {
          int xx,yy;
          xx=x+dx[i];yy=y+dy[i];
          int u=g[xx][yy][0];
          while (u<=g[xx][yy][1])
          {
                if ((p&(1<<u))==0) {break;}
                u++;
          }
          if (u<=g[xx][yy][1])
          {
               map<int,int>::iterator it=b[u].find(p|(1<<u));
               if (it!=b[u].end())
               {
                  it->second+=q;
               } else
               {
                     str tmp;
                     tmp.x=u;
                     tmp.y=(p|(1<<u));
                     tmp.z=q;
                     b[u].insert(pair<int,int>(tmp.y,q));
                     t[o].push(tmp);
               }
          }
       }
    return 0;
}

int main()
{
    dx[0]=1;dy[0]=0;
    dx[1]=-1;dy[1]=0;
    dx[2]=2;dy[2]=0;
    dx[3]=-2;dy[3]=0;
    dx[4]=0;dy[4]=1;
    dx[5]=0;dy[5]=-1;
    dx[6]=0;dy[6]=2;
    dx[7]=0;dy[7]=-2;
    scanf("%d",&tt);
    while (tt>0)
    {
          tt--;
          for (int i=0;i<25;i++) {
          a[i].clear();
          b[i].clear();}
          scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&fx,&fy);
          sx--;sy--;fx--;fy--;
          sum=0;
          for (int i=0;i<n;i++)
           for (int j=0;j<m;j++)
           {
               scanf("%d",&f[i][j]);
               if ((i==fx)&&(j==fy)) {f[i][j]--;}
               if (f[i][j]>0) {
               g[i][j][0]=sum;sum+=f[i][j];
               g[i][j][1]=sum-1;
               for (int k=g[i][j][0];k<=g[i][j][1];k++) {place[k][0]=i;place[k][1]=j;}
               }
           }
           
//           s[0].clear();
           work(1,0,fx,fy,1);
           int k=sum/2;
           int l=0;
           for (int i=2;i<=k;i++)
           {
//               s[l^1].clear();
               int size=s[l].size();
               while (size>0)
               {
                     size--;
                     str tmp=s[l].top();
                     s[l].pop();
                     map<int,int>::iterator it=a[tmp.x].find(tmp.y);
                     work(l,tmp.y,place[tmp.x][0],place[tmp.x][1],it->second);
               }
               l=(l^1);
           }
           
           
           k=sum-k;
           int ll=0;
           //t[0].clear();
           str tmp;
           tmp.x=g[sx][sy][0];
           tmp.y=(1<<tmp.x);
           tmp.z=1;
           b[tmp.x].insert(pair<int,int>(tmp.y,1));
           t[0].push(tmp);
           for (int i=1;i<=k;i++)
           {
               //t[ll^1].clear();
               int size=t[ll].size();
               while (size>0)
               {
                     size--;
                     str tmp=t[ll].top();
                     t[ll].pop();
                     map<int,int>::iterator it=b[tmp.x].find(tmp.y);
                     work1(ll,tmp.y,place[tmp.x][0],place[tmp.x][1],it->second);
               }
               ll=(ll^1);
           }
           
           int all=(1<<sum);all--;
           int ans=0;
           for (;!s[l].empty();)
           {
               str i=s[l].top();
               s[l].pop();
               int x,y,z;
               x=i.x;y=i.y;z=i.z;
               map<int,int>::iterator it0=a[x].find(y);
               z=it0->second;
               map<int,int>::iterator it=b[x].find((all^y)|(1<<x));
               if (it!=b[x].end())
               {
                  ans=ans+z*(it->second);
               }
           }
           while (!t[ll].empty()) {t[ll].pop();}
           
           printf("%d\n",ans);
    }
    
    return 0;
}

#include<stdio.h>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
map<long long,int> hash;
vector<long long> c;
int p1[6],p2[6],d1[6][2],d2[6][2],f[34][34],g[34][34],d[2][34];
int n,m,q;
long long status;
long long one=1,num;

long long next(long long s)
{
    long long ans=0;num=0;
    for (int i=0;i<n;i++) d[0][i]=0;
    for (int i=0;i<m;i++) d[1][i]=0;

    int x,y;x=y=0;
    while (x<n)
    {
        f[x][y]=(s&1);s>>=1;
        g[x][y]=0;
        if (f[x][y]==1){
        d[0][x]++;
        d[1][y]++;}
        y++;
        if (y==m)
        {
            x++;y=0;
        }
    }

    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (f[i][j]==1)
      {
          int type=(d[0][i]+d[1][j]-1);
          if (type>5) type%=6;
          int x=i,y=j;
          int dx=d1[type][0]*p1[type],dy=d1[type][1]*p1[type];
          while ((x+dx>=0)&&(x+dx<n)&&(y+dy>=0)&&(y+dy<m))
          {
              x+=dx;y+=dy;
              g[x][y]^=1;
          }
          x=i,y=j;
          dx=d2[type][0]*p2[type],dy=d2[type][1]*p2[type];
          while ((x+dx>=0)&&(x+dx<n)&&(y+dy>=0)&&(y+dy<m))
          {
              x+=dx;y+=dy;
              g[x][y]^=1;
          }
      }

    int u=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
     {
         f[i][j]^=g[i][j];
         if (f[i][j]>0)
         {
             num++;
             ans|=(one<<u);
         }
         u++;
     }

     return ans;
}

int main()
{
    d1[0][0]=-1;d1[0][1]=0;d2[0][0]=1;d2[0][1]=0;
    d1[1][0]=0;d1[1][1]=-1;d2[1][0]=0;d2[1][1]=1;
    d1[2][0]=-1;d1[2][1]=0;d2[2][0]=0;d2[2][1]=1;
    d1[3][0]=0;d1[3][1]=1;d2[3][0]=1;d2[3][1]=0;
    d1[4][0]=1;d1[4][1]=0;d2[4][0]=0;d2[4][1]=-1;
    d1[5][0]=0;d1[5][1]=-1;d2[5][0]=-1;d2[5][1]=0;

    scanf("%d%d%d",&n,&m,&q);
    int x,y;
    scanf("%d%d",&x,&y);
    for (int i=0;i<6;i++) scanf("%d%d",&p1[i],&p2[i]);
    c.push_back(1);
    status=(one<<((x-1)*m+y-1));
    hash.insert(make_pair(status,0));
    long long u;
    int v=1;
    while (true)
    {
        status=next(status);
        map<long long,int>::iterator it = hash.find(status);
        if (it!=hash.end())
        {
            u=it->second;
            break;
        }
        hash.insert(make_pair(status,v));
        c.push_back(c[v-1]+num);v++;
    }

    long long tmp=c[c.size()-1];
    if (u>0) tmp-=c[u-1];
    while (q--)
    {
        long long T;
        cin>>T;
        if (T<u)
        {
            cout<<c[T]<<endl;
            continue;
        }
        long long len=c.size()-u;
        T-=u;
        long long ans=(T/len)*tmp;
        T%=len;
        T+=u;
        ans+=c[T];
        cout<<ans<<endl;
    }
    return 0;
}

#include<stdio.h>
long long mod=1000000007;
struct node
{
    long long t,v;
} a[51][51];
bool used[51][51];
int n,m,m1,m2;
struct p
{
    int x,y;int t;
} q[1000000];
long long c[100][100];

inline bool update(int x,int y,node s,int x1,int x2,int y1,int y2,int z1,int z2,int p1,int p2)
{
    s.t++;
    s.v=(s.v*c[x1][x2])%mod;
    s.v=(s.v*c[y1][y2])%mod;
    s.v=(s.v*c[z1][z2])%mod;
    s.v=(s.v*c[p1][p2])%mod;
    if (s.t>a[x][y].t) return false;
    if (s.t<a[x][y].t) a[x][y]=s;
    else
    {
        long long ans=s.v;
        a[x][y].v+=ans;
        a[x][y].v%=mod;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);m/=50;
    for (int i=0;i<n;i++) {int x;scanf("%d",&x);x/=50;if (x==1) m1++; else m2++;}
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j].t=1e9;
    c[0][0]=1;
    for (int i=1;i<=50;i++)
      for (int j=0;j<=i;j++)
      {
          c[i][j]=c[i-1][j];
          if (j!=0) c[i][j]+=c[i-1][j-1];
          c[i][j]%=mod;
      }
    a[m1][m2].t=0;a[m1][m2].v=1;
    int size=1,h=0;q[0].x=m1;q[0].y=m2;
    used[m1][m2]=true;
    while (h<size)
    {
        int x=q[h].x,y=q[h].y;h++;
        used[x][y]=false;
        if (x+y*2<=m)
        {
            update(0,0,a[x][y],0,0,0,0,0,0,0,0);
            continue;
        }
        int max=x;if (max>m) max=m;
        for (int i=0;i<=max;i++)
        if (i==0)
        {
            if (m1-x<=0) continue;
            int u=m/2;if (u>y) u=y;
            int v=m1-x;if (v>m) v=m;
            for (int uu=1;uu<=u;uu++)
             for (int vv=0;vv<=v;vv++)
             {
                int w=m2-y+uu;if (w>m/2) w=m/2;
                for (int ww=0;ww<=w;ww++)
                if ((ww*2+vv<=m)&&(vv+ww>0))
            if ((update(x+vv,y-uu+ww,a[x][y],x,0,y,uu,m1-x,vv,m2-y+uu,ww))&&(!used[x+vv][y-uu+ww]))
            {
                q[size].x=x+vv;q[size].y=y-uu+ww;
                q[size].t=a[x][y].t+1;
                used[x+vv][y-uu]=true;
                size++;
            }
             }
        } else
        {
            int u=(m-i)/2;if (u>y) u=y;
            int v=m1-x+i;if (v>m) v=m;
            for (int uu=0;uu<=u;uu++)
              for (int vv=0;vv<=v;vv++)
              {
                int w=m2-y+uu;if (w>m/2) w=m/2;
                for (int ww=0;ww<=w;ww++)
                if ((ww*2+vv<=m)&&(vv+ww>0))
            if ((update(x-i+vv,y-uu+ww,a[x][y],x,i,y,uu,m1-x+i,vv,m2-y+uu,ww))&&(!used[x-i+vv][y-uu+ww]))
            {
                q[size].x=x-i+vv;q[size].y=y-uu+ww;
                q[size].t=a[x][y].t+1;
                used[x-i+vv][y-uu]=true;
                size++;
            }
              }
        }
    }
    if (a[0][0].t==1e9) printf("-1\n0\n");
    else printf("%I64d\n%I64d\n",a[0][0].t*2-1,a[0][0].v);
    return 0;
}

#include<stdio.h>
#include<string.h>

int n,m,x,y,tot;
char ch[15][15];
int a[15][3];
int state[16384][15],que[2][300][2],num[2];
int map[15][15];

void dirct(int dx,int dy,int x,int y)
{
    while (true)
    {
        x+=dx;y+=dy;
        if ((x<0)||(x>=n)||(y<0)||(y>=m)) {break;}
        if (map[x][y]==-2) {break;}
        if (map[x][y]>0) {map[x][y]=-2;break;}
        map[x][y]=-1;
    }
}

void check(int o,int p)
{
    if (map[o][p]<0) {return;}
    if (map[o][p]>0) {map[o][p]=-2;return;}
    map[o][p]=-1;
}

void work(int s,int x,int y,int sum)
{
    memset(map,0,sizeof(map));

    for (int i=0;i<tot;i++)
    if ((s&(1<<i))==0)
    {
        int x,y,z;
        x=a[i][1];y=a[i][2];
        z=a[i][0];
        if (map[x][y]==0) {map[x][y]=i+1;}
    }

    for (int i=0;i<tot;i++)
    if ((s&(1<<i))==0)
    {
        int x,y,z;
        x=a[i][1];y=a[i][2];
        z=a[i][0];
        if (z==0)
        {
            //if ((x>=2)&&((map[x-1][y]==0)||(map[x-1][y]==0-1)))
            if (x>=2)
            {
                if (y>0) check(x-2,y-1);
                if (y<m-1) check(x-2,y+1);
            }
            //if ((x+2<n)&&((map[x+1][y]==0)||(map[x+1][y]==0-1)))
            if (x+2<n)
            {
                if (y>0) check(x+2,y-1);
                if (y<m-1) check(x+2,y+1);
            }

            //if ((y>=2)&&((map[x][y-1]==0)||(map[x][y-1]==0-1)))
            if (y>=2)
            {
                if (x>0) check(x-1,y-2);
                if (x<n-1) check(x+1,y-2);
            }

            //if ((y+2<m)&&((map[x][y+1]==0)||(map[x][y+1]==0-1)))
            if (y+2<m)
            {
                if (x>0) check(x-1,y+2);
                if (x<n-1) check(x+1,y+2);
            }
        } else
        if (z==1)
        {
            dirct(-1,-1,x,y);
            dirct(-1,1,x,y);
            dirct(1,-1,x,y);
            dirct(1,1,x,y);
        } else
        {
            dirct(0,-1,x,y);
            dirct(0,1,x,y);
            dirct(-1,0,x,y);
            dirct(1,0,x,y);
        }
    }

        num[0]=1;
        que[0][0][0]=x;que[0][0][1]=y;map[x][y]=-1;
        int o=0;
        while (num[o]!=0)
        {
            int p=(o^1);
            sum++;num[p]=0;
            for (int i=0;i<num[o];i++)
            {
                int x=que[o][i][0];
                int y=que[o][i][1];
                for (int dx=-1;dx<=1;dx++)
                 for (int dy=-1;dy<=1;dy++)
                  if ((dx!=0)||(dy!=0))
                  {
                      int ux=x+dx,uy=y+dy;
                      if ((ux<0)||(uy<0)||(ux>=n)||(uy>=m)) continue;
                      if (map[ux][uy]<0) continue;
                      if (map[ux][uy]>0)
                      {
                          int u=map[ux][uy]-1;
                          int st=s+(1<<u);
                          if ((state[st][u]<0)||(state[st][u]>sum)) state[st][u]=sum;
                      } else
                      {
                        que[p][num[p]][0]=ux;
                        que[p][num[p]][1]=uy;
                        num[p]++;
                      }
                      map[ux][uy]=-1;
                  }
            }
            o=p;
        }
}

int main()
{
    scanf("%d%d",&n,&m);gets(ch[0]);
    for (int i=0;i<n;i++) gets(ch[i]);
    tot=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (ch[i][j]=='*') {x=i;y=j;}
      else if (ch[i][j]=='K') {a[tot][0]=0;a[tot][1]=i;a[tot][2]=j;tot++;}
      else if (ch[i][j]=='B') {a[tot][0]=1;a[tot][1]=i;a[tot][2]=j;tot++;}
      else if (ch[i][j]=='R') {a[tot][0]=2;a[tot][1]=i;a[tot][2]=j;tot++;}

    for (int i=0;i<(1<<tot);i++) for (int j=0;j<tot;j++) state[i][j]=-1;
    work(0,x,y,0);
    for (int i=1;i<(1<<tot);i++)
     for (int j=0;j<tot;j++)
      if (state[i][j]>0) work(i,a[j][1],a[j][2],state[i][j]);

    int ans=-1;
    if (tot==0) {ans=0;} else
    for (int i=0;i<tot;i++)
    if (state[(1<<tot)-1][i]>0)
    {
        if ((ans<0)||(ans>state[(1<<tot)-1][i])) {ans=state[(1<<tot)-1][i];}
    }
    printf("%d\n",ans);

    return 0;
}

#include<stdio.h>
char c[50][50];
int b[50][50][5],d[4][2],f[2][13500][3],g[2];
int sx,sy,ex,ey,n,m,k;

int abs(int o)
{
    if (o<0) {o=-o;}
    return o;
}

int target(int x,int y,int z,int j)
{
    char c1,c2;
    c1=c[x][y];
    c2=c[x+d[j][0]][y+d[j][1]];
}

void walk(int o,int p)
{
     if (g[o]==0) {return;}
     g[o^1]=0;
     p++;
     for (int i=1;i<=g[o];i++)
      for (int j=0;j<4;j++)
       if ((check(f[i][0],f[i][1],f[i][2],j)&&(p<b[f[i][0]+d[j][0]][f[i][1]+d[j][1]][target(f[i][0],f[i][1],f[i][2],j)]))
       {
          b[f[i][0]+d[j][0]][f[i][1]+d[j][1]][target(f[i][0],f[i][1],f[i][2],j)]=p;
          g[o^1]++;
          int uu=g[o^1];
          f[u][0]=f[i][0]+d[j][0];
          f[u][1]=f[i][1]+d[j][1];
          f[u][2]=target(f[i][0],f[i][1],f[i][2],j);
       }
     walk(o^1,p+1);
}

int main()
{
    d[0][0]=0;d[0][1]=1;
    d[1][0]=0;d[1][1]=-1;
    d[2][0]=1;d[2][1]=0;
    d[3][0]=-1;d[3][1]=0;
    for (int i=0;i<50;i++) for (int j=0;j<50;j++) for (int l=0;l<5;l++) {b[i][j][l]=3000;}
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++) {gets(c[i]);}
    for (int i=0;i<n;i++)
       for (int j=0;j<m;j++)
          {
                if (c[i][j]=='S') {sx=i;sy=j;}
                if (c[i][j]=='T') {ex=i;ey=j;}
          }
    if (abs(sx-sy)+abs(ex-ey)==1) {return 0;}
    
    g[0]=1;f[1][1][0]=ex;f[1][1][1]=ey;f[1][1][2]=0;b[ex][ey][0]=0;
    walk(0,1);
    
    return 0;
}

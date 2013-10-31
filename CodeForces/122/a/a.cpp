#include<stdio.h>
#include<string.h>
char s[50][50];
int n,m;
int x[4],y[4];
bool used[50][50];

void dfs(int a,int b,int &num)
{
    used[a][b]=true;
    num++;
    for (int i=0;i<4;i++)
    if ((a+x[i]>=0)&&(a+x[i]<n)&&(b+y[i]>=0)&&(b+y[i]<m))
    {
        int xx=a+x[i],yy=b+y[i];
        if ((s[xx][yy]=='#')&&(!used[xx][yy])) dfs(xx,yy,num);
    }
}

int work()
{
    int o,p,q;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
     {
      if (s[i][j]=='#') {o=i;p=j;}
      used[i][j]=false;
    }
    q=0;
    dfs(o,p,q);
    return q;
}

int main()
{
    x[0]=0;y[0]=1;
    x[1]=0;y[1]=-1;
    x[2]=1;y[2]=0;
    x[3]=-1;y[3]=0;
    scanf("%d%d",&n,&m);gets(s[0]);
    for (int i=0;i<n;i++) gets(s[i]);
    int ans=2;
    int tot=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (s[i][j]=='#') tot++;
    if (tot==3) {ans=1;} else
    if (tot<3) {ans=-1;} else
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (s[i][j]=='#')
      {
          s[i][j]='.';
          if (work()<tot-1) ans=1;
          s[i][j]='#';
      }

    printf("%d\n",ans);
    return 0;
}

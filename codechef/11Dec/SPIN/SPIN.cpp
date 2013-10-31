#include<stdio.h>
#include<string.h>

struct st
{
    int x,y;
};

st que[2][3000];
int a[50][50],b[50][50],x[4],y[4],c[6],q[2];
bool type[5][4],use[50][50];
int n;

inline int calc()
{
    int ans=1;
    for (int i=1;i<=5;i++) c[i]=0;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) c[b[i][j]]++;
    for (int i=2;i<=5;i++) if (c[i]>c[ans]) ans=i;
    return ans;
}
inline bool match(int x,int y,int x1,int y1)
{
    if (x-1==x1)
    {
        if (((a[x][y]==1)||(a[x][y]==4))&&((a[x1][y1]==2)||(a[x1][y1]==3))) return true;
    }
    if (x+1==x1)
    {
        if (((a[x][y]==2)||(a[x][y]==3))&&((a[x1][y1]==1)||(a[x1][y1]==4))) return true;
    }
    if (y-1==y1)
    {
        if (((a[x][y]==3)||(a[x][y]==4))&&((a[x1][y1]==2)||(a[x1][y1]==1))) return true;
    }
    if (y+1==y1)
    {
        if (((a[x][y]==1)||(a[x][y]==2))&&((a[x1][y1]==3)||(a[x1][y1]==4))) return true;
    }

    return false;
}

inline bool next_match(int x,int y,int x1,int y1)
{
    int uu=a[x][y];
    a[x][y]++;if (a[x][y]>4) a[x][y]=1;
    if (x-1==x1)
    {
        if (((a[x][y]==1)||(a[x][y]==4))&&((a[x1][y1]==2)||(a[x1][y1]==3))) {a[x][y]=uu;return true;}
    }
    if (x+1==x1)
    {
        if (((a[x][y]==2)||(a[x][y]==3))&&((a[x1][y1]==1)||(a[x1][y1]==4))) {a[x][y]=uu;return true;}
    }
    if (y-1==y1)
    {
        if (((a[x][y]==3)||(a[x][y]==4))&&((a[x1][y1]==2)||(a[x1][y1]==1))) {a[x][y]=uu;return true;}
    }
    if (y+1==y1)
    {
        if (((a[x][y]==1)||(a[x][y]==2))&&((a[x1][y1]==3)||(a[x1][y1]==4))) {a[x][y]=uu;return true;}
    }
    a[x][y]=uu;

    return false;
}

inline st deal(int o)
{
    for (int i=n-1;i>=0;i--)
     for (int j=n-1;j>=0;j--)
     if (b[i][j]!=o)
     {
         int col=a[i][j];
         for (int k=0;k<4;k++)
         if (type[col][k])
         {
             if ((i+x[k]>=0)&&(i+x[k]<n)&&(j+y[k]>=0)&&(j+y[k]<n)&&(b[i+x[k]][j+y[k]]==o)/*&&(next_match(i+x[k],j+y[k],i,j))*/)
             {
                 st tmp;
                 tmp.x=i+x[k];
                 tmp.y=j+y[k];
                 return tmp;
             }
         }
     }

    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
     {
         int col=a[i][j];
         for (int k=0;k<4;k++)
         if (type[col][k])
         {
             if ((i+x[k]>=0)&&(i+x[k]<n)&&(j+y[k]>=0)&&(j+y[k]<n)&&(b[i+x[k]][j+y[k]]==o)&&(next_match(i,j,i+x[k],j+y[k])))
             {
                 st tmp;
                 tmp.x=i;
                 tmp.y=j;
                 return tmp;
             }
         }
     }

    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if (b[i][j]!=o)
      {
        st tmp;
        tmp.x=i;
        tmp.y=j;
        return tmp;
      }
}

inline void switch1(int color)
{
    int l=0;
    color=b[que[0][1].x][que[0][1].y];
    while (q[l]!=0)
    {
        q[l^1]=0;
        memset(use,false,sizeof(use));
        for (int i=1;i<=q[l];i++)
        {
            a[que[l][i].x][que[l][i].y]++;
            if (a[que[l][i].x][que[l][i].y]>4) a[que[l][i].x][que[l][i].y]=1;
            b[que[l][i].x][que[l][i].y]=color;
            use[que[l][i].x][que[l][i].y]=true;
        }

        for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
         {
             for (int k=0;k<4;k++)
             if (type[a[i][j]][k])
             {
                 if ((i+x[k]>=0)&&(i+x[k]<n)&&(j+y[k]>=0)&&(j+y[k]<n)&&(use[i+x[k]][j+y[k]])&&(match(i,j,i+x[k],j+y[k])))
                 {
                     q[l^1]++;
                     st tmp;
                     tmp.x=i;
                     tmp.y=j;
                     que[l^1][q[l^1]]=tmp;
                     break;
                 }
             }
         }

        l=(l^1);
    }
}

int ans[1000][2];

int main()
{
    x[0]=0;y[0]=1;  //right
    x[1]=0;y[1]=-1; //left
    x[2]=1;y[2]=0;  //down
    x[3]=-1;y[3]=0; //up
    type[1][0]=type[1][3]=true;
    type[2][0]=type[2][2]=true;
    type[3][1]=type[3][2]=true;
    type[4][1]=type[4][3]=true;

    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
          for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
        for (int i=0;i<n;i++)
          for (int j=0;j<n;j++) scanf("%d",&b[i][j]);

        int turns=0,tl=1000;
        if (n>20) tl/=3;
        if (n>40) tl/=3;
        while (turns<=tl)
        {
            int cho=calc();
            if (c[cho]==n*n) break;
            turns++;
            if (turns>tl) break;

            q[0]=q[1]=0;
            q[0]=1;
            que[0][1]=deal(cho);
            ans[turns-1][0]=que[0][1].x;
            ans[turns-1][1]=que[0][1].y;
            switch1(cho);
        }

        if (turns>tl) {printf("-1\n");}
        else
        {
            printf("%d\n",turns);
            for (int i=0;i<turns;i++) printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
        }
    }
    return 0;
}

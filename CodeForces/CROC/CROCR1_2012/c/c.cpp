#include<stdio.h>
int a[500][500],b[500][500][2],c[500][500],d[500][500];
int n,m,k;

inline int max(int o,int p)
{
    if (o>p) return o;return p;
}

inline int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    scanf("%d%d",&n,&m);k=min(n,m);
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
     {
         scanf("%d",&a[i][j]);
         c[i][j]=d[i][j]=a[i][j];
         if (j!=0) c[i][j]+=c[i][j-1];
         if (i!=0) d[i][j]+=d[i-1][j];
     }
    int ans=-500*500*1001;int l=0;
    for (int i=3;i<=k;i+=2)
    {
        if (i==3)
        {
            for (int x=0;x<n-2;x++)
             for (int y=0;y<m-2;y++)
             {
                 b[x][y][l]=c[x][y+2]+c[x+2][y+2]+a[x+1][y+2];
                 if (y!=0)
                 {
                     b[x][y][l]-=c[x][y-1]+c[x+2][y-1];
                 }
                 ans=max(ans,b[x][y][l]);
             }
             l^=1;
             continue;
        }
        if (i==5)
        {
            for (int x=0;x<n-4;x++)
             for (int y=0;y<m-4;y++)
             {
                 b[x][y][l]=c[x][y+4]+c[x+2][y+2]+c[x+4][y+4]+a[x+3][y]+a[x+1][y+4]+a[x+2][y+4]+a[x+3][y+4];
                 if (y!=0)
                 {
                     b[x][y][l]-=c[x][y-1]+c[x+2][y-1]+c[x+4][y-1];
                 }
                 ans=max(ans,b[x][y][l]);
             }
             l^=1;
             continue;
        }
        for (int x=0;x<n-i+1;x++)
         for (int y=0;y<n-i+1;y++)
         {
             b[x][y][l]=b[x+2][y+2][l]+c[x][y+i-1]+c[x+i-1][y+i-1]
                       +d[x+i-2][y]-d[x+1][y]+d[x+i-2][y+i-1]-d[x][y+i-1]+a[x+2][y+1];
             if (y!=0)
             {
                 b[x][y][l]-=c[x][y-1]+c[x+i-1][y-1];
             }
             ans=max(ans,b[x][y][l]);
         }
        l^=1;
    }
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
int f[101][101],g[2][101][101],h[2][101][101];
int a,b,n;

int min(int o,int p)
{
    if (o<p) {return o;}return p;
}

int main()
{
    while (scanf("%d%d",&a,&b)!=EOF)
    {
          if (a==0) {break;}
          scanf("%d",&n);
          for (int i=0;i<=a;i++) for (int j=0;j<=b;j++) {f[i][j]=0;g[0][i][j]=g[1][i][j]=h[0][i][j]=h[1][i][j]=0;}
          for (int i=0;i<n;i++)
          {
              int x,y;
              scanf("%d%d",&x,&y); {f[x][y]=1;}
          }
          for (int i=0;i<=a;i++)
           for (int j=0;j<=b;j++)
            {
                    if (i>0) {f[i][j]+=f[i-1][j];}
                    if (j>0) {f[i][j]+=f[i][j-1];}
                    if ((i>0)&&(j>0)) {f[i][j]-=f[i-1][j-1];}
            }
            
          for (int i=0;i<=a-28;i++)
           for (int j=0;j<=b-15;j++)
            {
              g[0][i][j]=f[i+27][j+14]-f[i][j+14]-f[i+27][j]+f[i][j];
              if (i>0) {g[0][i][j]=min(g[0][i][j],g[0][i-1][j]);}     
              if (j>0) {g[0][i][j]=min(g[0][i][j],g[0][i][j-1]);} 
            }  
          for (int i=a-28;i>=0;i--)
           for (int j=b-15;j>=0;j--)
            {
              g[1][i][j]=f[i+27][j+14]-f[i][j+14]-f[i+27][j]+f[i][j];
              if (i<a-28) {g[1][i][j]=min(g[1][i][j],g[1][i+1][j]);}     
              if (j<b-15) {g[1][i][j]=min(g[1][i][j],g[1][i][j+1]);} 
            }
            
          for (int i=0;i<=a-15;i++)
           for (int j=0;j<=b-28;j++)
            {
              h[0][i][j]=f[i+14][j+27]-f[i][j+27]-f[i+14][j]+f[i][j];
              if (i>0) {h[0][i][j]=min(h[0][i][j],h[0][i-1][j]);}     
              if (j>0) {h[0][i][j]=min(h[0][i][j],h[0][i][j-1]);} 
            }  
          for (int i=a-15;i>=0;i--)
           for (int j=b-28;j>=0;j--)
            {
              h[1][i][j]=f[i+14][j+27]-f[i][j+27]-f[i+14][j]+f[i][j];
              if (i<a-15) {h[1][i][j]=min(h[1][i][j],h[1][i+1][j]);}     
              if (j<b-28) {h[1][i][j]=min(h[1][i][j],h[1][i][j+1]);} 
            }
         
         int ans=n;   
         for (int i=0;i<=a;i++)
          for (int j=0;j<=b;j++)
          {
              if ((i+28<=a)&&(j+15<=b))
              {
                 int x,y;
                 x=f[i+27][j+14]-f[i][j+14]-f[i+27][j]+f[i][j];
                 y=n;
                 int u,v;u=i+28;v=j+15;
                 if ((i-28>=0)&&(b-15>=0)) {y=min(y,g[0][i-28][b-15]);}
                 if ((a-28>=0)&&(j-15>=0)) {y=min(y,g[0][a-28][j-15]);}
                 if ((u+28<=a)&&(b-15>=0)) {y=min(y,g[1][u][b-15]);}
                 if ((a-28>=0)&&(v+15<=b)) {y=min(y,g[1][a-28][v]);}
                 if ((i-15>=0)&&(b-28>=0)) {y=min(y,h[0][i-15][b-28]);}
                 if ((a-15>=0)&&(j-28>=0)) {y=min(y,h[0][a-15][j-28]);}
                 if ((u+15<=a)&&(b-28>=0)) {y=min(y,h[1][u][b-28]);}
                 if ((a-15>=0)&&(v+28<=b)) {y=min(y,h[1][a-15][v]);}
                 
                 ans=min(x+y,ans);
                 if (ans==0)
                 {
                            int sb=0;
                 }
              }
              if ((i+15<=a)&&(j+28<=b))
              {
                 int x,y;
                 x=f[i+14][j+27]-f[i][j+27]-f[i+14][j]+f[i][j];
                 y=n;
                 int u,v;u=i+15;v=j+28;
                 if ((i-28>=0)&&(b-15>=0)) {y=min(y,g[0][i-28][b-15]);}
                 if ((a-28>=0)&&(j-15>=0)) {y=min(y,g[0][a-28][j-15]);}
                 if ((u+28<=a)&&(b-15>=0)) {y=min(y,g[1][u][b-15]);}
                 if ((a-28>=0)&&(v+15<=b)) {y=min(y,g[1][a-28][v]);}
                 if ((i-15>=0)&&(b-28>=0)) {y=min(y,h[0][i-15][b-28]);}
                 if ((a-15>=0)&&(j-28>=0)) {y=min(y,h[0][a-15][j-28]);}
                 if ((u+15<=a)&&(b-28>=0)) {y=min(y,h[1][u][b-28]);}
                 if ((a-15>=0)&&(v+28<=b)) {y=min(y,h[1][a-15][v]);}
                 
                 ans=min(x+y,ans);
                 if (ans==0)
                 {
                            int sb=0;
                 }
              }
          }
          
          printf("%d\n",ans);   
    }
    return 0;
}

#include<stdio.h>
int f[100][100],v[100],e[500][3],g[100][100];
int n,d,tt;

void build(int i,int o,int p)
{
     if (p>d) {return;}
     f[i][o]=p;
     int j=v[o];
     while (j!=0)
     {
           if (f[i][e[j][0]]==-1) {build(i,e[j][0],p+e[j][1]);}
           j=e[j][2];
     }
}

int max(int o,int p)
{
    if (o>p) {return o;} return p;
}

void work(int o,int p)
{
     int l=v[o];
     while (l!=0)
     {
           if (p!=e[l][0]) {
           work(e[l][0],o);
           for (int i=0;i<n;i++)
            if (f[o][i]!=-1)
            {int uu=0;
             for (int j=0;j<n;j++)
              if (f[e[l][0]][j]!=-1)
              {
                 if (i==j) {uu=max(g[e[l][0]][j]+e[l][1],uu);} 
                 else {uu=max(g[e[l][0]][j],uu);}
              }
              
             g[o][i]+=uu;}}
           l=e[l][2];
     }
}

int main()
{
    int maxm=1000000001;
    scanf("%d",&tt);
    while (tt>0)
    {
          tt--;
          scanf("%d%d",&n,&d);
          int m=0;
          for (int i=0;i<n;i++) {v[i]=0;for (int j=0;j<n;j++) {f[i][j]=-1;g[i][j]=0;}}
          for (int i=1;i<n;i++)
          {
              int s,t,w;
              scanf("%d%d%d",&s,&t,&w);
              m++;
              e[m][0]=t;
              e[m][1]=w;
              e[m][2]=v[s];
              v[s]=m;
              m++;
              e[m][0]=s;
              e[m][1]=w;
              e[m][2]=v[t];
              v[t]=m;
          }
          for (int i=0;i<n;i++) build(i,i,0);
          
          work(0,0);
          
          int ans=0;
          for (int i=0;i<n;i++) {if (g[0][i]>ans) {ans=g[0][i];}}
          printf("%d\n",ans);
    }
    return 0;
}

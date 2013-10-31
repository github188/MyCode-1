#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

bool ok[1000];
int e[1000000][3],v[1000],f[30][2],a[30][2],b[900][2],heap[30000],g[1000],g1[1000];
int t,n,m,ans,tot,all,hp,mid;

inline void add_e(int o,int p,int q)
{
       for (int i=0;i<f[p][1];i++)
       {
           all++;
           e[all][0]=f[p][0]+i;
           e[all][1]=v[o];
           e[all][2]=q;
           v[o]=all;
       }
}

bool dfs(int o)
{
     int j=v[o];
     while (j!=0)
     {
           if ((!ok[e[j][0]])&&(e[j][2]<=mid))
           {
              ok[e[j][0]]=true;
              int u=g[e[j][0]];
              g[e[j][0]]=o;
              if ((u==-1)||(dfs(u))) {return true;}
              g[e[j][0]]=u;
           }
           j=e[j][1];
     }
     return false;
}

int find(int o,int l,int r)
{
    while (l!=r)
    {
          int mm=(l+r)>>1;
          int mid=heap[mm];
          if (mid<o) {l=mm+1;} else {r=mm;}
    }
    return l;
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          
          ans=tot=all=hp=0;
          scanf("%d%d",&n,&m);
          for (int i=0;i<n;i++)
          {
              scanf("%d%d%d",&a[i][0],&a[i][1],&f[i][1]);
              if (i==0) {f[i][0]=0;} else {f[i][0]=f[i-1][0]+f[i-1][1];}
              tot+=f[i][1];
          }
          for (int i=0;i<m;i++) {scanf("%d%d",&b[i][0],&b[i][1]);}
          for (int i=0;i<tot;i++) {v[i]=0;}
          
          memset(g,-1,1000);
          
          for (int i=0;i<m;i++)
          {
              for (int j=0;j<n;j++)
              {
                  hp++;
                  heap[hp]=(a[j][0]-b[i][0])*(a[j][0]-b[i][0])+(a[j][1]-b[i][1])*(a[j][1]-b[i][1]);
                  add_e(i,j,heap[hp]);
              }
          
              sort(heap+1,heap+hp+1);
              int l,r;
              l=find(ans,1,hp);r=hp;
              mid=heap[(l+r)>>1];
              for (int k=0;k<tot;k++) {g1[k]=g[k];}
              
              while (l!=r)
              { 
                 memset(ok,false,1000);
                 int mm=(l+r)>>1;
                 mid=heap[mm];
                  for (int j=0;j<tot;j++) {g[j]=g1[j];}
                 
                 if (!dfs(i)) {l=mm+1;} else {r=mm;}
              }
              mid=heap[l];
              for (int j=0;j<tot;j++) {g[j]=g1[j];}
              dfs(i);
              
              ans=heap[l];
              
              double anss=ans;
              printf("%.3f\n",sqrt(ans));
          }
          
          if (t!=0) {printf("\n");}
    }
    return 0;
}

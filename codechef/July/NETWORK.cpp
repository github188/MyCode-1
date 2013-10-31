#include<stdio.h>
#include<string.h>
#include<math.h>
bool ok[1000];
int e[1000000][2],v[1000],f[30][2],a[30][2],b[900][2],heap[30000][3],g[1000];
int t,n,m,ans,tot,all,hp;

inline void swap(int &a,int &b)
{
     int c=a;a=b;b=c;
}

void up(int o)
{
     int p=o/2;
     if (p!=0)
     {
              if (heap[p][2]>heap[o][2])
              {
                 swap(heap[o][0],heap[p][0]);
                 swap(heap[o][1],heap[p][1]);
                 swap(heap[o][2],heap[p][2]);
                 up(p);
              }
     }
}

void down(int o)
{
     int p=o*2;
     if (p>hp) {return;}
     if ((p+1<=hp)&&(heap[p][2]>heap[p+1][2])) {p++;}
     
     if (heap[p][2]<heap[o][2])
              {
                 swap(heap[o][0],heap[p][0]);
                 swap(heap[o][1],heap[p][1]);
                 swap(heap[o][2],heap[p][2]);
                 down(p);
              }
}

inline void add_e(int o,int p)
{
       for (int i=0;i<f[p][1];i++)
       {
           all++;
           e[all][0]=f[p][0]+i;
           e[all][1]=v[o];
           v[o]=all;
       }
}

bool dfs(int o)
{
     int j=v[o];
     while (j!=0)
     {
           if (!ok[e[j][0]])
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
                  heap[hp][0]=i;
                  heap[hp][1]=j;
                  heap[hp][2]=(a[j][0]-b[i][0])*(a[j][0]-b[i][0])+(a[j][1]-b[i][1])*(a[j][1]-b[i][1]);
                  up(hp);
              }
              
              while (heap[1][2]<=ans)
                {
                    add_e(heap[1][0],heap[1][1]);
                    heap[1][2]=400000000;
                    down(1);
                }
                memset(ok,false,1000);
              
              while (!dfs(i))
              {
                while (heap[1][2]<=ans)
                {
                    add_e(heap[1][0],heap[1][1]);
                    heap[1][2]=400000000;
                    down(1);
                }
                
                ans=heap[1][2];
                add_e(heap[1][0],heap[1][1]);
                heap[1][2]=400000000;
                down(1);
                memset(ok,false,1000);
              }
              
              double anss=ans;
              printf("%.3f\n",sqrt(ans));
          }
          
          if (t!=0) {printf("\n");}
    }
    return 0;
}

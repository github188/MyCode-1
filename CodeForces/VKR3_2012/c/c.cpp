#include<stdio.h>
#include<string.h>
int edge[4000001][2],last[4000001],c[4000001],f[4000001],w[4000001],spfa[4000001],queue[2][4000001],pre[4000001],dist[4000001];
bool judge[2][4000001];
int tot,v;
const int maxn=1000000000;
const int minn=-1000000000;
//以上定义均与dinic相同

int n,m,i,j,k,l,u1,u2;

inline bool find(int s,int t)                                                                       //找最长路spfa
{
     int i,j,k,l,k1;
     for (i=0;i<=v;i++) {dist[i]=minn;spfa[i]=0;judge[0][i]=judge[1][i]=false;pre[i]=0;}
     dist[s]=0;
     queue[0][0]=1;queue[0][1]=s;judge[0][s]=true;
     l=0;
     while (queue[0][0]!=0)
     {
           //queue[l^1][0]=0;

                   k=queue[0][queue[0][0]];
                   queue[0][0]--;
                   j=last[k];
                   while (j!=0)
                   {
                       if ((j&1)==1)
                       {
                           k1=edge[j][0];
                           if ((f[j]<c[j])&&(dist[k]+w[j]>dist[k1]))
                           {
                               spfa[k1]++;
                               if (spfa[k1]==v) {return false;}
                               pre[k1]=j;
                               dist[k1]=dist[k]+w[j];
                               if (!judge[0][k1])
                               {
                                  queue[0][0]++;
                                  queue[0][queue[0][0]]=k1;
                                  judge[0][k1]=true;;
                               }
                           }
                       } else
                       {
                           k1=edge[j][0];
                           if ((f[j-1]>0)&&(dist[k]-w[j-1]>dist[k1]))
                           {
                               spfa[k1]++;
                               if (spfa[k1]==v) {return false;}
                               pre[k1]=j;
                               dist[k1]=dist[k]-w[j-1];
                               if (!judge[0][k1])
                               {
                                  queue[0][0]++;
                                  queue[0][queue[0][0]]=k1;
                                  judge[0][k1]=true;;
                               }
                           }
                       }
                       j=edge[j][1];
                   }
                   judge[l][k]=false;


     }
     if (pre[t]==0) {return false;}
     return true;
}

inline int min(int o,int p)
{
    if (o<p) {return o;}else {return p;}
}

inline int maxcost(int s,int t)                                                           //计算最大费用最大流
{
    int i,j,k,l,ans,flow,sum,uuu;
    ans=0;uuu=0;
    while (find(s,t))
    {
          uuu++;
       flow=10000;
       sum=0;
       l=t;
       while (l!=s)
       {
          k=pre[l];
          if (k&1==1)
          {
              flow=min(c[k]-f[k],flow);
              //sum+=w[k];
              l=edge[k+1][0];
          }
          else
          {
             flow=min(f[k-1],flow);
             //sum-=w[k-1];
             l=edge[k-1][0];
          }
       }
       l=t;
       while (l!=s)
       {
          k=pre[l];
          if (k&1==1)
          {
              f[k]+=flow;
              sum+=w[k]*flow;
              l=edge[k+1][0];
          }
          else
          {
             f[k-1]-=flow;
             sum-=w[k-1]*flow;
             l=edge[k-1][0];
          }
       }
       ans+=sum;
       //if (uuu==m) {break;}
       if (flow==0) {break;}
    }
    return ans;
}

inline void add_e(int s,int t,int cost,int flow)                                    //添边
{
    tot++;
    edge[tot][0]=t;
    edge[tot][1]=last[s];
    c[tot]=flow;
    f[tot]=0;
    w[tot]=cost;
    last[s]=tot;
    tot++;
    edge[tot][0]=s;
    edge[tot][1]=last[t];
    last[t]=tot;
}

int nn,mm;
int a[1001][3];

int main()
{
    tot=v=0;
    scanf("%d%d",&nn,&mm);
    for (int i=1;i<=nn;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    v=2*nn+3;
    for (int i=1;i<=nn;i++) add_e(1+i,1+nn+i,a[i][2],1);

    for (int i=1;i<=nn;i++)
     for (int j=1;j<=nn;j++)
      if (a[i][0]+a[i][1]-1<a[j][0]) add_e(1+nn+i,1+j,0,1);
    for (int i=1;i<=nn;i++)
    {
        add_e(1,1+i,0,1);
        add_e(1+i+nn,1+nn+nn+1,0,1);
    }
    add_e(1+nn+nn+1,1+nn+nn+2,0,mm);
    maxcost(1,v);
    for (int i=1;i<=nn;i++)
    {
        if (i!=1) printf(" ");
        int j=last[1+i];
        while (j!=0)
        {
            if (edge[j][0]==1+i+nn)
            {
                if (c[j]==f[j]) {printf("1");} else printf("0");
                break;
            }
            j=edge[j][1];
        }
    }
    printf("\n");
    return 0;
}

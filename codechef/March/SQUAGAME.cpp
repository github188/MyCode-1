#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int tr[5000000][4],b[50001],c[50001];
unsigned int fa[50001],sg[50001],f[50001];
int n,t,m;
struct square
{
       unsigned int x,yu,yd,no;
} a[100000];

bool comp(square a,square b)
{
     if (a.x<b.x) {return true;}return false;
}

int find(int o,unsigned int l,unsigned int r,unsigned int x)
{
    if (tr[o][3]==1) {return tr[o][0];}
    unsigned int mid=((l+r)>>1);
    if (x<=mid)
    {
       if (tr[o][1]==-1) {return tr[o][0];}
       return find(tr[o][1],l,mid,x);
    } else
    {
       if (tr[o][2]==-1) {return tr[o][0];}
       return find(tr[o][2],mid+1,r,x);
    }
}

void ins(int o,unsigned int l,unsigned int r,unsigned int x,unsigned int y,unsigned int z)
{
     if ((x<=l)&&(r<=y)) {tr[o][0]=z;tr[o][3]=1;return;}
     if (tr[o][3]==1) 
     {
        if (tr[o][1]>=0)
        {
           tr[tr[o][1]][0]=tr[o][0];
           tr[tr[o][1]][3]=1;
        }
        if (tr[o][2]>=0)
        {
           tr[tr[o][2]][0]=tr[o][0];
           tr[tr[o][2]][3]=1;
        }
     }
     unsigned int mid=((l+r)>>1);
     tr[o][3]=0;
     if (x<=mid)
     {
        if (tr[o][1]==-1)
        {
           m++;
           tr[o][1]=m;
           tr[m][0]=tr[o][0];tr[m][3]=1;
           tr[m][1]=tr[m][2]=-1;
        }
        ins(tr[o][1],l,mid,x,y,z);
     }
     if (y>mid)
     {
        if (tr[o][2]==-1)
        {
           m++;
           tr[o][2]=m;
           tr[m][0]=tr[o][0];tr[m][3]=1;
           tr[m][1]=tr[m][2]=-1;
        }
        ins(tr[o][2],mid+1,r,x,y,z);
     }
}

void del(int o,unsigned int l,unsigned int r,unsigned int x,unsigned int y,unsigned int z)
{
     if ((x<=l)&&(r<=y)) {tr[o][0]=fa[z];tr[o][3]=1;return;}
     unsigned int mid=((l+r)>>1);
     tr[o][3]=0;
     if (x<=mid)
     {
        if (tr[o][1]!=-1)
        {
           del(tr[o][1],l,mid,x,y,z);
        }
     }
     if (y>mid)
     {
        if (tr[o][2]!=-1)
        {
           del(tr[o][2],mid+1,r,x,y,z);
        }
     }
     if ((tr[tr[o][1]][3]==1)&&(tr[tr[o][2]][3]==1)&&(tr[tr[o][1]][0]==tr[tr[o][2]][0]))
     {
       tr[o][0]=tr[tr[o][1]][0];
       tr[o][3]=1;
     }
}

int min(int o,int p)
{
    if (o<p) {return o;}return p;
}

int ans(int o,int p)
{
    int j=c[o];
    int f=n+1;
    while (j!=-1)
    {
          if ((sg[o]^(sg[j]+1))==p) {f=min(f,j);}
          f=min( f, ans(j, (p^(sg[o]^(sg[j]+1)))-1 ) );
          j=b[j];
    }
    return f;
}

void cal(int o)
{
    int j=c[o];sg[o]=0;
    while (j!=-1)
    {
          cal(j);
          sg[o]=(sg[o]^(sg[j]+1));     
          j=b[j];
    }
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          unsigned int s=10000;s=s*s;
          scanf("%d",&n);
          for (int i=0;i<n;i++)
          {
              unsigned int x,y,z;
              scanf("%d%d%d",&x,&y,&z);
              x+=s;y+=s;
              a[i*2].x=x;a[i*2].yd=y;a[i*2].yu=y+z;a[i*2].no=i+1;
              a[i*2+1].x=x+z;a[i*2+1].yd=y;a[i*2+1].yu=y+z;a[i*2+1].no=n+(i+1);
          }
          fa[0]=sg[0]=0;
          sort(a,a+n+n,comp);
          
          m=0;
          tr[m][0]=0;tr[m][3]=1;
          tr[m][1]=tr[m][2]=-1;
          int u=2*n;
          for (int i=0;i<u;i++) 
          {
              if (a[i].no<=n)
              {
                  fa[a[i].no]=find(0,0,s+s+s,a[i].yd);
                  ins(0,0,s+s+s,a[i].yd,a[i].yu,a[i].no);
              } else {del(0,0,s+s+s,a[i].yd,a[i].yu,a[i].no-n);}
          }
          for (int i=0;i<=n;i++) {b[i]=c[i]=-1;}
          for (int i=1;i<=n;i++)
          {
              b[i]=c[fa[i]];
              c[fa[i]]=i;
          }
          
          cal(0);
          if (sg[0]==0) {printf("Fit\n");}
          else
          {
              printf("Fat %d\n",ans(0,0));
          }
    }
    return 0;
}

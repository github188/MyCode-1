#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int tr[5000000][4],fa[50001],sg[50001];
int n,t,m,s;
struct square
{
       int x,yu,yd,no;
} a[100000];

bool comp(square a,square b)
{
     if (a.x<b.x) {return true;}return false;
}

int find(int o,int l,int r,int x)
{
    if (tr[o][3]==1) {return tr[o][0];}
    int mid=((l+r)>>1);
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

void ins(int o,int l,int r,int x,int y,int z)
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
     int mid=((l+r)>>1);
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

void del(int o,int l,int r,int x,int y,int z)
{
     if ((x<=l)&&(r<=y)) {tr[o][0]=fa[z];tr[o][3]=1;return;}
     int mid=((l+r)>>1);
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

int mian()
{
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          s=10000;s=s*s;
          scanf("%d",&n);
          for (int i=0;i<n;i++)
          {
              int x,y,z;
              scanf("%d%d%d",&x,&y,&z);
              x+=s;y+=s;
              a[i*2].x=x;a[i*2].yd=y;a[i*2].yu=y+z;a[i*2].no=i+1;
              a[i*2+1].x=x+z;a[i*2+1].yd=y;a[i*2+1].yu=y+z;a[i*2+1].no=-(i+1);
          }
          fa[0]=sg[0]=0;
          sort(a,a+n,comp);
          
          m=0;
          tr[m][0]=0;tr[m][3]=1;
          tr[m][1]=tr[m][2]=-1;
          int u=2*n;
          for (int i=0;i<u;i++) 
          {
              if (a[i].no>0)
              {
                  fa[a[i].no]=find(0,0,s+s,a[i].yd);
                  ins(0,0,s+s,a[i].yu,a[i].yd,a[i].no);
              } else {del(0,0,s+s,a[i].yd,a[i].yu,-a[i].no);}
          }
          
          int ans=0;
          for (int i=n;i>0;i++) { sg[fa[i]]=sg[fa[i]]^(sg[i]+1); }
          if (sg[0]==0) {printf("Fit\n");}
          else
          {
              
          }
    }
    return 0;
}

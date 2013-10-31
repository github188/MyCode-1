#include<stdio.h>
#include<iostream>
using namespace std;
long long heap[1000000][2],a[10][2],b[500000][3],h[1000000][2];
int tot,n,m,tt;
long long maxx;

void up(int o)
{
     if (o>1)
     {
             int p=o/2;
             if (heap[o][0]<heap[p][0])
             {
                long long k;
                k=heap[o][0];heap[o][0]=heap[p][0];heap[p][0]=k;
                k=heap[o][1];heap[o][1]=heap[p][1];heap[p][1]=k;
                up(p);                          
             }
     } 
}

void down(int o)
{
     int p=o*2;
     if (p>tot) {return;}
     if ((p+1<=tot)&&(heap[p+1][0]<heap[p][0])) {p++;}
     if (heap[p][0]<heap[o][0])
     {
                               long long k;
                k=heap[o][0];heap[o][0]=heap[p][0];heap[p][0]=k;
                k=heap[o][1];heap[o][1]=heap[p][1];heap[p][1]=k;
                down(p);                
     }
}

void up1(int o)
{
     if (o>1)
     {
             int p=o/2;
             if (h[o][0]<h[p][0])
             {
                long long k;
                k=h[o][0];h[o][0]=h[p][0];h[p][0]=k;
                k=h[o][1];h[o][1]=h[p][1];h[p][1]=k;
                up1(p);                          
             }
     } 
}

void down1(int o)
{
     int p=o*2;
     if (p>tt) {return;}
     if ((p+1<=tot)&&(h[p+1][0]<h[p][0])) {p++;}
     if (h[p][0]<h[o][0])
     {
                               long long k;
                k=h[o][0];h[o][0]=h[p][0];h[p][0]=k;
                k=h[o][1];h[o][1]=h[p][1];h[p][1]=k;
                down1(p);                
     }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {scanf("%d%d",&a[i][0],&a[i][1]);}
    tot=1;tt=0;
    heap[1][0]=0;
    heap[1][1]=0;
    maxx=70000;maxx=maxx*maxx;maxx=maxx*maxx;
    for (int i=0;i<m;i++)
    {
        b[i][0]=heap[1][0];
        b[i][1]=heap[1][1];b[i][1]++;
        b[i][2]=b[i][0]+a[0][0]+a[0][1]*b[i][1];
        for (int j=1;j<n;j++)
         if (b[i][0]+a[j][0]+a[j][1]*b[i][1]<b[i][2]) {b[i][2]=b[i][0]+a[j][0]+a[j][1]*b[i][1];}
        tt++;
        h[tt][0]=b[i][2];h[tt][1]=i;up1(tt); 
        long long qq=heap[1][0];
        do {heap[1][0]=maxx;down(1);} while (heap[1][0]==qq);
        while (heap[1][0]>h[1][0])
        {
           int k=h[1][1];long long u=b[k][1];u++;b[k][2]=maxx;
           for (int j=0;j<n;j++)
           {
               tot++;
               heap[tot][0]=b[k][0]+a[j][0]+a[j][1]*b[k][1];
               heap[tot][1]=b[k][1];
               if (heap[tot][0]==12)
               {
                                    int sb=1;
               }
               
               up(tot);
               if (b[k][2]>b[k][0]+a[j][0]+a[j][1]*u) {b[k][2]=b[k][0]+a[j][0]+a[j][1]*u;}
           }
           b[k][1]=u;
           h[1][0]=b[k][2];
           down1(1);
        }
    }

    cout<<heap[1][0]<<endl;
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int r,c,h,w,k,x,y;
int a[700][700],b[400][400],cc[500];
struct loc
{
       int x,y,a;
} heap[2000];

bool comp(loc a,loc b)
{
     if (a.a<b.a) {return true;}
     if ((a.a==b.a)&&(a.x<b.x)) {return true;}
     if ((a.a==b.a)&&(a.x==b.x)&&(a.y>b.y)) {return true;}
     return false;
}

void swap(loc &a,loc &b)
{
     loc c=a;a=b;b=c;
}

void up(int o)
{
     int p=o/2;
     if (p>0)
     {
        if (comp(heap[p],heap[o]))
        {
           swap(heap[o],heap[p]);
           up(p);
        }
     }
}

void down(int o)
{
     int p=o*2;
     if ((p+1<=k)&&(comp(heap[p],heap[p+1]))) {p++;}
     if ((p<=k)&&(comp(heap[o],heap[p])))
     {
        swap(heap[o],heap[p]);
        down(p);
     } 
}

int main()
{
    scanf("%d%d",&r,&c);
    for (int i=0;i<r;i++)
     for (int j=0;j<c;j++) scanf("%d",&a[i][j]);
    scanf("%d%d",&h,&w);
    for (int i=0;i<h;i++)
     for (int j=0;j<w;j++) { scanf("%d",&b[i][j]); if (b[i][j]==0) {x=i;y=j;} }
    scanf("%d%d%d",&x,&y,&k);x--;y--;
    int kk=0;
    for (int i=-200;i<=200;i++) {cc[i+200]=i*i;}
    
    for (int i=0;i<=r-h;i++)
     for (int j=c-w;j>=0;j--)
     {
         int sum=0;
         if (kk<k)
         {
            for (int n=0;n<h;n++)
             for (int m=0;m<w;m++) 
              { sum+=cc[a[i+n][j+m]-b[n][m]-a[i+x][j+y]+200];    }
            kk++;
            heap[kk].x=i+1;heap[kk].y=j+1;heap[kk].a=sum;
            up(kk);
         }
         else
         {
            for (int n=0;n<h;n++) if (sum<heap[1].a) {
            for (int m=0;m<w;m++) { sum+=cc[a[i+n][j+m]-b[n][m]-a[i+x][j+y]+200];if (sum>=heap[1].a) {break;}    } }else {break;}
            if (sum<heap[1].a) 
            {
               heap[1].x=i+1;heap[1].y=j+1;heap[1].a=sum;
               down(1);
            }
         }
     }
    
    sort(heap+1,heap+1+k,comp);
    for (int i=1;i<=k;i++) {printf("%d %d %d\n",heap[i].x,heap[i].y,heap[i].a);} 
    return 0;
}

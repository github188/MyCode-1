#include<stdio.h>
#include<iostream>
using namespace std;

struct ss
{
       int x,y;
} a[100000];

bool comp(ss a,ss b)
{
     if (a.y>b.y) {return true;}
     if (a.y<b.y) {return false;}
     if (a.x<b.x) {return true;}
     return false;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    m=m+m/2;
    for (int i=0;i<n;i++) {scanf("%d%d",&a[i].x,&a[i].y);}
    sort(a,a+n,comp);
    for (int i=0;i<m;i++) {printf("%d %d\n",a[i].x,a[i].y);}
    return 0;
}

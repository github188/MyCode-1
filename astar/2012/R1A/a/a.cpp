#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct st
{
    int x,y,h;
};
st a[2000],b[2000];
int c[2000];
int k;

bool cmp(st a,st b)
{
    if ((a.h>b.h)||((a.h==b.h)&&(a.x<b.x))) return true;
    return false;
}

inline int work(int m)
{
    int o=k;
    for (int i=0;i<m;i++)
    {
        if (a[i].x==o) {o=a[i].y;}
        if (a[i].y==o) {o=a[i].x;}
    }
    return o;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n,m,tot;
        scanf("%d%d%d",&n,&m,&k);k--;
        for (int i=0;i<m;i++) {scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);a[i].h*=2;c[i]=0;a[i].x--;a[i].y--;}
        sort(a,a+m,cmp);
        if (work(m)==0) {printf("Yes\n");continue;}
        bool check=false;
        for (int i=0;i<m;i++)
        {
            st tmp=a[i];
            int j=i;
            while ((a[j].h==a[i].h)&&(j<m)) j++;
            for (int k=m;k>j;k--) a[k]=a[k-1];
            if (tmp.x!=0)
            {
                a[j].x=tmp.x-1;
                a[j].y=tmp.x;
                a[j].h=tmp.h-1;
                if (work(m+1)==0) {check=true;break;}
            }
            {
                a[j].x=tmp.x;
                a[j].y=tmp.y;
                a[j].h=tmp.h-1;
                if (work(m+1)==0) {check=true;break;}
            }
            if (tmp.y<n-1)
            {
                a[j].x=tmp.y;
                a[j].y=tmp.y+1;
                a[j].h=tmp.h-1;
                if (work(m+1)==0) {check=true;break;}
            }
            for (int k=j;k<m;k++) a[k]=a[k+1];

            j=i;
            while ((a[j].h==a[i].h)&&(j>0)) j--;
            for (int k=m;k>j;k--) a[k]=a[k-1];
            if (tmp.x!=0)
            {
                a[j].x=tmp.x-1;
                a[j].y=tmp.x;
                a[j].h=tmp.h+1;
                if (work(m+1)==0) {check=true;break;}
            }
            {
                a[j].x=tmp.x;
                a[j].y=tmp.y;
                a[j].h=tmp.h+1;
                if (work(m+1)==0) {check=true;break;}
            }
            if (tmp.y<n-1)
            {
                a[j].x=tmp.y;
                a[j].y=tmp.y+1;
                a[j].h=tmp.h+1;
                if (work(m+1)==0) {check=true;break;}
            }
            for (int k=j;k<m;k++) a[k]=a[k+1];
        }
        if (check) {printf("Yes\n");} else {printf("No\n");}
    }
    return 0;
}

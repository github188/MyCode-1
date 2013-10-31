#include<stdio.h>
#include<queue>
#include<functional>
#include<iostream>
using namespace std;
int tr[8000000][3];
int n,tot=1;

void insert(int o,int l,int r,int p)
{
    tr[o][2]++;
    int mid=(l+r)/2;
    if (l==r) return;
    if (p<=mid)
    {
        if (tr[o][0]==0)
        {
            tot++;
            tr[o][0]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        insert(tr[o][0],l,mid,p);
    } else
    {
        if (tr[o][1]==0)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        insert(tr[o][1],mid+1,r,p);
    }
}

int find(int o,int l,int r,int p)
{
    if (l==r) return l;
    int mid=(l+r)/2;
    if (tr[o][0]!=0)
    {
        if (p<=tr[tr[o][0]][2]) return find(tr[o][0],l,mid,p);
        p-=tr[tr[o][0]][2];
    }
    return find(tr[o][1],mid+1,r,p);
}

int main()
{
    scanf("%d",&n);
    int m=0;
    tr[1][0]=tr[1][1]=tr[1][2]=0;
    while (n>0)
    {
        n--;
        int x;
        scanf("%d",&x);
        if (x==1)
        {
            m++;
            int y;
            scanf("%d",&y);
            insert(1,1,1000000000,y);
        } else
        {
            if (m<3) printf("No reviews yet\n"); else {printf("%d\n",find(1,1,1000000000,m-m/3+1));}
        }
    }
    return 0;
}

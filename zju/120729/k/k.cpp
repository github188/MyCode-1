#include<stdio.h>
#include<iostream>
using namespace std;
long long x[50000],y[50000],tr[1000000][3];
int n,tot;

void insert(int o,int l,int r,int p,long long q)
{
    if (l==r) {if ((tr[o][2]<0)||(q<tr[o][2]))tr[o][2]=q;return;}
    int mid=(l+r)/2;
    if ((tr[o][2]==-1)||(tr[o][2]>q)) tr[o][2]=q;
    if (p<=mid)
    {
        if (tr[o][0]==-1)
        {
            tot++;
            tr[o][0]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=-1;
        }
        insert(tr[o][0],l,mid,p,q);
    } else
    {
        if (tr[o][1]==-1)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=-1;
        }
        insert(tr[o][1],mid+1,r,p,q);
    }
}

long long find(int o,int l,int r,int p,int q)
{
    if ((p<=l)&&(r<=q)) return tr[o][2];
    int mid=(l+r)/2;
    long long x,y;
    if (p<=mid)
    {
        if (tr[o][0]==-1) {x=-1;}
        else {x=find(tr[o][0],l,mid,p,q);}
    } else {x=-1;}
    if (q>mid)
    {
        if (tr[o][1]==-1) {y=-1;}
        else {y=find(tr[o][1],mid+1,r,p,q);}
    } else {y=-1;}
    if ((x==-1)||((y!=-1)&&(y<x))) x=y;
    return x;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        long long ans=-1;
        for (int i=0;i<n;i++) scanf("%d",&x[i]);
        for (int i=0;i<n;i++) scanf("%d",&y[i]);
        tot=1;
        tr[1][0]=tr[1][1]=tr[1][2]=-1;
        int z=y[0]-1;
        if (z>=n-1)
        {
            z=n-1;
            if ((ans<0)||(x[0]<ans)) ans=x[0];
        }
        insert(1,0,n,z,x[0]);
        for (int i=1;i<n;i++)
        {
            int z=i+y[i]-1;
            long long u=find(1,0,n,i-1,n)+x[i];
            if (z>=n-1)
            {
                z=n-1;
                if ((ans<0)||(u<ans)) ans=u;
            }
            insert(1,0,n,z,u);
        }
        cout<<ans<<endl;
    }
    return 0;
}

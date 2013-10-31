#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long t[4000000][4];
int k1,k2,k3,t1,t2,t3,n,m;
long long c[200000],d[200000];
long long lim;

long long find(int o,long long l,long long r,long long c)
{
     return t[o][1];
}

void deal(int o,long long l,long long r,long long s,long long del)
{
     long long mid,two;two=2;mid=(l+r)/two;
     if (l!=r) 
     if (s<=mid)
     {
                int p;
        if (t[o][2]==0)
        {
           m++;p=m;
           t[o][2]=p;
           t[p][0]=t[p][1]=t[p][2]=t[p][3]=0;t[p][1]=lim;
        } else {p=t[o][2];}
        
        deal(p,l,mid,s,del);
     } else
     {
        int p;mid++;
        if (t[o][3]==0)
        {
           m++;p=m;
           t[o][3]=p;
           t[p][0]=t[p][1]=t[p][2]=t[p][3]=0;t[p][1]=lim;
        } else {p=t[o][3];}
        
        deal(p,mid,r,s,del);
     }
     t[o][0]+=del; if (t[o][0]==0) {t[o][1]=lim;} else {
                   if (l==r) {t[o][1]=s;} else
     if (del>0) {if (s<t[o][1]) {t[o][1]=s;}} else 
     {
        long long rr=lim;int p;p=t[o][2];
        if ((t[o][2]!=0)&&(t[p][0]!=0)) {rr=t[p][1];}
        else
        {
            p=t[o][3];
        if (t[o][3]!=0) {p=t[o][3];if (t[p][0]!=0)rr=t[p][1];}
        }
        t[o][1]=rr;
     }}
}

int main()
{
    scanf("%d%d%d%d%d%d%d",&k1,&k2,&k3,&t1,&t2,&t3,&n);
    for (int i=0;i<n;i++) {scanf("%I64d",&c[i]);d[i]=c[i];}
    lim=10000;lim=lim*lim;lim=lim*10;lim=lim+lim;
    long long ome=1;
    sort(c,c+n);
    m=1;
    t[1][0]=t[1][1]=t[1][2]=t[1][3]=0;t[1][1]=lim;
    deal(1,1,lim,1,k1);
    for (int i=0;i<n;i++)
    {
        long long a=find(1,1,lim,c[i]);
        long long b=a;
        if (a<c[i]) {a=c[i];}
        deal(1,1,lim,a+t1,1);
        deal(1,1,lim,b,-1);
        c[i]=a+t1;
    }
    
    
    sort(c,c+n);
    m=1;
    t[1][0]=t[1][1]=t[1][2]=t[1][3]=0;t[1][1]=lim;
    deal(1,1,lim,1,k2);
    for (int i=0;i<n;i++)
    {
        long long a=find(1,1,lim,c[i]);
        long long b=a;
        if (a<c[i]) {a=c[i];}
        deal(1,1,lim,a+t2,1);
        deal(1,1,lim,b,-1);
        c[i]=a+t2;
    }
    
    
    sort(c,c+n);
    m=1;
    t[1][0]=t[1][1]=t[1][2]=t[1][3]=0;t[1][1]=lim;
    deal(1,1,lim,1,k3);
    for (int i=0;i<n;i++)
    {
        long long a=find(1,1,lim,c[i]);
        long long b=a;
        if (a<c[i]) {a=c[i];}
        deal(1,1,lim,a+t3,1);
        deal(1,1,lim,b,-1);
        c[i]=a+t3;
    }
    
    sort(c,c+n);
    cout<<c[n-1]-d[n-1]<<endl;
    return 0;
}

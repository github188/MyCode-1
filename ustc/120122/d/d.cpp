#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

unsigned int a[26][8];int c[5];
struct node
{
    unsigned int x;
    long long y;
} b[5][500000];

void init(int o,unsigned int p,int q)
{
    if (o>4) return;
    p=p*1000000007;
    for (char i='a';i<='z';i++)
    {
        b[o][c[o]].x=p+i;
        long long u=26,v=i-'a';
        b[o][c[o]].y=q*u+v;
        c[o]++;
        init(o+1,p+i,q*26+i-'a');
    }
}

bool cmp(node a,node b)
{
    if ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y))) return true;
    return false;
}

unsigned int n;
long long tt4;

long long find(int o,unsigned int p)
{
    if (b[o][c[o]-1].x<p) return -1;
    if (b[o][0].x>p) return -1;
    int l=0,r=c[o]-1;
    while (l!=r)
    {
        int mid=(l+r)/2+1;
        if (b[o][mid].x<=p) {l=mid;} else {r=mid-1;}
    }
    if (b[o][l].x!=p) return -1;
    return b[o][l].y;
}

        long long ans=-1;
void work(int o,int p,unsigned int q,long long r)
{
    for (int i='a';i<='z';i++)
    {
        q=q+a[i-'a'][p];

        if (p==5)
        {
            long long f=r*26+i-'a',ans1=find(4,n-q);
            if (ans1!=-1)
            {
                ans=f*tt4+ans1;return;
            }
        } else
        {
            work(o,p-1,q,r*26+i-'a');
            if (ans!=-1) return;
        }
        q-=a[i-'a'][p];
        if (ans!=-1) return;
    }
}

int main()
{
    tt4=26*26*26*26;
    int tt=0;
    for (int i=0;i<26;i++) a[i][1]=i+'a';
    for (int i=2;i<9;i++)
    for (int j=0;j<26;j++) a[j][i]=a[j][i-1]*1000000007;
    c[0]=c[1]=c[2]=c[3]=0;
    init(1,0,0);
    for (int i=1;i<=4;i++)
    {
        sort(b[i],b[i]+c[i],cmp);
    }
    for (int i=1;i<=4;i++)
    for (int j=1;j<c[i];j++)
    if (b[i][j].x==b[i][j-1].x) b[i][j].y=b[i][j-1].y;

    while (true)
    {
        cin>>n;
        if (n==0) break;
        char out[10];
        int k=0;ans=-1;
        for (int i=1;i<=8;i++)
        {
            k=i;
            if (i<5)
            {
                ans=find(i,n);
                if (ans!=-1) break;
            } else
            {
                work(i,i,0,0);
                if (ans!=-1) break;
            }
        }
        out[k]=0;
        tt++;
        for (int i=k-1;i>=0;i--)
        {
            long long u,v;u=26;
            v=ans%u;ans/=u;
            out[i]=v+'a';
        }

        printf("Case %d: %s\n",tt,out);
    }

    return 0;
}

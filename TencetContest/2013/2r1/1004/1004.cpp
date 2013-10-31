#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    long long x,y,v;
};
node heap1[200000],heap2[200000];
int n,tt,q,tot=0,tot1=0;

void up(int o)
{
    if (heap1[o].x>heap1[o].y)
    {
        long long p=heap1[o].y;heap1[o].y=heap1[o].x;heap1[o].x=p;
    }
    if (o==1) return;int p=(o>>1);
    if (heap1[o].x<heap1[p].x)
    {
        node q=heap1[o];heap1[o]=heap1[p];heap1[p]=q;
        up(p);
    }
}

void up1(int o)
{
    if (o==1) return;int p=(o>>1);
    if (heap2[o].y<heap2[p].y)
    {
        node q=heap2[o];heap2[o]=heap2[p];heap2[p]=q;
        up1(p);
    }
}

void down(int o)
{
    int p=(o<<1);
    if (p>tot1) return;
    if ((p+1<=tot1)&&(heap1[p+1].x<heap1[p].x)) p++;
    if (heap1[p].x<heap1[o].x)
    {
        node q=heap1[o];heap1[o]=heap1[p];heap1[p]=q;
        down(p);
    }
}

void down1(int o)
{
    int p=(o<<1);
    if (p>tot) return;
    if ((p+1<=tot)&&(heap2[p+1].y<heap2[p].y)) p++;
    if (heap2[p].y<heap2[o].y)
    {
        node q=heap2[o];heap2[o]=heap2[p];heap2[p]=q;
        down1(p);
    }
}

int main()
{
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            heap1[i*4+1].x=x1;heap1[i*4+1].y=y1;heap1[i*4+1].v=1;up(i*4+1);
            heap1[i*4+2].x=x1;heap1[i*4+2].y=y2;heap1[i*4+2].v=-1;up(i*4+2);
            heap1[i*4+3].x=x2;heap1[i*4+3].y=y1;heap1[i*4+3].v=-1;up(i*4+3);
            heap1[i*4+4].x=x2;heap1[i*4+4].y=y2;heap1[i*4+4].v=1;up(i*4+4);
        }
        tot1=n*4;
        scanf("%d",&q);
        int last=0,size=0;
        long long ans=0,sum2=0,sum1=0;
        tot=0;
        while (q--)
        {
            scanf("%d",&last);
            while (heap1[1].x<=last)
            {
                size-=heap1[1].v;
                sum1+=heap1[1].v*heap1[1].x;tot++;
                heap2[tot].x=heap1[1].x;
                heap2[tot].y=heap1[1].y;
                heap2[tot].v=heap1[1].v;
                up1(tot);
                heap1[1].x=1e9;
                down(1);
            }
            while (heap2[1].y<=last)
            {
                sum1-=heap2[1].x*heap2[1].v;
                ans+=heap2[1].x*heap2[1].y*heap2[1].v;
                heap2[1].y=1e9;
                down1(1);
            }
            long long ans1=ans;
            long long ll=last;ans1+=sum1*ll;
            long long ss=size;ans1+=ss*ll*ll;
            cout<<ans1<<endl;
        }
    }
    return 0;
}

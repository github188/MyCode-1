#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct node
{
    int x,y;
};
long long f[9][262144];
node q[2621440];
long long ans;
int size;

bool cmp(node a,node b)
{
    if ((a.x>b.x)||((a.x==b.x)&&(a.y>b.y))) return true;
    return false;
}

node tran(int s)
{
    node ans,tmp;ans.x=ans.y=0;tmp.x=-1;
    int f=1;
    while (s>0)
    {
        ans.y++;
        int u=s%10;s/=10;
        if (u<4) {ans.x+=0;}
        else
            if (u==4) {ans.x+=f;}
            else
            if (u<7) {ans.x+=2*f;}
            else
            if (u==7) {ans.x+=3*f;}
            else {return tmp;}
        f=(f<<2);
    }
    return ans;
}

void add(long long o,int state,int d)
{
    if (f[d-1][state]==0)
    {
        q[size].x=d;
        q[size].y=state;
        size++;
    }
    f[d-1][state]+=o;
}

int cal_d(int x,int y)
{
    if (x>y) return x;return y;
}

int cal(int x,int y)
{
    int ans=0,o=1;
    while ((x>0)||(y>0))
    {
        int p=(x&3),q=(y&3);
        x=(x>>2);y=(y>>2);
        ans+=cal_d(p,q)*o;
        o=(o<<2);
    }
    return ans;
}

void work(int o,int p)
{
    if (o!=0) ans+=f[o-1][p];
    if (o>=9) return;
    p=(p<<2);
    work(o+1,p+1);
    work(o+1,p+3);
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        memset(f,0,sizeof(f));
        int n;
        scanf("%d",&n);
        size=0;
        while (n>0)
        {
            n--;
            int s;scanf("%d",&s);
            node tmp=tran(s);
            int state=tmp.x,f1=tmp.y;
            if (state<0) continue;
            int up=size;
            for (int i=0;i<up;i++)
            {
                int x=q[i].x,y=q[i].y;
                add(f[x-1][y],cal(y,state),cal_d(f1,x));
            }
            add(1,state,f1);
            sort(q,q+size,cmp);
        }

        ans=0;
        work(0,0);
        cout<<ans<<endl;
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node
{
    int x,y,id;
};

struct edge
{
    int x,up,down,val;
};

node a[100000];
edge e[200000];
int tr[4000000][3],ans[100000];
int tot,num;

bool cmp1(node a,node b)
{
    if (a.x<b.x) return true;
    return false;
}

bool cmp2(edge a,edge b)
{
    if (a.x<b.x) return true;
    return false;
}

void ins(int o,int l,int r,int p,int q,int val)
{
    if ((p<=l)&&(r<=q))
    {
        tr[o][0]+=val;
        return;
    }
    int mid,mid1;
    if (l+r>=0)
    {
        mid=(l+r)/2;
        mid1=mid+1;
    } else
    {
        mid1=(l+r)/2;
        mid=mid1-1;
    }

    if (p<=mid)
    {
        if (tr[o][1]==0)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        ins(tr[o][1],l,mid,p,q,val);
    }

    if (mid1<=q)
    {
        if (tr[o][2]==0)
        {
            tot++;
            tr[o][2]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        ins(tr[o][2],mid1,r,p,q,val);
    }
}

int find(int o,int l,int r,int y)
{
    int ans=tr[o][0];
    int mid,mid1;
    if (l+r>=0)
    {
        mid=(l+r)/2;
        mid1=mid+1;
    } else
    {
        mid1=(l+r)/2;
        mid=mid1-1;
    }

    if (y<=mid)
    {
        if (tr[o][1]!=0) ans+=find(tr[o][1],l,mid,y);
    } else
    {
        if (tr[o][2]!=0) ans+=find(tr[o][2],mid1,r,y);
    }
    return ans;
}

int main()
{
    tot=num=0;
    int n,m;
    scanf("%d%d",&n,&m);
    int tmp=0;
    long long maxl=1000000000,maxdl=2000000000;
    for (int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[i].x=x+y;
        a[i].y=y-x;
        a[i].id=i+1;

        long long u,v,w,t;t=z;
        u=x+y;u-=t;
        if (u<0) u=0;
        v=w=y-x;
        v-=t;
        if (v<-maxl) v=-maxl;
        w+=t;
        if (w>maxl) w=maxl;
        e[tmp].x=u;
        e[tmp].up=v;
        e[tmp].down=w;
        e[tmp].val=1;
        tmp++;

        u=x+y;u+=t;u++;
        if (u>maxdl) u=maxdl;
        v=w=y-x;
        v-=t;
        if (v<-maxl) v=-maxl;
        w+=t;
        if (w>maxl) w=maxl;
        e[tmp].x=u;
        e[tmp].up=v;
        e[tmp].down=w;
        e[tmp].val=-1;
        tmp++;
    }

    int nn=n+n;
    sort(a,a+n,cmp1);
    sort(e,e+nn,cmp2);

    tr[0][0]=tr[0][1]=tr[0][2]=0;
    int h=0;

    for (int i=0;i<n;i++)
    {
        while ((h<nn)&&(e[h].x<=a[i].x))
        {
            ins(0,-1000000000,1000000000,e[h].up,e[h].down,e[h].val);
            h++;
        }
        if (find(0,-1000000000,1000000000,a[i].y)>m)
        {
            ans[num++]=a[i].id;
        }
    }
    sort(ans,ans+num);

    printf("%d\n",num);
    if (num!=0)
    {
        printf("%d",ans[0]);
        for (int i=1;i<num;i++) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

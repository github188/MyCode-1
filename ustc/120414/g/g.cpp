#include<stdio.h>
int tr[6000000][3];
int n,tt,tot;

void ins(int o,int l,int r,int s,int t)
{
    if (tr[o][0]>s) {tr[o][0]=s;}
    if (l==r) return;
    int mid=(l+r)/2;
    if (t<=mid)
    {
        if (tr[o][1]==0)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=1000001;
            tr[tot][1]=0;
            tr[tot][2]=0;
        }
        ins(tr[o][1],l,mid,s,t);
    } else
    {
        if (tr[o][2]==0)
        {
            tot++;
            tr[o][2]=tot;
            tr[tot][0]=1000001;
            tr[tot][1]=0;
            tr[tot][2]=0;
        }
        ins(tr[o][2],mid+1,r,s,t);
    }
}

int find(int o,int l,int r,int t)
{
    if (l==r) return tr[o][0];
    int mid=(l+r)/2;
    int x=-1,y=-1;
    if ((tr[o][1]!=0)&&(t<=mid)) x=find(tr[o][1],l,mid,t);
    if ((t>mid))
    {
        if (tr[o][2]!=0) y=find(tr[o][2],mid+1,r,t);
        if (tr[o][1]!=0) x=tr[tr[o][1]][0];
    }
    if (x==-1) x=y;
    if ((y!=-1)&&(y<x)) x=y;
    return x;
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;int c;
        scanf("%d%d",&n,&c);tot=1;
        tr[1][0]=1000001;tr[1][1]=tr[1][2]=0;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);int tmp=-1;
            if (i!=1) tmp=find(1,0,1000000,x);
            ins(1,0,1000000,i,x);
            if (tmp!=-1)
            {
                tmp=(i-tmp+1)*c;
                if (ans<tmp) ans=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

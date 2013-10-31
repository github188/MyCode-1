#include<stdio.h>
int tr[1000000][2];
double t[1000000][2];
int a[100000][4];
int n,m,tot;
int maxl=2000000000,maxu=1000000000;

void ins(int o,int l,int r,int p,int q)
{
    if (l==r)
    {
        t[o][0]=1;t[o][1]=q;
        return;
    }
    long long uu=l,vv=r,to=2;uu+=vv;uu/=to;
    int mid=uu;
    if (p<=mid)
    {
        if (tr[o][0]==0)
        {
            tot++;
            tr[o][0]=tot;
            tr[tot][0]=tr[tot][1]=0;
            t[tot][0]=1;t[tot][1]=0;
        }
        ins(tr[o][0],l,mid,p,q);
    } else
    {
        if (tr[o][1]==0)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=tr[tot][1]=0;
            t[tot][0]=1;t[tot][1]=0;
        }
        ins(tr[o][1],mid+1,r,p,q);
    }

    double ans=0;
    if (tr[o][0]!=0) ans+=t[tr[o][0]][1];
    if (tr[o][1]!=0) ans+=t[tr[o][1]][1];
    t[o][1]=t[o][0]*ans;
}

void tins(int o,int l,int r,int p,int q,double f)
{
    if ((p<=l)&&(r<=q))
    {
        t[o][0]*=(1-f);
        double ans=0;
        if (tr[o][0]!=0) ans+=t[tr[o][0]][1];
        if (tr[o][1]!=0) ans+=t[tr[o][1]][1];
        if (l==r) ans+=tr[o][1]/(1-f);
        t[o][1]=t[o][0]*ans;
        return;
    }
    long long uu=l,vv=r,to=2;uu+=vv;uu/=to;
    int mid=uu;
    if (p<=mid)
    {
        if (tr[o][0]!=0)
        {
            tins(tr[o][0],l,mid,p,q,f);
        }
    }
    if (q>mid)
    {
        if (tr[o][1]!=0)
        {
            tins(tr[o][1],mid+1,r,p,q,f);
        }
    }
    double ans=0;
    if (tr[o][0]!=0) ans+=t[tr[o][0]][1];
    if (tr[o][1]!=0) ans+=t[tr[o][1]][1];
    t[o][1]=t[o][0]*ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);a[i][0]+=maxu;}
    t[1][0]=1;t[1][1]=0;tot=1;
    for (int i=0;i<m;i++)
    {
        int k,l;scanf("%d%d",&k,&l);k+=maxu;
        ins(1,0,maxl,k,l);
    }

    for (int i=0;i<n;i++)
    {
        int u=a[i][0]-a[i][1];if (u<0) u=0;
        double p=a[i][2];p/=100;
        tins(1,0,maxl,u,a[i][0]-1,p);
        if (maxl-a[i][0]<a[i][1]) {u=maxl;} else {u=a[i][1]+a[i][0];}
        p=a[i][3];p/=100;
        tins(1,0,maxl,a[i][0]+1,u,p);
    }

    printf("%.5f\n",t[1][1]);
    return 0;
}

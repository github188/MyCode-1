#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct st
{
    int d,c;
};
st a[100000];
int tr[4000000][4];
long long t[4000000];
int tot;
int maxl=1000000000;

bool cmp(st a,st b)
{
    if (a.c<b.c) return true;
    return false;
}

void ins_t(int o,int p,int q,int l,int r,int z)
{
    if (tr[o][2]==-1)
    {
        t[o]=0;
        tr[o][2]=tr[o][3]=0;
        if (tr[o][0]!=0)
        {
            int tmp=tr[o][0];
            tr[tmp][2]=-1;
        }
        if (tr[o][1]!=0)
        {
            int tmp=tr[o][1];
            tr[tmp][2]=-1;
        }
    }

    if ((p<=l)&&(r<=q))
    {
        long long ll=l,rr=r,one=1,two=2,zz=z;
        t[o]+=zz*(ll+rr)*(rr-ll+one)/two;
    }

    if ((l<=p)&&(q<=r))
    {
        tr[o][2]+=z;
        tr[o][3]+=(q-p+1)*z;
        return;
    } else {tr[o][3]+=(q-p+1)*z;}

    int mid=(p+q)/2;
    if (l<=mid)
    {
       if (tr[o][0]==0)
       {
           tot++;
           tr[o][0]=tot;
           tr[tot][0]=tr[tot][1]=tr[tot][2]=tr[tot][3]=0;
           t[tot]=0;
       }
       int rr=r;
       if (rr>mid) rr=mid;
       ins_t(tr[o][0],p,mid,l,rr,z);
    }
    if (r>mid)
    {
       if (tr[o][1]==0)
       {
           tot++;
           tr[o][1]=tot;
           tr[tot][0]=tr[tot][1]=tr[tot][2]=tr[tot][3]=0;
           t[tot]=0;
       }
       int ll=l;
       if (ll<mid+1) ll=mid+1;
       ins_t(tr[o][1],mid+1,q,ll,r,z);
    }
}

int check(int o,int p,int q,int s)
{
    int ans=0;
    if (tr[o][2]==-1)
    {
        t[o]=0;
        tr[o][2]=tr[o][3]=0;
        if (tr[o][0]!=0)
        {
            int tmp=tr[o][0];
            tr[tmp][2]=-1;
        }
        if (tr[o][1]!=0)
        {
            int tmp=tr[o][1];
            tr[tmp][2]=-1;
        }
    }
    ans+=tr[o][2]*(s-p+1);
    int mid=(p+q)/2;
    if (s<=mid)
    {
        if (tr[o][0]==0) return;
        if (tr[tr[o][0]][2]==-1) return;
        ans+=check(tr[o][0],p,mid,s);
    } else
    {
        if ((tr[o][0]!=0)&&(tr[tr[o][0]][2]!=-1))
        {
            ans+=tr[tr[o][0]][3];
        }
        if (tr[o][1]==0) return;
        if (tr[tr[o][1]][2]==-1) return;
        ans+=check(tr[o][1],mid+1,q,s);
    }
    return ans;
}

void del_t(int o,int p,int q,int s,int u)
{
    if (tr[o][2]==-1)
    {
        t[o]=0;
        tr[o][2]=tr[o][3]=0;
        if (tr[o][0]!=0)
        {
            int tmp=tr[o][0];
            tr[tmp][2]=-1;
        }
        if (tr[o][1]!=0)
        {
            int tmp=tr[o][1];
            tr[tmp][2]=-1;
        }
    }
    if (tr[o][2]>0)
    {
        u+=tr[o][2];
        tr[o][3]-=(q-p+1)*tr[o][2];
        long long tt=tr[o][2],tp=p,tq=q,ta=0,one=1,two=2;
        ta=(tp+tq)*(tq-tp+one)/two;
        t[o]-=ta;
        tr[o][2]=0;
    }
    int mid=(p+q)/2;
    if (s<=mid)
    {
       if (tr[o][1]==0)
       {
           tot++;
           tr[o][1]=tot;
           tr[tot][0]=tr[tot][1]=tr[tot][2]=tr[tot][3]=0;
           t[tot]=0;
       }
       int tmp=tr[o][1];
       ins_t(tmp,mid+1,q,mid+1,q,z);
       if (tr[o][0]==0)
       {
           tot++;
           tr[o][0]=tot;
           tr[tot][0]=tr[tot][1]=tr[tot][2]=tr[tot][3]=0;
           t[tot]=0;
       }
       del_t()
    }
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n;
        scanf("%d",&n);
        if (n==0)
        {
            printf("0\n");
            continue;
        }
        for (int i=0;i<n;i++) scanf("%d%d",&a[i].d,&a[i].c);
        sort(a,a+n,cmp);
        tot=1;
        tr[tot][0]=tr[tot][1]=tr[tot][2]=tr[tot][3]=0;
        t[tot]=0;
        int last=0;
        for (int i=0;i<n;i++)
        if (a[i].d+a[i].c>0)
        {
            if (a[i].c-last>=a[i].d) {ins_t(1,1,maxl,1,a[i].d,1);last+=a[i].d;}
            {
                ins_t(1,1,maxl,a[i].d-a[i].c+last+1,a[i].d,1);
                a[i].d-=a[i].c-last;
                int l=1,r=a[i].d;
                while (l<r)
                {
                    int mid=(l+r)/2;
                    if (check(1,1,maxl,mid)>=a[i].d-mid+1) {r=mid;} else {l=mid+1;}
                }
                int u=check(1,1,maxl,l);
                if (u!=0)
                {
                    int v=u-a[i].d+l-1;
                    del_t(1,1,maxl,l,0);
                    ins_t(1,1,maxl,l,a[i].d);
                    ins_r(1,1,maxl,l,v);
                }
                last=a[i].c;
            }
        }
        cout<<t[1]<<endl;
    }
    return 0;
}

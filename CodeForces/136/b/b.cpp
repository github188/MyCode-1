#include<stdio.h>
#include<algorithm>
using namespace std;
struct p
{
    int x,y,z;
} a[100000],q[100000];
int tr[4000000][3];
int tot,n,m;
int b[100001][2],c[100001],ans[100001],num[100001];

bool cmp(p a,p b) {return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y)));}
bool cmp1(p a,p b) {return (a.y<b.y);}

void add(int o,int l,int r,int p,int q,int s)
{
    if ((p<=l)&&(r<=q))
    {
        tr[o][2]+=s;
        return;
    }
    int mid=(l+r)/2;
    if (p<=mid)
    {
        if (tr[o][0]==0)
        {
            tot++;
            tr[o][0]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        add(tr[o][0],l,mid,p,q,s);
    }
    if (q>mid)
    {
        if (tr[o][1]==0)
        {
            tot++;
            tr[o][1]=tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        add(tr[o][1],mid+1,r,p,q,s);
    }
}

int find(int o,int l,int r,int p)
{
    int mid=(l+r)/2;
    int ans=tr[o][2];
    if (l!=r)
    {
        if ((p<=mid)&&(tr[o][0]!=0)) ans+=find(tr[o][0],l,mid,p);
        if ((p>mid)&&(tr[o][1]!=0)) ans+=find(tr[o][1],mid+1,r,p);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].x);
        num[i+1]=a[i].x;
        a[i].y=i+1;
        c[i]=0;
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].x,&q[i].y);
        q[i].z=i;
    }
    sort(a,a+n,cmp);
    sort(q,q+m,cmp1);
    int h=0;
    for (int i=0;i<n;i++)
    if (a[i].x>n)
    {
        b[h][1]=i-1;
        h=-1;
        break;
    } else
    if (h==0)
    {
        h=a[i].x;
        b[h][0]=i;
    } else
    if (a[i].x!=a[i-1].x)
    {
        b[h][1]=i-1;
        h=a[i].x;
        b[h][0]=i;
    }
    if (h!=-1) b[h][1]=n-1;
    tot=1;
    tr[1][0]=tr[1][1]=tr[1][2]=0;
    h=0;
    for (int i=1;i<=n;i++)
    {
        if (num[i]<=n)
        {
            c[num[i]]++;
            int l,r;
            if (c[num[i]]>num[i])
            {
                if (c[num[i]]-num[i]-1>0) {l=a[b[num[i]][0]+c[num[i]]-num[i]-2].y+1;} else {l=1;}
                r=a[b[num[i]][0]+c[num[i]]-num[i]-1].y;
                add(1,1,n,l,r,-1);
            }
            if (c[num[i]]>=num[i])
            {
                if (c[num[i]]-num[i]-1>=0) {l=a[b[num[i]][0]+c[num[i]]-num[i]-1].y+1;} else l=1;
                r=r=a[b[num[i]][0]+c[num[i]]-num[i]].y;
                add(1,1,n,l,r,1);
            }
        }
        while ((h<m)&&(q[h].y<=i))
        {
            ans[q[h].z]=find(1,1,n,q[h].x);
            h++;
        }
    }

    for (int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}

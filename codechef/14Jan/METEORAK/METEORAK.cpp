#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    int val,pos;
    bool operator<(const node a) const
    {
        return val>a.val;
    }
} a[1000],poi[1000000];

int num;
struct tree
{
    int left,right,lval,rval,val,isSeg;
} tr[50000];

int newtree(int len)
{
    num++;
    tr[num].left=tr[num].right=tr[num].isSeg=0;
    tr[num].lval=tr[num].rval=tr[num].val=len;
    return num;
}

void add(int o,int l,int r,int pos)
{
    if (l==r) {tr[o].lval=tr[o].rval=tr[o].val=0;tr[o].isSeg=1;return;}
    int mid=(l+r)/2;
    if (tr[o].isSeg==0)
    {
        tr[o].isSeg=1;
        tr[o].left=newtree(mid-l+1);
        tr[o].right=newtree(r-mid);
    }
    if (pos<=mid) add(tr[o].left,l,mid,pos);
    else add(tr[o].right,mid+1,r,pos);
    if (tr[tr[o].left].isSeg==0) tr[o].lval=tr[tr[o].left].rval+tr[tr[o].right].lval;
    else tr[o].lval=tr[tr[o].left].lval;
    if (tr[tr[o].right].isSeg==0) tr[o].rval=tr[tr[o].right].lval+tr[tr[o].left].rval;
    else tr[o].rval=tr[tr[o].right].rval;
    tr[o].val=tr[tr[o].left].val>tr[tr[o].right].val?tr[tr[o].left].val:tr[tr[o].right].val;
    tr[o].val=tr[o].val>tr[tr[o].left].rval+tr[tr[o].right].lval
                ?tr[o].val:tr[tr[o].left].rval+tr[tr[o].right].lval;
}

int ans[1000][1000];
int f[1000];
int n,m,k;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;i++)
    {
        int x,y;scanf("%d%d",&x,&y);x--;y--;
        poi[i].val=x;poi[i].pos=y;
    }
    sort(poi,poi+k);
    for (int j=0;j<m;j++) f[j]=-1;
    int h=k-1;
    for (int i=0;i<n;i++)
    {
        while ((h>=0)&&(poi[h].val==i)) f[poi[h--].pos]=i;
        for (int j=0;j<m;j++) a[j].val=f[j],a[j].pos=j;
        sort(a,a+m);
        num=0;
        newtree(m);
        int r=0;
        for (int j=i;j>=0;j--)
        {
            while ((r<m)&&(a[r].val==j)) add(1,0,m-1,a[r++].pos);
            ans[j][i]=tr[1].val*(i-j+1);
        }
    }
    for (int i=2;i<=n;i++)
        for (int j=0;j<=n-i;j++)
        {
            ans[j][j+i-1]=ans[j][j+i-1]>ans[j+1][j+i-1]?ans[j][j+i-1]:ans[j+1][j+i-1];
            ans[j][j+i-1]=ans[j][j+i-1]>ans[j][j+i-2]?ans[j][j+i-1]:ans[j][j+i-2];
        }
    int q=0;scanf("%d",&q);
    while (q--)
    {
        int x,y;scanf("%d%d",&x,&y);x--;y--;
        printf("%d\n",ans[x][y]);
    }
    return 0;
}

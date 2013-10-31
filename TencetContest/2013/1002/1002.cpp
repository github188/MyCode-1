#include<stdio.h>
#include<string.h>
int a[100001],g[100001];
int n,d,tot;
int tr[500001][3];
int max(int o,int p)
{
    return o>p?o:p;
}
int Sum(int o,int l,int r,int end)
{
    if (r<=end) return tr[o][2];
    int mid=(l+r)/2;
    if (end<=mid)
    {
        if (tr[o][0]==0) return 0;
        return Sum(tr[o][0],l,mid,end);
    } else
    {
        int ans=0;
        if (tr[o][0]!=0) ans=tr[tr[o][0]][2];
        if (tr[o][1]!=0) ans=max(ans,Sum(tr[o][1],mid+1,r,end));
        return ans;
    }
}
void plus(int o,int l,int r,int pos , int num)
{
    tr[o][2]=max(tr[o][2],num);
    if (l==r) return;
    int mid=(l+r)/2;
    if (pos<=mid)
    {
        if (tr[o][0]==0)
        {
            tr[o][0]=++tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        plus(tr[o][0],l,mid,pos,num);
    }
    else
    {
        if (tr[o][1]==0)
        {
            tr[o][1]=++tot;
            tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
        }
        plus(tr[o][1],mid+1,r,pos,num);
    }
}
int main()
{
    while (scanf("%d%d",&n,&d)!=EOF)
    {
        for (int i=1;i<=n;i++) {scanf("%d",&a[i]);g[i]=1;}
        tot=1;
        tr[1][0]=tr[1][1]=tr[1][2]=0;
        int ans=1;
        if (d==0) plus(1,0,100000,a[1],1);
        for (int i=2;i<=n;i++)
        {
            if (i-d-1>0) plus(1,0,100000,a[i-d-1],g[i-d-1]);
            if (a[i]>0)
            {
                g[i]=Sum(1,0,100000,a[i]-1)+1;
                if (g[i]>ans) ans=g[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

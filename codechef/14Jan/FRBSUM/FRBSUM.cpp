#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int a[100000],b[20][100000],sum[20][100000];
int n,m;

void init(int l,int r,int lev)
{
    if (l==r) {sum[lev][l]=b[lev][l]=a[l];return;}
    int mid=(l+r)/2;
    init(l,mid,lev+1);
    init(mid+1,r,lev+1);
    int x=l,y=mid+1,z=l;
    while ((x<=mid)&&(y<=r)) b[lev][z++]=b[lev+1][x]<b[lev+1][y]?b[lev+1][x++]:b[lev+1][y++];
    while (x<=mid) b[lev][z++]=b[lev+1][x++];
    while (y<=r) b[lev][z++]=b[lev+1][y++];
    sum[lev][l]=b[lev][l];
    for (int i=l+1;i<=r;i++) sum[lev][i]=sum[lev][i-1]+b[lev][i];
}

int work(int lev,int l,int r,int x,int y,int big)
{
    if ((r<x)||(l>y)) return 0;
    if ((x<=l)&&(r<=y))
    {
        int u=l,v=r;
        if (b[lev][u]>big) return 0;
        if (b[lev][v]<=big) return sum[lev][v];
        while (u<v)
        {
            int mid=(u+v)/2+1;
            if (b[lev][mid]<=big) u=mid; else v=mid-1;
        }
        return sum[lev][u];
    }
    int mid=(l+r)/2;
    return work(lev+1,l,mid,x,y,big)+work(lev+1,mid+1,r,x,y,big);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    init(0,n-1,0);
    int q;scanf("%d",&q);
    while (q--)
    {
        int l,r;scanf("%d%d",&l,&r);l--;r--;
        int last_sum=0,cur_sum=-1;
        while (true)
        {
            cur_sum=work(0,0,n-1,l,r,last_sum+1);
            if (cur_sum==last_sum) break;
            last_sum=cur_sum;
        }
        printf("%d\n",last_sum+1);
    }
    return 0;
}

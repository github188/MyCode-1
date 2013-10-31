#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct st
{
    double val;
    int no;
};
st a[1000],b[1000];
int n,k;
double ans;
int c[1000][2],d[1000];

bool cmp(st a,st b)
{
    if (a.val>b.val) return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    int u=0,v=0;
    for (int i=0;i<n;i++)
    {
        double x;
        int y;
        scanf("%lf%d",&x,&y);
        if (y==1)
        {
            a[u].val=x;
            a[u].no=i+1;
            u++;
        } else
        {
            b[v].val=x;
            b[v].no=i+1;
            v++;
        }
    }
    sort(a,a+u,cmp);
    sort(b,b+v,cmp);
    if (k<=u) {
    int h=0,j=-1;
    for (int i=0;i<k-1;i++)
    {
        ans+=a[i].val/2;
        c[i][0]=h;
        d[h]=a[i].no;h++;
        while ((j+1<v)&&(b[j+1].val>=a[i].val))
        {
            ans+=b[j+1].val;
            d[h]=b[j+1].no;
            j++;h++;
        }
        c[i][1]=h-1;
    }
    c[k-1][0]=h;
    for (int i=k-1;i<u;i++)
    {
        ans+=a[i].val;
        d[h]=a[i].no;
        h++;
    }int jj=j;j++;
    for (;j<v;j++)
    {
        ans+=b[j].val;
        d[h]=b[j].no;
        h++;
    }
    c[k-1][1]=h-1;
    if ((b[v-1].val<a[u-1].val)&&(jj<v-1)) {ans-=b[v-1].val/2;} else {ans-=a[u-1].val/2;}
    } else
    {
        int h=0;
        for (int i=0;i<u;i++)
        {
            ans+=a[i].val/2;
            c[i][0]=c[i][1]=h;
            d[h]=a[i].no;h++;
        }
        for (int i=0;i<k-u-1;i++)
        {
            ans+=b[i].val;
            c[u+i][0]=c[u+i][1]=h;
            d[h]=b[i].no;h++;
        }
        c[k-1][0]=h;
        for (int i=k-u-1;i<v;i++)
        {
            ans+=b[i].val;
            d[h]=b[i].no;
            h++;
        }
        c[k-1][1]=h-1;
    }
    printf("%.1f\n",ans);
    for (int i=0;i<k;i++)
    {
        printf("%d",c[i][1]-c[i][0]+1);
        for (int j=c[i][0];j<=c[i][1];j++) printf(" %d",d[j]);
        printf("\n");
    }
    return 0;
}

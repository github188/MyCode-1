#include<stdio.h>
#include<algorithm>
using namespace std;

double tv[5000000];
int t[5000000][2];
int tot,tt,d,n;
double a[50000];
int b[50000],c[50000];
struct node
{
    int x,y;
} f[100000];

void insert(int t[][2],double tv[],int o,int l,int r,int p,double q)
{
    tv[o]+=q;
    if (l==r) {return;}
    int mid=((l+r)>>1);
    if (p<=mid)
    {
        if (t[o][0]==0)
        {
            tot++;
            t[o][0]=tot;
            t[tot][0]=t[tot][1]=0;
            tv[tot]=0;
        }
        insert(t,tv,t[o][0],l,mid,p,q);
    } else
    {
        if (t[o][1]==0)
        {
            tot++;
            t[o][1]=tot;
            t[tot][0]=t[tot][1]=0;
            tv[tot]=0;
        }
        insert(t,tv,t[o][1],mid+1,r,p,q);
    }
}

double find(int t[][2],double tv[],int o,int l,int r,int p)
{
    double ans=0;
    if (l==r)
    {
        if (p>l) return tv[o];
        return 0;
    }
    int mid=((l+r)>>1);
    if ((p>mid)&&(t[o][0]!=0)) {ans+=tv[t[o][0]];}
    if ((p<=mid)&&(t[o][0]!=0)) {ans+=find(t,tv,t[o][0],l,mid,p);} else
    if ((p>mid+1)&&(t[o][1]!=0)) ans+=find(t,tv,t[o][1],mid+1,r,p);
    return ans;
}

bool cmp(node a,node b)
{
    return (a.x<b.x);
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d",&n,&d);
        tot=1;
        tv[1]=0;
        t[1][0]=t[1][1]=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            c[i]+=d;
            f[i*2].x=b[i];
            f[i*2].y=i+1;
            f[i*2+1].x=b[i]+d;
            f[i*2+1].y=-i-1;
        }
        sort(f,f+2*n,cmp);
        int m=0,k=0;
        while (k<n+n)
        {
            m++;
            int u=f[k].y;
            if (u>0) {b[u-1]=m;}
            else {c[-u-1]=m;}
            while ((k+1<n+n)&&(f[k].x==f[k+1].x))
            {
                k++;
                int u=f[k].y;
                if (u>0) {b[u-1]=m;}
                else {c[-u-1]=m;}
            }
            k++;
        }
        for (int i=0;i<n;i++) {scanf("%lf",&a[i]);a[i]/=100.0;}

        double ans=0;
        for (int i=n-1;i>=0;i--)
        {
            if (a[i]>0.0) ans+=a[i]*(find(t,tv,1,1,100000,c[i]));
            if (a[i]<1.0) ans+=(1.0-a[i])*(find(t,tv,1,1,100000,b[i]));
            if (a[i]>0.0) insert(t,tv,1,1,100000,c[i],a[i]);
            if (a[i]<1.0) insert(t,tv,1,1,100000,b[i],1-a[i]);
        }
        printf("%.4f\n",ans);
    }
    return 0;
}

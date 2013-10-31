#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct st
{
    int no,w;
    double v;
};
st a[100000];
int n,k;
double h;
int ans[100000];

bool cmp(st a,st b)
{
    if ((a.w<b.w)||((a.w==b.w)&&(a.v<b.v))) return true;return false;
}

int main()
{
    scanf("%d%d%lf",&n,&k,&h);
    for (int i=0;i<n;i++) {scanf("%d",&a[i].w);a[i].no=i;}
    for (int i=0;i<n;i++) {scanf("%lf",&a[i].v);}sort(a,a+n,cmp);
    double l,r;
    l=0;r=k;r*=h;
    for (int i=0;i<500;i++)
    {
        double t=(l+r)/2;
        int m=k;
        double hi=k;hi*=h;

        for (int j=n-1;j>=0;j--)
        {
            if (hi/a[j].v<=t)
            {
                hi-=h;
                m--;
                if (m==0) break;
            }
        }
        if (m==0)
        {
            r=t;
        } else {l=t;}
    }
    double t=(l+r)/2;
    int m=k;
    double hi=k;hi*=h;
        for (int j=n-1;j>=0;j--)
        {
            if (hi/a[j].v<=r)
            {
                hi-=h;
                m--;
                ans[m]=a[j].no;
                if (m==0) break;
            }
        }
    for (int i=0;i<k-1;i++) printf("%d ",ans[i]+1);
    printf("%d\n",ans[k-1]+1);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct edge
{
    int x,y;
    double v;
};

edge a[1001],b[1001];
int n,m;
int f[100];

bool cmp(edge a,edge b)
{
    if (a.v<b.v) return true;return false;
}

int father(int x)
{
    if (x==f[x]) return x;
    int tmp=father(f[x]);
    f[x]=tmp;
    return tmp;
}

inline double work(double o)
{
    for (int i=1;i<=n;i++) f[i]=i;
    double n1=n-1;
    for (int i=0;i<m;i++)
    {
        b[i]=a[i];
        b[i].v=(b[i].v-o)*(b[i].v-o)/n1;
    }
    sort(b,b+m,cmp);

    double ans=0;
    for (int i=0;i<m;i++)
    if (father(b[i].x)!=father(b[i].y))
    {
        ans+=b[i].v;
        int x=father(b[i].x),y=father(b[i].y);
        f[x]=y;
    }
    return ans;
}

int main()
{
    int tt=0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n==0) break;
        if (n==1) {        tt++;
        printf("Case %d: %.2f\n",tt,0);continue;}
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%lf",&a[i].x,&a[i].y,&a[i].v);
        }
        double ans=-1,arr=0;double kk=n-1;kk=1/kk;
        while (arr<50.01)
        {
            double tmp=work(arr);
            if ((ans<0)||(tmp<ans)) ans=tmp;
            arr+=kk;
        }
        tt++;
        printf("Case %d: %.2f\n",tt,ans);
    }
    return 0;
}

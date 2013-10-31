#include<stdio.h>
#include<algorithm>
using namespace std;

struct st
{
    int x,y;
};
int n,k,d,m;
int l[150000],x[50][150000],a[15000][2];
st f[7500000];

bool cmp(st a,st b)
{
    if (a.x<b.x) return true;
    return false;
}

int main()
{
    scanf("%d%d%d%d",&n,&k,&d,&m);
    for (int i=0;i<n;i++) scanf("%d",&l[i]);
    for (int i=0;i<k;i++) for (int j=0;j<n;j++) scanf("%d",&x[j][i]);
    for (int i=0;i<m;i++) {scanf("%d%d",&f[i].x,&f[j].y);f[i].x--;f[i].y--;}
    sort(f,f+m,cmp);
    if (f[0].x==f[m-1].x)
    {
        int l,r;
        l=0;r=-1;
        for (int i=0;i<m;i++)
        {
            if (f[i].y>l) l=f[i].y;
            if ((f[i].y<r)||(r==-1)) r=f[i].y;
        }
        printf("%d\n",(l-r)*2);
        return 0;
    }
    int j=0;
    for (int i=0;i<n;i++) a[i][0]=a[i][1]=-1;
    for (int i=0;i<n;i++)
    {
        int l=j;
        while ((j<m)&&(f[j].x==i))
        {
            if (f[j].y>a[i][1]) a[i][1]=f[j].y;
            if ((f[j].y<a[i][0])||(a[i][0]==-1)) a[i][0]=f[j].y;
            j++;
        }
    }


    return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
struct eve
{
    int s,e,c;
} a[2000];
int n;
int f[50];

bool cmp(eve a,eve b)
{
    return a.e<b.e;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        for (int i=0;i<50;i++) f[i]=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
        sort(a,a+n,cmp);
        for (int i=1;i<=48;i++)
        {
            f[i]=f[i-1];
            for (int j=0;j<n;j++)
            if ((a[j].e==i)&&(a[j].c+f[a[j].s]>f[i])) f[i]=a[j].c+f[a[j].s];
        }
        printf("%d\n",f[48]);
    }
    return 0;
}

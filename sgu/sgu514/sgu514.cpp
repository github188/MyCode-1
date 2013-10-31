#include<stdio.h>
#include<math.h>
int a[10];
bool b[1024][1001];
int n;
double ans;

int num1(int o)
{
    int ans=0;
    for (int i=0;i<n;i++) if ((o&(1<<i))!=0) {ans++;}
    return ans;
}

int iabs(int o)
{
    if (o<0) {o=-o;}return o;
}

double area(int o,int p,int q)
{
    double a,b,c;
    a=o;b=p;c=q;
    double pi=a+b+c;pi/=2;
    double ans=sqrt(pi*(pi-a)*(pi-b)*(pi-c));
    return ans;
}

void wc1(int o)
{
    int p=num1(o);
    if (p>n-2) {return;}
    if (p==n-2)
    {
        int c[3];c[0]=0;
        for (int i=0;i<n;i++) if ((o&(1<<i))==0) {c[0]++;c[c[0]]=i;}
        for (int j=iabs(a[c[1]]-a[c[2]]);j<=a[c[1]]+a[c[2]];j++)
        if (b[o][j])
        {
            double tmp=area(j,a[c[1]],a[c[2]]);
            if ((tmp<ans)||(ans<0)) {ans=tmp;}
        }
        return;
    }

    for (int i=0;i<=1000;i++)
    if (b[o][i])
    {
        for (int j=0;j<n;j++)
        if ((o&(1<<j))==0)
        {
            int tmpn=iabs(i-a[j]),tmpp=i+a[j];
            b[o+(1<<j)][tmpn]=true;
            if (tmpp<=1000) {b[o+(1<<j)][tmpp]=true;}
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    b[1][a[0]]=true;ans=-1;
    for (int i=0;i<(1<<n);i++) wc1(i);

    printf("%.6f\n",ans);
    return 0;
}

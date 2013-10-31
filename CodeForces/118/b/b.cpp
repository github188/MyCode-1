#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[3];
double s;
double ans[3];

void work1()
{
    int c[3];c[0]=0;
    for (int i=0;i<3;i++) {if (a[i]!=0) {c[0]++;c[c[0]]=i;}ans[i]=0.0;}
    ans[c[1]]=(a[c[1]]*s)/(a[c[1]]+a[c[2]]);
    ans[c[2]]=s-ans[c[1]];
}

void work()
{
    double q=a[0],w=a[1],e=a[2];
    ans[0]=(q*s-(q*w*s)/(w+e))/(q+e-(q*w)/(w+e));
    ans[1]=(w*s-w*ans[0])/(w+e);
    ans[2]=s-ans[0]-ans[1];
}

int main()
{
    scanf("%lf%d%d%d",&s,&a[0],&a[1],&a[2]);
    int k=0;
    for (int i=0;i<3;i++) if (a[i]==0) k++;
    if (k>1)
    {
        int u=0;
        for (int i=0;i<3;i++) {if (a[i]!=0) u=i;ans[i]=0;}
        ans[u]=s;
        printf("%.7f %.7f %.7f\n",ans[0],ans[1],ans[2]);
        return 0;
    }
    if (k==1) {work1();} else {work();}
    printf("%.7f %.7f %.7f\n",ans[0],ans[1],ans[2]);

    return 0;
}

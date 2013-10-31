#include<stdio.h>

int s,n,m,k,t;

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d%d",&s,&n,&m,&k);
        s--;n--;m--;
        double a=(double)n/(double)s,b=1.0-a;
        double ans=0.0,pos=1.0;int no=m-k;
        if (k>n) {printf("%.6f\n",0.0);continue;}
        if (b<1e-10) {printf("%.6f\n",1.0);continue;}
        if (s-m<n-k) {printf("%.6f\n",1.0);continue;}
        for (int i=1;i<=k;i++) pos=pos*((double)((m-i+1)*(n-i+1))/(double)((s-i+1)*(i)));
        for (int i=k+1;i<=n;i++) pos=pos*((double)(s-m-i+k+1)/(double)(s-i+1));
        ans+=pos;
        for (int i=k+1;((i<=m)&&(i<=n));i++)
        {
            pos=pos*((double)((m-i+1)*(n-i+1))/(double)((s-m-n+i)*i));
            ans+=pos;
        }
        printf("%.7f\n",ans);
    }
    return 0;
}

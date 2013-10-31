#include<stdio.h>
#include<string.h>
double l,r;
bool a[1000][1000],used[1000];
double x[1000],y[1000],z[1000],f[1000][1000];
int n,tot,k;
int stack[2000];

int main()
{
    l=0;r=3;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      f[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
    while (r-l>1e-9)
    {
        int kk=0;
        double mid=(l+r)/2.0;
        memset(a,false,sizeof(a));
        memset(used,false,sizeof(used));
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (f[i][j]<mid+1e-12) a[i][j]=true;
        for (int i=0;i<n;i++)
        if (!used[i])
        {
            used[i]=true;
            tot=0;
            stack[tot++]=i;
            while (tot!=0)
            {
                int k=stack[tot-1];
                tot--;
                for (int j=0;j<n;j++)
                if ((!used[j])&&(a[k][j]))
                {
                    stack[tot++]=j;
                    used[j]=true;
                }
            }
            kk++;
        }

        if (kk>=k) {l=mid;} else {r=mid;}
    }
    printf("%.6f\n",(l+r)/2.0);
    return 0;
}

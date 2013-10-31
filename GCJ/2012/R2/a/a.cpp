#include<stdio.h>
int d[10000],l[10000],f[20000],g[20000];
int n,D,tt;

int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) {scanf("%d%d",&d[i],&l[i]);f[i]=-1;}
        scanf("%d",&D);
        int ll,r;
        ll=0;r=-1;
        r=0;
        f[0]=d[0];g[0]=d[0];
        for (int i=1;i<n;i++)
        {
            while ((r>=ll)&&(f[ll]+g[ll]<d[i])) ll++;
            int ff,gg;
            ff=gg=-1;

            if ((r>=ll)&&(min(l[i],d[i]-f[ll])>gg))
            {
                ff=d[i];
                gg=min(l[i],d[i]-f[ll]);
            }
            if (gg>0)
            {
                    r++;
                    f[r]=ff;
                    g[r]=gg;
            }
        }
        printf("Case #%d: ",t);
        bool check=false;
        if (r>=ll)
        {
            for (int i=ll;i<=r;i++)
            if (f[i]+g[i]>=D) check=true;
        }
        if (check) {printf("YES\n");} else {printf("NO\n");}
    }
    return 0;
}

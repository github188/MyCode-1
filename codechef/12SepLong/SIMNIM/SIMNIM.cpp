#include<stdio.h>
long long a[1100],b[1100];
int f[70][1100],g[70],ans[1100];
int t;
bool use[70];

int main()
{
    bool check=false;
    scanf("%d",&t);
    int tt=t;
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++) {scanf("%lld",&a[i]);b[i]=a[i];}
        int size=0;
        while (a[n-1]>0)
        {
            g[size]=(a[n-1]&1);
            use[size]=false;
            a[n-1]>>=1;
            for (int i=0;i<n-1;i++) {f[size][i]=(a[i]&1);a[i]>>=1;}
            size++;
        }
        while (true){int change=0;
        for (int i=0;i<n-1;i++)
        {
            int pos=-1;
            for (int j=0;j<size;j++)
            if ((!use[j])&&(f[j][i]==1)) {pos=j;break;}
            if (pos!=-1)
            {
                change++;
                use[pos]=true;
                for (int j=0;j<size;j++)
                if ((j!=pos)&&(f[j][i]==1))
                {
                    g[j]^=g[pos];
                    for (int k=0;k<n-1;k++) f[j][k]^=f[pos][k];
                }
                break;
            }
        }
        if (change==0) break;}
        long long tmp=0;
        for (int i=0;i<n-1;i++) ans[i]=1;
        for (int i=0;i<size;i++)
        if (g[i]==1)
        {
            int pos=-1;
            for (int j=0;j<n-1;j++) if (f[i][j]==1) {pos=j;break;}
            if (pos!=-1) ans[pos]=2;
        }
        ans[n-1]=2;
        int u=2;
        for (int i=0;i<n;i++) if (ans[i]==1) tmp^=b[i];
        bool check=false;
        for (int i=0;i<n;i++) if (ans[i]==1) {check=true;break;}
        if (!check) {for (int i=0;i<n;i++) ans[i]=1;u=1;}
        if (tmp>0) {for (int i=0;i<n;i++) ans[i]=1;u=1;}
        for (int i=0;i<n;i++) if (b[i]==0) {ans[i]=(++u);}
        for (int i=0;i<n-1;i++) printf("%d ",ans[i]);
        printf("%d\n",ans[n-1]);
    }
    return 0;
}

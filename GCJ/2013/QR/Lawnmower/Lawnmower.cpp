#include<stdio.h>
int a[100][100];
int t,n,m;

bool check()
{
    for (int i=1;i<=100;i++)
    {
        for (int j=0;j<n;j++)
        {
            bool c=true;
            for (int k=0;k<m;k++)
             if ((a[j][k]!=i)&&(a[j][k]!=0)) {c=false;break;}
            if (c) for (int k=0;k<m;k++) a[j][k]=0;
        }
        for (int j=0;j<m;j++)
        {
            bool c=true;
            for (int k=0;k<n;k++)
             if ((a[k][j]!=i)&&(a[k][j]!=0)) {c=false;break;}
            if (c) for (int k=0;k<n;k++) a[k][j]=0;
        }
    }
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (a[i][j]!=0) return false;
    return true;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
        printf("Case #%d: ",tt);
        if (check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

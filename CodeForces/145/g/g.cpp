#include<stdio.h>
int ans[1001][1001],a[1001][2];
int n,m,k;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    m=0;
    k=1;
    a[0][0]=1;a[0][1]=n;
    while (true)
    {
        ans[m][0]=0;
        for (int i=0;i<k;i++)
        if (a[i][0]!=a[i][1])
        {
            int mid=(a[i][1]-a[i][0])/2+a[i][0];
            for (int j=a[i][0];j<=mid;j++) ans[m][++ans[m][0]]=j;
        }
        if (ans[m][0]==0) break;
        int kk=k;
        for (int i=0;i<kk;i++)
        if (a[i][0]!=a[i][1])
        {
            int mid=(a[i][1]-a[i][0])/2+a[i][0];
            int v=a[i][1];
            a[i][1]=mid;
            a[k][0]=mid+1;
            a[k][1]=v;
            k++;
        }
        m++;
    }
    printf("%d\n",m);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<=ans[i][0];j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}

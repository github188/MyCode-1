#include<stdio.h>
int a[100001],b[100001],ans[100001][2];
int n,m,x,y,num;

int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    int k=1,l=1;
    for (int i=1;i<=m;i++)
    {
        //while ((l+1<=n)&&(a[l+1]<=b[i]+x)) l++;
        while ((k+1<=n)&&(a[k]<b[i]-y)) k++;
        if (k>n) break;
        if ((a[k]>=b[i]-y)&&(a[k]<=b[i]+x))
        {
            num++;
            ans[num][0]=k;
            ans[num][1]=i;
            k++;
        }
    }
    printf("%d\n",num);
    for (int i=1;i<=num;i++)
    {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}

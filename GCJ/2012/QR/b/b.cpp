#include<stdio.h>

int a[100];
int t,n,s,p;

int min(int o,int p)
{
    if (o<p) return o;
    return p;
}
int max(int o,int p)
{
    if (o>p) return o;
    return p;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&n,&s,&p);
        int ans=0,x=max(p*3-2,p),y=max(3*p-4,p),tmp=0;
        for (int j=0;j<n;j++)
        {
            int z;
            scanf("%d",&z);
            if (z>=x) ans++;
            if (z>=y) tmp++;
        }
        ans+=min(s,tmp-ans);
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}

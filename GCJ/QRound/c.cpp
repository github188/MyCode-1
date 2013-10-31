#include<stdio.h>
int a[1001];
int ans,n,tt;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&tt);
    for (int ttt=1;ttt<=tt;ttt++)
    {
        scanf("%d",&n);
        int m,u,v;m=ans=0;u=10000000;
        for (int i=0;i<n;i++) {scanf("%d",&v);m=(m^v);ans+=v;if (v<u) {u=v;}}
        if (m==0) {printf("Case #%d: %d\n",ttt,ans-u);} else {printf("Case #%d: NO\n",ttt);}
    }
    return 0;
}

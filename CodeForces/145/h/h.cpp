#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000],b[100000],c[200000],ans[700000];
int n,m;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0;i<m;i++) scanf("%d",&b[i]);
    int ha=n-1,hb=m-1,u=n+m-1;
    int k=0;
    while ((ha>=0)||(hb>=0))
    {
        while ((ha>=0)&&(a[ha]==k))
        {
            c[u]=ha+1;
            u--;
            ha--;
        }
        while ((hb>=0)&&(b[hb]==k))
        {
            c[u]=hb+1+n;
            u--;
            hb--;
        }
        if (ha>=0)
        {
            k^=1;
            c[u]=ha+1;
            ans[++ans[0]]=u+1;
            u--;
            ha--;
        } else
        if (hb>=0)
        {
            k^=1;
            c[u]=hb+1+n;
            ans[++ans[0]]=u+1;
            u--;
            hb--;
        }
    }
    for (int i=0;i<n+m;i++) printf("%d ",c[i]);printf("\n");
    sort(ans+1,ans+1+ans[0]);
    printf("%d\n",ans[0]);
    for (int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}

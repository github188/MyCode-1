#include<stdio.h>
bool a[1000001];
int ans[1000001];

int main()
{
    int n=0;scanf("%d",&n);ans[0]=0;
    while (n--) {int x;scanf("%d",&x);a[x]=true;}
    int h=1;
    for (int i=1;i<=500000;i++)
    if (a[i]&a[1000000-i+1])
    {
        while (true)
        {
            if (!(a[h]|a[1000000-h+1])) break;
            h++;
        }
        ans[++ans[0]]=h;
        ans[++ans[0]]=1000000-h+1;
        h++;
    } else
    if (a[i]|a[1000000-i+1])
    {
        if (a[i]) ans[++ans[0]]=1000000-i+1; else ans[++ans[0]]=i;
    }
    printf("%d\n",ans[0]);
    for (int i=1;i<=ans[0];i++)
    {
        printf("%d",ans[i]);
        if (i==ans[0]) printf("\n"); else printf(" ");
    }
    return 0;
}

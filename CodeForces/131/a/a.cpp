#include<stdio.h>
int a[300],b[300][300],c[300];
bool ok[300];
int n;

int work(int o)
{
    int d[300];
    for (int i=1;i<=n;i++) {d[i]=c[i];ok[i]=false;}
    int ans=0,m=n;
    while (m>0)
    {
        int u=0;
        do
        {
            u=0;
        for (int i=1;i<=n;i++)
        if ((a[i]==o)&&(d[i]==0)&&(!ok[i]))
        {
            u++;
            ok[i]=true;
            ans++;
            m--;
            for (int j=1;j<=b[i][0];j++)
            if (!ok[b[i][j]]) {d[b[i][j]]--;}
        }
        } while (u>0);
        if (m>0)
        {
           ans++;
           o++;
           if (o==4) o=1;
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for (int j=1;j<=x;j++) {int y;scanf("%d",&y);b[y][++b[y][0]]=i;c[i]++;}
    }
    int ans=work(1);
    int o=work(2),p=work(3);
    ans=ans>(o>p?p:o)?(o>p?p:o):ans;
    printf("%d\n",ans);
    return 0;
}

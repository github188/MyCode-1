#include<stdio.h>
int v[100001],e[300001][3],f[100001],stack[2][100001],size[2],fa[100001];
int n;
long long ans;

void bfs()
{
    size[0]=size[1]=0;
    size[0]=1;
    stack[0][0]=1;
    while (size[0]>0)
    {
        size[0]--;
        int o=stack[0][size[0]],j=v[o];
        stack[1][size[1]++]=o;
        while (j!=0)
        {
            if (e[j][0]!=fa[o])
            {
                fa[e[j][0]]=o;
                stack[0][size[0]++]=e[j][0];
            }
            j=e[j][2];
        }
    }
    while (size[1]>0)
    {
        int o=stack[1][--size[1]],j=v[o];
        f[o]=1;
        while (j!=0)
        {
            if (e[j][0]!=fa[o]) f[o]+=f[e[j][0]];
            j=e[j][2];
        }
    }
    for (int i=2;i<=n;i++)
    {
        int j=v[i];
        while (j!=0)
        {
            if (e[j][0]==fa[i])
            {
                long long u=f[i],v=e[j][1];
                if (n-f[i]<u) u=n-f[i];
                ans+=u*v;
            }
            j=e[j][2];
        }
    }
}


int main()
{
    int tt;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {v[i]=0;fa[i]=f[i]=0;}
        int tot=0;
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            tot++;
            e[tot][0]=y;
            e[tot][1]=z;
            e[tot][2]=v[x];
            v[x]=tot;

            tot++;
            e[tot][0]=x;
            e[tot][1]=z;
            e[tot][2]=v[y];
            v[y]=tot;
        }
        ans=0;
        bfs();
        ans+=ans;
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}

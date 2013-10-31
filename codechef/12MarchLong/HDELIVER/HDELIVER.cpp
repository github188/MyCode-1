#include<stdio.h>
int father[100];

int fa(int o)
{
    if (father[o]==o) return o;
    father[o]=fa(father[o]);return father[o];
}

int main()
{
    int tt;scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) father[i]=i;
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int fx=fa(x),fy=fa(y);
            if (fx!=fy)
            {
                father[fx]=fy;
            }
        }
        int q;scanf("%d",&q);
        while (q>0)
        {
            int x,y;scanf("%d%d",&x,&y);
            int fx=fa(x),fy=fa(y);
            if (fx!=fy) {printf("NO\n");}
            else {printf("YO\n");}
            q--;
        }
    }
    return 0;
}

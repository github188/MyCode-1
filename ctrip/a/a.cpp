#include<stdio.h>
int fa[400001],ty[300001];

int fat(int o)
{
    if (fa[o]==o) return o;
    fa[o]=fat(fa[o]); return fa[o];
}

int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        int m,n;scanf("%d%d",&m,&n);
        for (int i=1;i<=3*m+2;i++) fa[i]=i;
        int ans=0;
        while (n--)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            if ((y>m)||(z>m)) ans++; else
            if (x==1)
            {
                int t1,t2;
                int y1=fat(y*3),z1=fat(z*3);
                t1=y1%3;y1/=3;
                t2=z1%3;z1/=3;
                if (y1==z1)
                {
                    if (t1!=t2) ans++;
                } else
                {
                    fa[z1*3+t2]=y1*3+t1;
                    fa[z1*3+(t2+1)%3]=y1*3+(t1+1)%3;
                    fa[z1*3+(t2+2)%3]=y1*3+(t1+2)%3;
                }
            } else
            {
                int t1,t2;
                int y1=fat(y*3),z1=fat(z*3);
                t1=y1%3;y1/=3;
                t2=z1%3;z1/=3;
                if (y1==z1)
                {
                    if ((t1==t2)||((t1+1)%3!=t2)) ans++;
                } else
                {
                    fa[z1*3+t2]=y1*3+(t1+1)%3;
                    fa[z1*3+(t2+1)%3]=y1*3+(t1+2)%3;
                    fa[z1*3+(t2+2)%3]=y1*3+(t1+3)%3;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

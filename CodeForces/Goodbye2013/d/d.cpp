#include<stdio.h>

int k,a,n,m,x,y;

void work()
{
    x=y=0;
    if (a==0) return;
    if (k==0) return;
    if (k==1) {x=a;return;}
    if (k==2) {y=a;return;}
    x=y=-1;
    int f=0,g=1;
    while (true)
    {
        int ll=0;
        while (true)
        {
            if (g*2>m) break;
            long long u=f,v=g,aa=a;
            int p=2;
            while (p<k)
            {
                p++;
                long long w=u;u=v;v=w+u;
                if (v>=aa) break;
            }
            if ((p==k)&&(v==aa))
            {
                x=f;y=g;
                return;
            }
            g++;
            if (g>a) break;
            if (p<k)
            {
                if (g==f) return;
                break;
            }
        }
        if (ll==1) return;
        if (f>a) return;
        f++;g=0;
        if ((f*2>n)||(g*2>m)) return;
    }
}

int main()
{
    scanf("%d%d%d%d",&k,&a,&n,&m);
    work();
    if (x<0)
    {
        printf("Happy new year!\n");
    } else
    {
        for (int i=0;i<x;i++) printf("AC");
        for (int i=0;i<n-x-x;i++) printf("A");printf("\n");
        for (int i=0;i<y;i++) printf("AC");
        for (int i=0;i<m-y-y;i++) printf("A");printf("\n");
    }
    return 0;
}

#include<stdio.h>

int min(int o,int p)
{
    if (o<p) {return o;} return p;
}

void work(int l,int r,int m,int o)
{
    if (m==1)
    {
        if (o==0)
    {
        for (int i=l;i<=r;i++)
        {
            if (i!=l) {printf("++%d",i-1);}
            else {printf("+%d",i);}
        }
    } else
    {
        for (int i=r;i>=l;i--)
        {
            if (i!=r) {printf("--%d",i+1);}
            else {printf("+%d",i);}
        }
    }
        return;
    }
    if (o==0)
    {
        for (int i=l;i<=r;i++)
        {
            if (i!=l) {printf("-%d",i-1);}
            else {printf("+%d",i);}
            work(i+1,r,min(m-1,r-i),o^1);
        }
    } else
    {
        for (int i=r;i>=l;i--)
        {
            if (i!=r) {printf("-%d",i+1);}
            else {printf("+%d",i);}
            work(l,i-1,min(m-1,i-l),o^1);
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    work(1,n,m,0);
    printf("-%d\n",n);
    return 0;
}

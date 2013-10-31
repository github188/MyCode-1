#include<stdio.h>
int v[100001],e[200001][2],q[2][100001],b[100001];
int n,m;
bool use[100001];

int main()
{
    scanf("%d%d",&n,&m);
    int tot=0;
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        tot++;
        e[tot][0]=y;
        e[tot][1]=v[x];
        v[x]=tot;
        tot++;
        e[tot][0]=x;
        e[tot][1]=v[y];
        v[y]=tot;
        b[x]++;
        b[y]++;
    }

    for (int i=0;i<)
    return 0;
}

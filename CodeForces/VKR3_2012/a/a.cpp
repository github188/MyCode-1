#include<stdio.h>
int e[2][200001][2],v[2][100001],c[100001],a[2][100001],b[2][100001];
bool use[2][100001];
int n,m;

void work(int a[][100001],int o)
{
    for (int i=1;i<=a[0][0];i++) use[o][a[0][i]]=true;
    int l=0;
    while (a[l][0]!=0)
    {
        a[l^1][0]=0;
        for (int i=1;i<=a[l][0];i++)
        {
            int j=v[o][a[l][i]];
            while (j!=0)
            {
                if (!use[o][e[o][j][0]])
                {
                    use[o][e[o][j][0]]=true;
                    if ((o!=1)||(c[e[o][j][0]]!=1)) {
                    a[l^1][0]++;
                    a[l^1][a[l^1][0]]=e[o][j][0];}
                }
                j=e[o][j][1];
            }
        }
        l^=1;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        if (c[i]==1)
        {
            a[0][0]++;
            a[0][a[0][0]]=i;
        }
        if (c[i]==2)
        {
            b[0][0]++;
            b[0][b[0][0]]=i;
        }
    }
    int tot=0;
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        tot++;
        e[0][tot][0]=y;
        e[0][tot][1]=v[0][x];
        v[0][x]=tot;
        e[1][tot][0]=x;
        e[1][tot][1]=v[1][y];
        v[1][y]=tot;
    }

    work(a,0);
    work(b,1);

    for (int i=1;i<=n;i++)
    if (use[0][i]&use[1][i]) {printf("1\n");} else printf("0\n");
    return 0;
}

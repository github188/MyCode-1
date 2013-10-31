#include<stdio.h>

int v[200],e[5000][2],tr[200][200];
bool use[200],f[200][2];
int n,m,tot;

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d%d",&n,&m);
        tot=0;
        for (int i=1;i<=n;i++)
        {
            v[i] = 0;
            f[i][0]=f[i][1]=false;
            use[i]=false;
        }
        for (int i=0;i<m;i++)
        {

        }
    }
    return 0;
}


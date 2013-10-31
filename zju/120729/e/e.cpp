#include<stdio.h>
#include<string.h>
int v[210],e[400][3],tr[210][2][2],f[210][210],a[210];
int n,k,m,tot;

void trans(int o,int fa)
{
    tr[o][0][0]=-1;
    int j=v[o];
    if (e[j][0]==fa) j=e[j][2];
    if (j==0) return;
    tr[o][0][0]=e[j][0];
    tr[o][0][1]=e[j][1];
    int cur=e[j][0];
    tr[cur][1][0]=-1;
    j=e[j][2];
    trans(cur,o);
    while (j!=0)
    {
        if (e[j][0]==fa) {j=e[j][2];continue;}
        tr[cur][1][0]=e[j][0];
        tr[cur][1][1]=e[j][1];
        cur=e[j][0];
        tr[cur][1][0]=-1;
        j=e[j][2];
        trans(cur,o);
    }
}

void work(int o,int fa,int p)
{
    int j=o;
    if (p<=m) f[o][p]=a[o];
    if (tr[j][0][0]!=-1)
    {
        work(tr[j][0][0],o,tr[j][0][1]);
        for (int i=p;i<=m;i++) f[o][i]=f[o][i]>f[tr[j][0][0]][i-p]+a[o]?f[o][i]:f[tr[j][0][0]][i-p]+a[o];
    }
    if (tr[j][1][0]!=-1)
    {
        int v=tr[j][1][0];
        work(tr[j][1][0],o,tr[j][1][1]);
        for (int i=m;i>=0;i--)
         for (int j=0;j<=i;j++)
          if ((f[o][i-j]>=0)&&(f[v][j]>=0))
          {
              f[o][i]=f[o][i]>f[o][i-j]+f[v][j]?f[o][i]:f[o][i-j]+f[v][j];
          }
        for (int i=0;i<=m;i++) f[o][i]=f[o][i]>f[tr[j][1][0]][i]?f[o][i]:f[tr[j][1][0]][i];
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        tot=0;
        //memset(v,0,sizeof(v));
        for (int i=1;i<=n;i++) v[i]=0;
        for (int i=1;i<=n;i++) for (int j=0;j<=100;j++) f[i][j]=-1;
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            tot++;
            e[tot][0]=x;
            e[tot][1]=z;
            e[tot][2]=v[y];
            v[y]=tot;

            tot++;
            e[tot][0]=y;
            e[tot][1]=z;
            e[tot][2]=v[x];
            v[x]=tot;
        }
        scanf("%d%d",&k,&m);m/=2;
        tr[k][0][0]=tr[k][1][0]=-1;

        trans(k,0);

        f[k][0]=a[k];
        work(k,0,0);
        int ans=f[k][0];
        for (int i=1;i<=m;i++) ans=ans>f[k][i]?ans:f[k][i];
        printf("%d\n",ans);
    }
    return 0;
}

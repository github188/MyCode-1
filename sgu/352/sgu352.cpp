#include<stdio.h>
#include<string.h>
using namespace std;

int v[2][4100],e[2][200002][3],d[4100],lev[4100],a[10000],first[4100],ans[4100],lca[15][10000],path[4100],ch[4100],c[4100],chc[4100][2];
int n,m,num,tr_num,k;

void dfs(int o)
{
    num++;
    first[o]=num;
    a[num]=o;
    int j=v[1][o];
    while (j!=0)
    {
        int p=e[1][j][0];
        if (lev[p]==0)
        {
            lev[p]=lev[o]+1;
            d[p]=d[o]+e[1][j][1];
            dfs(p);
            num++;
            a[num]=o;
        }
        j=e[1][j][2];
    }
}

void init()
{
    lca[0][0]=1;
    for (int i=1;i<=num;i++) lca[0][i]=a[i];
    k=0;
    while (lca[k][0]*2<=num)
    {
        k++;
        lca[k][0]=lca[k-1][0]*2;
        for (int i=1;i<=num-lca[k][0]+1;i++)
        {
            int p=lca[k-1][i];
            if (lev[p]>lev[lca[k-1][i+lca[k-1][0]]]) p=lca[k-1][i+lca[k-1][0]];
            lca[k][i]=p;
        }
    }
}

inline int find(int o,int p)
{
    int l=first[o],r=first[p],f=0;
    if (r<l) {int u=l;l=r;r=u;}
    while (r-l+1>lca[f][0]+lca[f][0]) f++;
    int q=lca[f][l];
    if (lev[q]>lev[lca[f][r-lca[f][0]+1]]) q=lca[f][r-lca[f][0]+1];
    return q;
}

void work(int o,int fa)
{
    if (o!=1)
    {
        for (int i=1;i<=n;i++) {ch[i]=-1;c[i]=0;}
        int j=v[0][o];
        while (j!=0)
        {
            int p=d[e[0][j][0]]+e[0][j][1];
            if ((ch[e[0][j][0]]<0)||(p<ch[e[0][j][0]])) ch[e[0][j][0]]=p;
            j=e[0][j][2];
        }
        int tmp=-1;
        int tot=0;
        for (int i=1;i<=n;i++)
        if (ch[i]!=-1)
        {
            int p=find(o,i);
            if (p==1)
            {
              if ((tmp<0)||(tmp>ch[i])) tmp=ch[i];
            } else
            {
                tot++;
                chc[tot][0]=i;
                chc[tot][1]=c[p];
                c[p]=tot;
            }
        }
        for (int i=1;i<tr_num;i++)
        {
            int p=path[i];
            if ((tmp>=0)&&((ans[p]<0)||(ans[p]>tmp+d[o]-d[p])))
            {
                ans[p]=tmp+d[o]-d[p];
            }
            //if ((ch[p]>=0)&&((tmp>ch[p])||(tmp<0))) tmp=ch[p];
            int j=c[p];
            while (j!=0)
            {
                int p=chc[j][0];
                if ((ch[p]>=0)&&((tmp>ch[p])||(tmp<0))) tmp=ch[p];
                j=chc[j][1];
            }
        }

        if ((tmp>=0)&&((ans[o]<0)||(tmp<ans[o]))) ans[o]=tmp;
    }

    path[tr_num]=o;tr_num++;
    int j=v[1][o];
    while (j!=0)
    {
        if (e[1][j][0]!=fa) work(e[1][j][0],o);
        j=e[1][j][2];
    }
    tr_num--;
}

int main()
{
    scanf("%d%d",&n,&m);num=0;
    int tot[2];tot[0]=tot[1]=1;
    for (int i=0;i<m;i++)
    {
        int x,y,val,w;
        scanf("%d%d%d%d",&x,&y,&val,&w);

        e[w][tot[w]][0]=y;
        e[w][tot[w]][1]=val;
        e[w][tot[w]][2]=v[w][x];
        v[w][x]=tot[w];
        tot[w]++;

        e[w][tot[w]][0]=x;
        e[w][tot[w]][1]=val;
        e[w][tot[w]][2]=v[w][y];
        v[w][y]=tot[w];
        tot[w]++;
    }

    lev[1]=1;
    dfs(1);
    init();

    for (int i=2;i<=n;i++) ans[i]=-1;
    tr_num=0;
    work(1,0);

    for (int i=2;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);

    return 0;
}

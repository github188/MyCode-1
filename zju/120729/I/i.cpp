#include<stdio.h>
#include<string.h>
int v[200],v1[200],e[10000][2],e1[10000][2],use[10000],use1[10000],pp[200],q[200],r[200];
int tot,tot1,n,m;

void dfs1(int o,int p)
{
    q[o]=true;
    int j=v[o];
    while (j>0)
    {
        if (/*(!use[j])&&*/(e[j][0]!=p))
        {
            use[j]=true;
            if (!q[e[j][0]]) dfs1(e[j][0],p);
        }
        j=e[j][1];
    }
}

void dfs2(int o,int p,int &ans)
{
    r[o]=true;
    if (q[o]) {ans++;pp[o]=true;}
    int j=v1[o];
    while (j>0)
    {
        if (/*(!use1[j])&&*/(e1[j][0]!=p))
        {
            use1[j]=true;
            if (!r[e1[j][0]]) dfs2(e1[j][0],p,ans);
        }
        j=e1[j][1];
    }
}

int work(int o,int p)
{
    memset(q,false,sizeof(q));
    dfs1(o,p);
    int ans=0;
    memset(r,false,sizeof(r));
    dfs2(o,p,ans);
    return ans;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++) v[i]=v1[i]=0;
        tot=tot1=0;
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[++tot][0]=y;
            e[tot][1]=v[x];
            v[x]=tot;
            use[tot]=false;
            e1[++tot1][0]=x;
            e1[tot1][1]=v1[y];
            v1[y]=tot1;
            use1[tot1]=false;
        }

        int ans=-1;
        for (int i=0;i<n;i++)
        {
            memset(use,false,sizeof(use));
            memset(use1,false,sizeof(use1));
            memset(pp,false,sizeof(pp));
            int l=0;
            for (int j=0;j<n;j++)
            if ((!pp[j])&&(i!=j))
            {
                int k=work(j,i);
                if (k>l) l=k;
            }
            if (l==1) l=0;
            if ((ans==-1)||(l<ans)) ans=l;
        }
        printf("%d\n",ans);
    }
    return 0;
}

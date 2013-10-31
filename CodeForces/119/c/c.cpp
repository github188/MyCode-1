#include<stdio.h>

int v[100001],e[500010][2],d[100001],s[2][500000],t[500000],dd[100001];
int n,m,tot,k;
bool a[100001];

int max(int o,int p)
{
    if (o>p) return o;return p;
}

int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    tot=0;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;i++) {int t;scanf("%d",&t);a[t]=true;}
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
    }
    int x,y;
    scanf("%d%d",&x,&y);

    for (int i=1;i<=n;i++) dd[i]=d[i]=-1;
    d[x]=0;
    int t1;
    t1=1;
    t[0]=x;
    while (t1!=0)
    {
        int ss[2];
        ss[0]=1;
        int tt=d[t[t1]];
        s[0][0]=t[t1-1];
        t1--;
        int l=0,k=0;
        while (ss[l]!=0)
        {
            k++;
            ss[l^1]=0;
            for (int i=0;i<ss[l];i++)
            {
                int j=v[s[l][i]];
                while (j!=0)
                {
                    int x=e[j][0];
                    if (d[x]<0)
                    {
                        if (a[x])
                        {
                            t[t1]=x;
                            t1++;
                            d[x]=max(tt,k);
                        } else
                        {
                            s[l^1][ss[l^1]]=x;
                            ss[l^1]++;
                            d[x]=k;
                        }
                    }
                    j=e[j][1];
                }
            }
            l^=1;
        }
    }

    int ss[2];
    ss[0]=1;
    s[0][0]=y;
    int ans=-1;
    int len=0,l=0;
    dd[y]=0;
    while (ss[l]>0)
    {
        ss[l^1]=0;
        len++;
        for (int i=0;i<ss[l];i++)
        {
            int j=v[s[l][i]];
            while (j!=0)
            {
                int x=e[j][0];
                if (d[x]<0)
                {
                    if (a[x])
                    {
                        if (d[x]!=-1)
                        {
                            if (ans<0) {ans=max(len,d[x]);} else {ans=min(ans,max(len,d[x]));}
                        }
                    } else
                    {
                        s[l][ss[l]]=x;
                        d[x]=len;
                    }
                }
                j=e[j][1];
            }
        }
        l^=1;
    }
    printf("%d\n",ans);

    return 0;
}

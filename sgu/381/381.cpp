#include<stdio.h>

int v[100001],e[1000001][3],ans[100001],tmp_ans[2][100001];
int n,m;
bool use[100001],tr[100001];

void dfs(int o,int p,int q)
{
    use[o]=true;
    if (p==1)
    {
        tmp_ans[q][0]++;
        tmp_ans[q][tmp_ans[q][0]]=o;
        tr[o]=true;
    }
    int j=v[o];
    while (j!=0)
    {
        if (!use[e[j][0]])
        {
            int k;
            if (((p==1)&&(e[j][1]==1))||((p==0)&&(e[j][1]==-1))) {k=0;} else {k=1;}
            dfs(e[j][0],k,q);
            if (tmp_ans[q][0]<0) return;
        } else
        {
            int k;
            if (tr[o]) {k=0;} else {k=1;}
            k^=p;
            if (e[j][1]==1)
            {
                if (k==0)
                {
                    tmp_ans[q][0]=-1;
                    return;
                }
            } else
            {
                if (k==1)
                {
                    tmp_ans[q][0]=-1;
                    return;
                }
            }
        }
        j=e[j][2];
    }
}

void work(int o)
{
    for (int i=1;i<=tmp_ans[o][0];i++)
    {
        ans[0]++;
        ans[ans[0]]=tmp_ans[o][i];
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int tot=0;
    for (int i=0;i<m;i++)
    {
        int x,y,u,u1;scanf("%d%d%d%d",&x,&y,&u,&u1);
        tot++;u=u*u1;
        e[tot][0]=y;
        e[tot][1]=u;
        e[tot][2]=v[x];
        v[x]=tot;

        tot++;
        e[tot][0]=x;
        e[tot][1]=u;
        e[tot][2]=v[y];
        v[y]=tot;
    }

    bool isOK=true;
    for (int i=1;i<=n;i++)
    if (!use[i])
    {
        tmp_ans[0][0]=tmp_ans[1][0]=0;
        dfs(i,0,0);
        dfs(i,1,1);
        if ((tmp_ans[0][0]<0)&&(tmp_ans[1][0]<0)) {isOK=false;break;}
        if ((tmp_ans[0][0]<tmp_ans[1][0])||(tmp_ans[1][0]<0)) {work(0);}
        else {work(1);}
    }

    if (!isOK) {printf("NO\n");}
    else
    {
        printf("YES\n%d\n",ans[0]);
        for (int i=1;i<=ans[0];i++)
        printf("%d\n",ans[i]);
    }

    return 0;
}

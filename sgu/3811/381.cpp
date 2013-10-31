#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int v[200001],e[2000001][3],ans[200001],tmp_ans[2][200001];
int n,m;
bool use[2][200001],tr[2][200001];

void dfs(int o,int p,int q)
{
    use[q][o]=true;
    if (p==1)
    {
        if (tmp_ans[q][0]>=0) {
        tmp_ans[q][0]++;
        tmp_ans[q][tmp_ans[q][0]]=o;
        tr[q][o]=true;}
    }
    int j=v[o];
    while (j!=0)
    {
        if (!use[q][e[j][0]])
        {
            int k;
            if (((p==1)&&(e[j][1]==1))||((p==0)&&(e[j][1]==-1))) {k=0;} else {k=1;}
            dfs(e[j][0],k,q);
            //if (tmp_ans[q][0]<0) return;
        } else
        {
            int k;
            if (!tr[q][e[j][0]]) {k=0;} else {k=1;}
            k^=p;
            if (e[j][1]==1)
            {
                if (k==0)
                {
                    tmp_ans[q][0]=-1;
                    //return;
                }
            } else
            {
                if (k==1)
                {
                    tmp_ans[q][0]=-1;
                    //return;
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
    if (!use[0][i])
    {
        tmp_ans[0][0]=tmp_ans[1][0]=0;
        dfs(i,0,0);
        dfs(i,1,1);
        if ((tmp_ans[0][0]<0)&&(tmp_ans[1][0]<0)) {isOK=false;break;}
        if (((tmp_ans[0][0]<tmp_ans[1][0])||(tmp_ans[1][0]<0))&&(tmp_ans[0][0]>=0)) {work(0);}
        else {work(1);}
    }

    if (!isOK) {printf("NO\n");}
    else
    {
        //sort(ans+1,ans+1+ans[0]);
        printf("YES\n%d\n",ans[0]);
        for (int i=1;i<=ans[0];i++)
        printf("%d\n",ans[i]);
    }

    return 0;
}

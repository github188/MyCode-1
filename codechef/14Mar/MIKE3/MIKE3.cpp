//search
#include<stdio.h>

bool used[20001][20],edge[20][20],chosen[20];

void dfs(int set_i,int num,int &ans,int chosen_num)
{
    ans=(ans>chosen_num?ans:chosen_num);
    if (set_i==num) return;
    dfs(set_i+1,num,ans,chosen_num);
    for (int i=0;i<set_i;i++) if ((edge[i][set_i])&&(chosen[i])) return;
    chosen[set_i]=true;
    dfs(set_i+1,num,ans,chosen_num+1);
    chosen[set_i]=false;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int k;scanf("%d",&k);
        while (k--)
        {
            int a;scanf("%d",&a);
            used[a][i]=true;
        }
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<m;j++)
            if (used[i][j])
                for (int k=0;k<m;k++)
                    if ((k!=j)&&(used[i][k])) edge[j][k]=true;
    int ans=0;
    dfs(0,m,ans,0);
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node
{
    int x,y;
};

node tool[100];
int f[100][2000],g[100],h[100],chef[2000][2],team[2000];
int n,m;
bool use[100];

bool cmp(node a,node b)
{
    if (a.y<b.y) return true;
    return false;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        memset(g,0,sizeof(g));
        memset(tool,0,sizeof(tool));
        memset(h,0,sizeof(h));
        memset(team,0,sizeof(team));
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) {tool[i].x=i;tool[i].y=0;}
        for (int i=0;i<m;i++)
        {
            scanf("%d",&chef[i][0]);
            chef[i][0]--;
            int u=chef[i][0];
            f[u][g[u]]=i;
            g[u]++;
            tool[u].y++;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&chef[i][1]);
            chef[i][1]--;
            int u=chef[i][1];
            f[u][g[u]]=i;
            g[u]++;
            tool[u].y++;
        }

        int mark=0;
        while (true)
        {
            memset(use,false,sizeof(use));
            bool check=true;
            mark++;
            sort(tool,tool+n,cmp);
            if (tool[0].y==0) break;
            for (int i=0;i<n;i++)
            if (!use[i])
            {
                int x=tool[i].x;
                int j=h[x];
                while ((j<g[x])&&(team[f[x][j]]!=0)) j++;
                if (j>=g[x])
                {
                    check=false;
                    for (int i=0;i<n;i++) if (team[i]==mark) team[i]=0;
                }
                int y=f[x][j];
                team[y]=mark;
                for (int i=0;i<n;i++)
                if ((tool[i].x==chef[y][0])||(tool[i].x==chef[y][1]))
                {tool[i].y--;use[i]=true;}
                h[x]=j+1;
            }

            if (!check) break;
        }

        for (int i=0;i<m-1;i++) printf("%d ",team[i]);
        printf("%d\n",team[m-1]);
    }
    return 0;
}

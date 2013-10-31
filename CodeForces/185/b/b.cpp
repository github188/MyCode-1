#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int d[100000];
int h[100000],t[100000],a[100000];
int n,m,p;
long long f[100000][101];
int head[101],tail[101];
struct node
{
    long long v,x,k;
} q[101][200000];

long long inf=1e9;

bool check(int p,long long v,long long k)
{
    return (q[p][tail[p]].v-q[p][tail[p]-1].v)*(q[p][tail[p]].k-k)>(q[p][tail[p]].v-v)*(q[p][tail[p]].v-q[p][tail[p]-1].v);
}

long long calc(int p)
{
    long long ans=(q[p][tail[p]].v-q[p][tail[p]-1].v)/(q[p][tail[p]].k-q[p][tail[p]-1].k);
    return ans;
}

void upd(int o,int p)
{
    if (o+1==p)
    {
        head[p]=tail[p]=0;
        q[p][0].v=0;q[p][0].k=o+1;q[p][0].x=inf;
        return;
    }
    while (head[p]<tail[p]) if (check(p,f[o][p],o+1)) tail[p]--; else break;
    tail[p]++;
    q[p][tail[p]].v=f[o][p];
    q[p][tail[p]].k=o+1;
    q[p][tail[p]].x=inf;
    q[p][tail[p]-1].x=calc(p);
}

int main()
{
    scanf("%d%d%d",&n,&m,&p);
    if (p>m) p=m;
    for (int i=1;i<n;i++)
    {
        int x;scanf("%d",&x);
        d[i]=d[i-1]+x;
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&h[i],&t[i]);
        t[i]-=d[h[i]-1];
    }
    sort(t,t+m);
    long long sum=0;
    for (int i=0;i<m;i++) sum+=t[i];
    inf*=inf;
    for (int i=0;i<m;i++)
    {
        int up=i+1;if (p<up) up=p;
        f[i][1]=(long long)(i+1)*(long long)t[i];
        upd(i,1);
        for (int j=2;j<=up;j++)
        if (j<i)
        {
            f[i][j]=(long long)(i-1)*(long long)t[i];
            while ((head[j-1]<tail[j-1])&&(q[j-1][head[j-1]].x<=(long long)t[i])) head[j-1]++;
            f[i][j]+=q[j-1][head[j-1]].v-q[j-1][head[j-1]].k*(long long)t[i];
            upd(i,j);
        }
    }
    printf("%I64d\n",f[m-1][p]-sum);
    return 0;
}

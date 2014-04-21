#include<stdio.h>

int v[100001],e[600001][2];
struct node
{
    int lev,max1,max2,index;
} a[100001];
int n,m,num,index;
long long ans,k;
bool g[100001],s[100001];

void dfs(int o,int lev)
{
    a[o].lev=lev;
    a[o].index=index++;
    int p=v[o];
    while (p>0)
    {
        int q=e[p][0];
        if (a[q].lev<lev)
        {
            if (a[q].lev!=lev-1)
            if (a[q].lev<a[o].max1)
            {
                a[o].max2=a[o].max1;
                a[o].max1=a[q].lev;
            } else
            if (a[q].lev<a[o].max2) a[o].max2=a[q].lev;
        } else
        {
            if (a[q].lev>n){
            dfs(q,lev+1);
            if (a[q].max1<a[o].max1)
            {
                a[o].max2=a[o].max1;
                a[o].max1=a[q].max1;
            } else
            if (a[q].max1<a[o].max2) a[o].max2=a[q].max1;
            if (a[q].max2<a[o].max1)
            {
                a[o].max2=a[o].max1;
                a[o].max1=a[q].max2;
            } else
            if (a[q].max2<a[o].max2) a[o].max2=a[q].max2;}
        }
        p=e[p][1];
    }

    if ((a[o].max1>=a[o].lev)&&(a[o].lev!=0)) {k++;g[o]=true;} else g[o]=false;
    if ((a[o].max1<a[o].lev)&&(a[o].max2>=a[o].lev)) ans++;
}

void dfs1(int o,long long p,int r)
{
    int x=v[o];
    int son=0,s=0;
    bool ch=true;
    while (x!=0)
    {
        int y=e[x][0];
        if (a[y].lev+1<a[o].lev) ch=false;
        if (a[y].lev-1==a[o].lev)
        {
            if (((a[y].max1<a[o].lev)||((a[y].max1==a[o].lev)&&(o==r)))&&(a[y].max2>a[o].lev)) {son++;s=y;}
        }
        x=e[x][1];
    }
    if ((ch)&&(son==1)) ans+=p; else s=-1;
    x=v[o];
    while (x!=0)
    {
        int y=e[x][0];
        if (a[y].lev-1==a[o].lev)
        {
            if (y==s) dfs1(y,p+1,r); else
            if (a[y].max1==a[o].lev) dfs1(y,1,o); else dfs1(y,0,r);
        }
        x=e[x][1];
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    if ((m<2)||(n<3))
    {
        printf("0\n");
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        v[i]=0;
        a[i].max1=a[i].max2=n+1;
        a[i].lev=n+1;
    }
    num=0;
    for (int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        num++;
        e[num][0]=y;
        e[num][1]=v[x];
        v[x]=num;
        num++;
        e[num][0]=x;
        e[num][1]=v[y];
        v[y]=num;
    }
    ans=0;
    index=0;
    dfs(1,0);
    int f=0;
    dfs1(1,0,1);
    long long m1=m,one=1,two=2;
    ans=ans+(m1-k)*k+k*(k-one)/two;
    printf("%lld\n",ans);
    return 0;
}
/*
I
5 6
1 2
2 3
2 4
3 4
3 5
1 5
O
4

I
4 4
1 2
2 3
3 4
1 4
O
6

I
4 5
1 2
2 3
2 4
1 3
1 4
O
2

I
5 6
1 2
2 3
1 3
3 4
4 5
3 5
O
6

I
3 2
1 2
2 3
O
1

I
3 2
1 2
1 3
O
1

I
3 3
1 2
2 3
1 3
O
3
*/

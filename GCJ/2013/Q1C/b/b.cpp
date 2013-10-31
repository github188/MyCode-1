#include<stdio.h>
#include<string.h>

int tt,x,y,k;
char s[10000];
int p[100],q[100];

bool check()
{
    int xx=x,yy=y;
    char a='E',b='N';
    if (x<0) {a='W';x=-x;}
    if (y<0) {b='S';y=-y;}
    for (int i=1;i<=p[0];i++) if (q[i]==0) x+=p[i]; else y+=p[i];
    for (int i=k;i>0;i--)
    {
        bool ok=true;
        for (int j=1;j<=p[0];j++) if (p[j]==i) ok=false;
        if (!ok) continue;
        if (i<=x) {s[i]=a;x-=i;} else {s[i]=b;y-=i;}
    }
    for (int i=1;i<=p[0];i++)
    if (q[i]==0)
    {
        s[p[i]]='W';
        if (a=='W') s[p[i]]='E';
    }else
    {
        s[p[i]]='S';
        if (b=='S') s[p[i]]='N';
    }
    if ((x==0)&&(y==0))
    {
        x=xx;
        y=yy;
        return true;
    }
    x=xx;
    y=yy;
    return false;
}

bool dfs(int o)
{
    if (o>p[0]) return check();
    q[o]=0;if (dfs(o+1)) return true;
    q[o]=1;return dfs(o+1);
}

void work(int x,int y)
{
    memset(s,0,sizeof(s));
    int sum=x+y;
    if (x<0) sum-=2*x;
    if (y<0) sum-=2*y;
    int num=1;k=1;
    while (num<sum)
    {
        k++;num+=k;
    }
    while ((num-sum)&1) {k++;num+=k;}
    int pos=(num-sum)/2;
    if (pos==0)
    {
        char a='E',b='N';
        if (x<0) {a='W';x=-x;}
        if (y<0) b='S';
        for (int i=k;i>0;i--)
        if (i<=x) {s[i-1]=a;x-=i;} else s[i-1]=b;
    } else
    {
        p[0]=1;p[1]=(num-sum)/2;
        if (p[1]>k)
        {
            p[0]=2;p[2]=p[1]-p[1]/2;p[1]/=2;
            if (p[1]==p[2]) {p[1]--;p[2]++;}
        }
        char a='E',b='N';
        if (x<0) {a='W';x=-x;}
        if (y<0) {b='S';y=-y;}
        if (!dfs(1))
        {
            int o=0;
        }
        //printf("%d %d\n",x,y);
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&x,&y);
        work(x,y);
        printf("Case #%d: %s\n",t,s);
    }
    return 0;
}

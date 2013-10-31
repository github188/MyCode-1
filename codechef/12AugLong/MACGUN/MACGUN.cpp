#include<stdio.h>
#include<string.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int64;
typedef int T;
#define mem(a, b) memset(a, b, sizeof(a))
#define Sqr(x) ((x) * (x))
inline T Max(T a, T b) { if (a < b) a = b; return a; }
inline T Min(T a, T b) { if (a > b) a = b; return a; }
inline void Swap(T & a, T & b) { T t = a; a = b; b = t; }

const int maxn = 500000;
const int maxm = 4000000;
const double EPS = 1e-10;
const int INF = INT_MAX / 2;

int mm,n,ans1,ln,rn,tot;
char s[700][700];
bool use[700][700],ok[500000];
int lv[500000],e[4000000][2],b[700][700],c[500000];

struct EDGE
{
    int a, b;
    int next;
};

int nx, ny, m;
EDGE edge[maxm];
int edge_num;
int first[maxn];
int cx[maxn], cy[maxn];// cx[i]表示xi对应的匹配，cy[i]表示yi对应的匹配.
int distx[maxn], disty[maxn]; // 层的概念，即在BFS中的第几层.

int que[maxn];
int head, tail;

int ans;

void Debug(void)
{
    int i, j;
}

void Init(void)
{
    int i, j;
    for (int i=0;i<=ln;i++) first[i]=cx[i]=-1;
    for (int i=0;i<=rn;i++) cy[i]=-1;
    edge_num = 0;
    ans = 0;
}

void AddEdge(int a, int b)
{
    edge[edge_num].a = a, edge[edge_num].b = b;
    edge[edge_num].next = first[a], first[a] = edge_num++;
}

bool BFS(void)
{
    int i, j, k;
    bool flag(0);
    int h, t;
    for (int i=0;i<=ln;i++) distx[i]=0;
    for (int i=0;i<=rn;i++) disty[i]=0;
    head = tail = 0;
    for (i = 1; i <= nx; i++)
    {
        if (cx[i] == -1) que[tail++] = i;
    }
    while (head != tail)
    {
        for (h = head, t = tail; h != t; h = (h + 1) % maxn)
        {
            i = que[h];
            for (k = first[i]; k != -1; k = edge[k].next)
            {
                j = edge[k].b;
                if (!disty[j])
                {
                    disty[j] = distx[i] + 1;
                    if (cy[j] == -1) flag = 1;
                    else
                    {
                        distx[cy[j]] = disty[j] + 1;
                        que[tail] = cy[j];
                        tail = (tail + 1) % maxn;
                    }
                }
            }
        }
        head = t;
    }
    return flag;
}

bool DFS(int i)
{
    int j, k;
    for (k = first[i]; k != -1; k = edge[k].next)
    {
        j = edge[k].b;
        if (disty[j] == distx[i] + 1)
        { // 说明j是i的后继结点.
            disty[j] = 0; // j被用过了，不能再作为其他点的后继结点了.
            if (cy[j] == -1 || DFS(cy[j]))
            {
                cx[i] = j, cy[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

void Hopcroft_Karp(void)
{
    int i, j;
    while (BFS())
    {
        for (i = 1; i <= nx; i++)
        {
            if (cx[i] == -1 && DFS(i)) ans++;
        }
    }
}

inline void add_e(int x,int y)
{
    e[++tot][0]=y;
    e[tot][1]=lv[x];
    lv[x]=tot;
}

void dfs(int x,int y,int o,int p,int fa)
{
    use[x][y]=true;
    b[x][y]=p;
    if ((x-2>=0)&&(y-2>=0)&&(!use[x-2][y-2]))
    {
        int q=0;
        if (o>0)
        {
            rn++;
            q=rn;
            if (s[x-1][y-1]!='P') add_e(p,rn);
        } else
        {
            ln++;
            q=ln;
            lv[ln]=0;
            if (s[x-1][y-1]!='P') add_e(ln,p);
        }
        dfs(x-2,y-2,-o,q,p);
    } else
    if ((x-2>=0)&&(y-2>=0)&&(use[x-2][y-2])&&(b[x-2][y-2]>0)&&(b[x-2][y-2]!=fa))
    {
        if (o>0)
        {
            if (s[x-1][y-1]!='P') add_e(p,b[x-2][y-2]);
        } else if (s[x-1][y-1]!='P') add_e(b[x-2][y-2],p);
    }

    if ((x-2>=0)&&(y+2<mm)&&(!use[x-2][y+2]))
    {
        int q=0;
        if (o>0)
        {
            rn++;
            q=rn;
            if (s[x-1][y+1]!='P') add_e(p,rn);
        } else
        {
            ln++;
            q=ln;
            lv[ln]=0;
            if (s[x-1][y+1]!='P') add_e(ln,p);
        }
        dfs(x-2,y+2,-o,q,p);
    }else
    if ((x-2>=0)&&(y+2<mm)&&(use[x-2][y+2])&&(b[x-2][y+2]>0)&&(b[x-2][y+2]!=fa))
    {
        if (o>0)
        {
            if (s[x-1][y+1]!='P') add_e(p,b[x-2][y+2]);
        } else if (s[x-1][y+1]!='P') add_e(b[x-2][y+2],p);
    }

    if ((x+2<n)&&(y+2<mm)&&(!use[x+2][y+2]))
    {
        int q=0;
        if (o>0)
        {
            rn++;
            q=rn;
            if (s[x+1][y+1]!='P') add_e(p,rn);
        } else
        {
            ln++;
            q=ln;
            lv[ln]=0;
            if (s[x+1][y+1]!='P') add_e(ln,p);
        }
        dfs(x+2,y+2,-o,q,p);
    }else
    if ((x+2<n)&&(y+2<mm)&&(use[x+2][y+2])&&(b[x+2][y+2]>0)&&(b[x+2][y+2]!=fa))
    {
        if (o>0)
        {
            if (s[x+1][y+1]!='P') add_e(p,b[x+2][y+2]);
        } else if (s[x+1][y+1]!='P') add_e(b[x+2][y+2],p);
    }

    if ((x+2<n)&&(y-2>=0)&&(!use[x+2][y-2]))
    {
        int q=0;
        if (o>0)
        {
            rn++;
            q=rn;
            if (s[x+1][y-1]!='P') add_e(p,rn);
        } else
        {
            ln++;
            q=ln;
            lv[ln]=0;
            if (s[x+1][y-1]!='P') add_e(ln,p);
        }
        dfs(x+2,y-2,-o,q,p);
    }else
    if ((x+2<n)&&(y-2>=0)&&(use[x+2][y-2])&&(b[x+2][y-2]>0)&&(b[x+2][y-2]!=fa))
    {
        if (o>0)
        {
            if (s[x+1][y-1]!='P') add_e(p,b[x+2][y-2]);
        } else if (s[x+1][y-1]!='P') add_e(b[x+2][y-2],p);
    }
}

bool check(int o)
{
    int j=lv[o];
    while (j>0)
    {
        if (!ok[e[j][0]])
        {
            ok[e[j][0]]=true;
            int p=c[e[j][0]];
            c[e[j][0]]=o;
            if ((p==0)||(check(p))) return true;
            c[e[j][0]]=p;
        }
        j=e[j][1];
    }
    return false;
}

int match()
{
    int ans=0;
    for (int i=1;i<=rn;i++) c[i]=0;
    for (int i=1;i<=ln;i++)
    {
        //memset(ok,false,sizeof(ok));
        for (int j=1;j<=rn;j++) ok[j]=false;
        if (check(i)) ans++;
    }
    return ans;
}

int work(int x,int y)
{
    ln=rn=0;
    ln=1;
    lv[1]=0;
    tot=0;
    dfs(x,y,1,1,-1);

    Init();
    nx=ln;ny=rn;
    for (int i=1;i<=ln;i++)
    {
        int j=lv[i];
        while (j>0)
        {
            AddEdge(i,e[j][0]);
            j=e[j][1];
        }
    }
    Hopcroft_Karp();

    return ln+rn-ans;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&mm);
        if (n==0) break;
        gets(s[0]);
        for (int i=0;i<n;i++) gets(s[i]);
        ans1=0;
        for (int i=0;i<n;i++) for (int j=0;j<mm;j++) {use[i][j]=false;b[i][j]=0;}
        for (int i=0;i<n;i++)
          for (int j=0;j<mm;j++)
          if (s[i][j]=='P') {use[i][j]=true;} else
          if (s[i][j]=='G')
          {
              use[i][j]=true;
              if ((i-2>=0)&&(j-2>=0)&&(s[i-1][j-1]!='P')) use[i-2][j-2]=true;
              if ((i-2>=0)&&(j+2<mm)&&(s[i-1][j+1]!='P')) use[i-2][j+2]=true;
              if ((i+2<n)&&(j-2>=0)&&(s[i+1][j-1]!='P')) use[i+2][j-2]=true;
              if ((i+2<n)&&(j+2<mm)&&(s[i+1][j+1]!='P')) use[i+2][j+2]=true;
          }
        for (int i=0;i<n;i++)
         for (int j=0;j<mm;j++)
         if (!use[i][j]) ans1+=work(i,j);
        printf("%d\n",ans1);
    }
    return 0;
}

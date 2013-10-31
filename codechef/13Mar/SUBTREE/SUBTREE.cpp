#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define N 500010
using namespace std;
struct tree_inf
{
    int dep,fa,size,num,sum;
    bool isHeavy;
} f[N];
struct segtree
{
    int l,r,v;
} tr[N*10];
struct seg_inf
{
    int fdep,len,head;
} g[N];
struct heap_inf
{
    int x,y,ca;
} heap[N];
int CommonLen[N],MaxiLen[N];
int left[N],right[N];
int v[N],e[N+N][3],que[N+N],rmq[20][N+N],a[20],first[N],b[N];
int n,tote,tot,totg,m,maxlen,minlen;

void addedge(int x,int y,int c)
{
    e[++tote][0]=y;
    e[tote][1]=c;
    e[tote][2]=v[x];
    v[x]=tote;
    e[++tote][0]=x;
    e[tote][1]=c;
    e[tote][2]=v[y];
    v[y]=tote;
}

void dfs1(int o,int dep,int fa,int sum)
{
    f[o].dep=dep;f[o].fa=fa;f[o].sum=sum;
    que[++que[0]]=o;
    first[o]=que[0];
    int j=v[o],size=1;
    while (j!=0)
    {
        if (e[j][0]!=fa)
        {
            dfs1(e[j][0],dep+1,o,sum+e[j][1]);
            size+=f[e[j][0]].size;
            que[++que[0]]=o;
        }
        j=e[j][2];
    }
    f[o].size=size;
}

void build_rmq()
{
    for (int i=1;i<=que[0];i++) rmq[0][i]=i;
    rmq[0][0]=que[0];
    int i=0;a[0]=1;
    for (int i=0;rmq[i][0]>a[i];i++)
    {
        a[i+1]=(a[i]<<1);
        for (int j=1;j+a[i]<=rmq[i][0];j++)
        {
            int k=++rmq[i+1][0];
            rmq[i+1][k]=rmq[i][j];
            if (f[que[rmq[i][j]]].dep>f[que[rmq[i][j+a[i]]]].dep) rmq[i+1][k]=rmq[i][j+a[i]];
        }
    }
}

void insert(int o,int l,int r,int pos,int val)
{
    if (l==r) {tr[o].v=val;return;}
    tr[o].v=tr[o].v<val?tr[o].v:val;
    int mid=(l+r)/2;
    if (pos<=mid)
    {
        if (tr[o].l==0)
        {
            tr[o].l=++tot;
            tr[tot].l=tr[tot].r=0;
            tr[tot].v=1e9;
        }
        insert(tr[o].l,l,mid,pos,val);
    }
    else
    {
        if (tr[o].r==0)
        {
            tr[o].r=++tot;
            tr[tot].l=tr[tot].r=0;
            tr[tot].v=1e9;
        }
        insert(tr[o].r,mid+1,r,pos,val);
    }
}

int find(int o,int l,int r,int p,int q)
{
    if ((p<=l)&&(r<=q)) return tr[o].v;
    int mid=(l+r)/2;
    int ans=1e9;
    if (p<=mid) ans=find(tr[o].l,l,mid,p,q);
    if (mid<q)
    {
        int tmp=find(tr[o].r,mid+1,r,p,q);
        if (tmp<ans) ans=tmp;
    }
    return ans;
}

int find_tr(int o,int p)
{
    int ans=1e9;
    if (o==p) return -1;
    while (o!=p)
    {
        if (!f[o].isHeavy)
        {
            ans=ans<f[o].num?ans:f[o].num;
            o=f[o].fa;
        } else
        {
            int x,y,z;z=g[f[o].num].fdep;
            if (f[z].dep>=f[p].dep) x=1; else x=f[p].dep-f[z].dep+1;
            if (f[z].dep+g[f[o].num].len>=f[o].dep) y=f[o].dep-f[z].dep; else y=g[f[o].num].len;
            int min=find(g[f[o].num].head,1,g[f[o].num].len,x,y);
            ans=ans<min?ans:min;
            if (f[z].dep>=f[p].dep) o=z; else o=p;
        }
    }
    return ans;
}

int tmpq[N];
void build_tr(int o,bool newtr)
{
    if (newtr) {tmpq[0]=1;tmpq[1]=o;}
    else tmpq[++tmpq[0]]=o;
    int size=0,p=-1,j=v[o],u=0;
    while (j>0)
    {
        if (e[j][0]!=f[o].fa)
        {
            if (f[e[j][0]].size>size)
            {
                size=f[e[j][0]].size;
                p=e[j][0];u++;
            }
        }
        j=e[j][2];
    }
    if ((p==-1)&&(f[tmpq[tmpq[0]]].size>0))
    {
        g[++totg].fdep=tmpq[1];
        g[totg].len=tmpq[0]-1;
        g[totg].head=++tot;
        tr[tot].l=tr[tot].v=0;
        tr[tot].v=1e9;
        int tmp=tot;
        for (int i=2;i<=tmpq[0];i++)
        {
            int k=tmpq[i];
            f[k].isHeavy=true;
            f[k].num=totg;
            insert(tmp,1,g[totg].len,i-1,f[k].sum-f[f[k].fa].sum);
        }
    } else
    //if (f[tmpq[tmpq[0]]].size>1)
    {
        build_tr(p,false);
        j=v[o];
        while (j>0)
        {
            if ((e[j][0]!=f[o].fa)&&(e[j][0]!=p))
            {
                f[e[j][0]].num=e[j][1];
                //tmpq[0]=0;
                build_tr(e[j][0],true);
            }
            j=e[j][2];
        }
    }
}

bool cmp(int a,int b) {return first[a]<first[b];}

int find_lca(int x,int y)
{
    int j=0;
    if (y<x) {int tmp=x;x=y;y=tmp;}
    while (a[j]+a[j]<y-x+1) j++;
    return f[que[rmq[j][x]]].dep<f[que[rmq[j][y-a[j]+1]]].dep?rmq[j][x]:rmq[j][y-a[j]+1];
}

int toth;
void up(int o)
{
    if (o==1) return;
    int p=(o>>1);
    if (f[que[heap[o].ca]].dep>f[que[heap[p].ca]].dep)
    {
        heap_inf tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        left[heap[o].x]=o;left[heap[p].x]=p;
        right[heap[o].y]=o;right[heap[p].y]=p;
        up(p);
    }
}

void down(int o)
{
    if ((o<<1)>toth) return;
    int p=(o<<1);
    if ((p+1<=toth)&&(f[que[heap[p+1].ca]].dep>f[que[heap[p].ca]].dep)) p++;
    if (f[que[heap[p].ca]].dep>f[que[heap[o].ca]].dep)
    {
        heap_inf tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        left[heap[o].x]=o;left[heap[p].x]=p;
        right[heap[o].y]=o;right[heap[p].y]=p;
        down(p);
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    tote=0;que[0]=0;
    f[0].dep=0;

    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        addedge(x,y,c);
    }
    dfs1(1,1,-1,0);
    build_rmq();
    build_tr(1,true);
    int q;scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            CommonLen[first[b[i]]=-1;
            MaxiLen[first[b[i]]]=0;
        }
        sort(b,b+m,cmp);
        maxlen=0;minlen=-1;
        bool isMore;int tmpmin;
        for (int i=1;i<m;i++)
        {
            heap[i].x=first[b[i-1]];
            heap[i].y=first[b[i]];
            left[heap[i].x]=i;
            right[heap[i].y]=i;
            heap[i].ca=find_lca(heap[i].x,heap[i].y);
            toth=i;
            up(i);
        }
        for (int i=1;i<m;i++)
        {
            heap_inf tmph=heap[1];
            int XtoCa=find_tr(que[tmph.x],que[tmph.ca]);
            if ((XtoCa<0)||((CommonLen[tmph.x]>0)&&(CommonLen[tmph.x]<XtoCa))) XtoCa=CommonLen[tmph.x];
            int YtoCa=find_tr(que[tmph.y],que[tmph.ca]);
            if ((YtoCa<0)||((CommonLen[tmph.y]>0)&&(CommonLen[tmph.y]<YtoCa))) YtoCa=CommonLen[tmph.y];

        }

        printf("%d %d\n",maxlen,minlen);
    }
    return 0;
}

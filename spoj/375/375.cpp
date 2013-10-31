#include<stdio.h>
int e[210000][6],edge[110000][7],v[110000][3],size[110000],dfsq[220000],t[1000000][3]
    ,tr[110000][3],lev[110000],link[110000],lca[20][110000],first[110000];
char s[200];
int n,tot,etot,ttot;

int max(int o,int p) {return o>p?o:p;}

void work_l(int o,int p)
{
    while (v[o][1]>=0)
    {
        int j=v[o][1];
        edge[e[j][2]][4]=p;
        link[++link[0]]=j;
        e[j][5]=link[0];
        o=e[j][0];
    }
}

void build(int o,int l,int r)
{
    if (l==r) {t[o][2]=l;return;}
    int mid=(l+r)/2;

    if (t[o][0]==0)
    {
        tot++;
        t[o][0]=tot;
        t[tot][0]=t[tot][1]=t[tot][2]=0;
    }
    build(t[o][0],l,mid);

    if (t[o][1]==0)
    {
        tot++;
        t[o][1]=tot;
        t[tot][0]=t[tot][1]=t[tot][2]=0;
    }
    build(t[o][1],mid+1,r);
    t[o][2]=e[link[t[t[o][0]][2]]][1]>e[link[t[t[o][1]][2]]][1]?t[t[o][0]][2]:t[t[o][1]][2];
}

void dfs(int o,int fa,int ol)
{
    dfsq[++dfsq[0]]=o;
    first[o]=dfsq[0];
    lev[o]=ol;
    int j=v[o][0],bn=-1;
    size[o]=0;
    while (j!=0)
    {
        if (e[j][0]!=fa)
        {
            dfs(e[j][0],o,ol+1);
            dfsq[++dfsq[0]]=o;
            size[o]+=size[e[j][0]];
            if ((bn<0)||(size[e[j][0]]>size[bn])) {bn=e[j][0];}
        } else v[o][2]=j;
        j=e[j][3];
    }

    if (bn==-1) {v[o][1]=-1;}
    else
    {
        j=v[o][0];
        while (j!=0)
        {
            if (e[j][0]!=fa)
              if (e[j][0]!=bn)
                {
                    if (v[e[j][0]][1]!=-1) {
                    int l=link[0]+1;
                    work_l(e[j][0],ttot);
                    int r=link[0];
                    tot++;
                    tr[ttot][0]=tot;
                    tr[ttot][1]=l;
                    tr[ttot][2]=r;
                    t[tot][0]=t[tot][1]=t[tot][2]=0;
                    build(tr[ttot][0],l,r);
                    ttot++;}
                }
               else
               {
                   v[o][1]=j;
                   edge[e[j][2]][3]=1;
               }
            j=e[j][3];
        }
    }
    if (o==1)
    {
        int l=link[0]+1;
        work_l(o,ttot);
        int r=link[0];
        tot++;
        tr[ttot][0]=tot;
        tr[ttot][1]=l;
        tr[ttot][2]=r;
        t[tot][0]=t[tot][1]=t[tot][2]=0;
        build(tr[ttot][0],l,r);
        ttot++;
    }
}

void change(int o,int l,int r,int p)
{
    if (l==r) return;
    int mid=(l+r)/2;
    if (p<=mid) {change(t[o][0],l,mid,p);}
    else {change(t[o][1],mid+1,r,p);}
    t[o][2]=e[link[t[t[o][0]][2]]][1]>e[link[t[t[o][1]][2]]][1]?t[t[o][0]][2]:t[t[o][1]][2];
}

int rmq(int o,int p)
{
    if (o>p) {int q=o;o=p;p=q;}
    int k=0,j=1;
    while (j*2<=p-o+1) {j*=2;k++;}
    return lev[lca[k][o]]<lev[lca[k][p-j+1]]?lca[k][o]:lca[k][p-j+1];
}

int find_max(int o,int l,int r,int p,int q)
{
    if ((p<=l)&&(r<=q)) return e[link[t[o][2]]][1];
    int mid=(l+r)/2;
    int u=0;
    if (p<=mid) u=find_max(t[o][0],l,mid,p,q);
    if (mid<q) u=max(u,find_max(t[o][1],mid+1,r,p,q));
    return u;
}

int find(int o,int d)
{
    if (o==d) return 0;
    if (edge[e[v[o][2]][2]][3]<0) return max(e[v[o][2]][1],find(e[v[o][2]][0],d));
    int old=e[link[tr[edge[e[v[o][2]][2]][4]][1]]][2];
    old=lev[edge[old][0]]<lev[edge[old][1]] ? edge[old][0] : edge[old][1];
    if (lev[old]<lev[d])
    {
        int p=lev[d]-lev[old]+tr[edge[e[v[o][2]][2]][4]][1]
           ,q=lev[o]-lev[old]+tr[edge[e[v[o][2]][2]][4]][1]-1;
        return find_max(tr[edge[e[v[o][2]][2]][4]][0],tr[edge[e[v[o][2]][2]][4]][1],tr[edge[e[v[o][2]][2]][4]][2],p,q);
    } else
    {
        int p=lev[o]-lev[old]+tr[edge[e[v[o][2]][2]][4]][1]-1;
        return max(find_max(tr[edge[e[v[o][2]][2]][4]][0],tr[edge[e[v[o][2]][2]][4]][1],tr[edge[e[v[o][2]][2]][4]][2],tr[edge[e[v[o][2]][2]][4]][1],p)
                ,find(old,d));
    }
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d",&n);
        if (n==1)
        {
            scanf("%s",&s);
            while (s[0]!='D')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("0\n");
                scanf("%s",&s);
            }
            continue;
        }
        for (int i=1;i<=n;i++) {v[i][0]=0;first[i]=-1;}
        tot=ttot=etot=0;
        link[0]=0;
        for (int i=1;i<n;i++)
        {
            first[i]=-1;
            scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
            edge[i][3]=-1;
            etot++;
            e[etot][0]=edge[i][1];
            e[etot][1]=edge[i][2];
            e[etot][2]=i;
            e[etot][3]=v[edge[i][0]][0];
            v[edge[i][0]][0]=etot;
            edge[i][5]=etot;
            e[etot][5]=-1;

            etot++;
            e[etot][0]=edge[i][0];
            e[etot][1]=edge[i][2];
            e[etot][2]=i;
            e[etot][3]=v[edge[i][1]][0];
            v[edge[i][1]][0]=etot;
            edge[i][6]=etot;
            e[etot][5]=-1;
        }
        dfsq[0]=0;
        dfs(1,0,1);

        for (int i=0;i<=dfsq[0];i++) lca[0][i]=dfsq[i];
        int j=1,k=0;
        while (lca[k][0]>=1+j)
        {
            k++;
            lca[k][0]=0;
            for (int i=1;i+j<=lca[k-1][0];i++)
                lca[k][++lca[k][0]]=lev[lca[k-1][i]]<lev[lca[k-1][i+j]] ? lca[k-1][i] : lca[k-1][i+j];
            j*=2;
        }
        scanf("%s",&s);
        while (s[0]!='D')
        {
            if (s[0]=='C')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                edge[x][2]=y;
                e[edge[x][5]][1]=y;
                e[edge[x][6]][1]=y;
                if (edge[x][3]==1)
                {
                    int u=edge[x][5],v=edge[x][6];
                    if (e[u][5]==-1) u=v;
                    change(tr[edge[x][4]][0],tr[edge[x][4]][1],tr[edge[x][4]][2],e[u][5]);
                }
            } else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int fa=rmq(first[x],first[y]);
                printf("%d\n",max(find(x,fa),find(y,fa)));
            }
            scanf("%s",&s);
        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
struct node
{
    int l,r,v;
} tr[4][2000000];
int tot[4],c[2][500000],r[2][500000],cs[500000],rs[500000];
int n,q;
char s[50];

void insert(node tr[],int z,int o,int l,int r,int pos,int v)
{
    tr[o].v+=v;
    if (l==r) {return;}
    int mid=(l+r)/2;
    if (pos<=mid)
    {
        if (tr[o].l==0)
        {
            tr[o].l=++tot[z];
            tr[tot[z]].l=tr[tot[z]].r=tr[tot[z]].v=0;
        }
        insert(tr,z,tr[o].l,l,mid,pos,v);
    } else
    {
        if (tr[o].r==0)
        {
            tr[o].r=++tot[z];
            tr[tot[z]].l=tr[tot[z]].r=tr[tot[z]].v=0;
        }
        insert(tr,z,tr[o].r,mid+1,r,pos,v);
    }
}

int find(node tr[],int z,int o,int l,int r,int pos)
{
    if (pos<=l) return tr[o].v;
    int mid=(l+r)/2,ans=0;
    if (pos<=mid)
    {
        if (tr[o].l!=0) ans+=find(tr,z,tr[o].l,l,mid,pos);
        if (tr[o].r!=0) ans+=tr[tr[o].r].v;
    } else if (tr[o].r!=0) ans+=find(tr,z,tr[o].r,mid+1,r,pos);
    return ans;
}

int main()
{
    for (int i=0;i<4;i++)
    {
        tot[i]=1;
        tr[i][1].l=tr[i][1].r=tr[i][1].v=0;
    }

    scanf("%d%d",&n,&q);
    insert(tr[0],0,1,0,q,0,n);
    insert(tr[2],2,1,0,q,0,n);
    for (int t=1;t<=q;t++)
    {
        scanf("%s",s);
        if ((s[0]=='R')&&(s[strlen(s)-1]=='t'))
        {
            int x,y;scanf("%d%d",&x,&y);x--;
            int z=0;if (rs[x]==1) z=1;
            insert(tr[z],z,1,0,q,r[rs[x]][x],-1);
            z=0;if (y==1) z=1;
            insert(tr[z],z,1,0,q,t,1);
            rs[x]=y;
            r[y][x]=t;
        }
        if ((s[0]=='R')&&(s[strlen(s)-1]=='y'))
        {
            int x;scanf("%d",&x);x--;
            if (rs[x]==0) printf("%d\n",n-find(tr[3],3,1,0,q,r[0][x]));
            else printf("%d\n",find(tr[2],2,1,0,q,r[1][x]));
        }
        if ((s[0]=='C')&&(s[strlen(s)-1]=='t'))
        {
            int x,y;scanf("%d%d",&x,&y);x--;
            int z=2;if (cs[x]==1) z=3;
            insert(tr[z],z,1,0,q,c[cs[x]][x],-1);
            z=2;if (y==1) z=3;
            insert(tr[z],z,1,0,q,t,1);
            cs[x]=y;
            c[y][x]=t;
        }
        if ((s[0]=='C')&&(s[strlen(s)-1]=='y'))
        {
            int x;scanf("%d",&x);x--;
            if (cs[x]==0) printf("%d\n",n-find(tr[1],1,1,0,q,c[0][x]));
            else printf("%d\n",find(tr[0],0,1,0,q,c[1][x]));
        }
    }
    return 0;
}

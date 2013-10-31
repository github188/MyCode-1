#include<stdio.h>

struct point
{
    int no,val;
};
int n,k,tot;
int tr[4000000][3],path[100000][35],a[100000],b[100000],pos[100000],ans[400001],pr[31];
bool use[100000][35];
point heap[100001];

void insert(int o,int p,int i)
{
    path[i][0]++;
    path[i][path[i][0]]=o;
    use[i][path[i][0]]=false;
    if (p==-1)
    {
        tr[o][2]++;
        b[i]=1;
        return;
    }

    int q=(a[i]&(pr[p]));
    if (q>0) q=1;
    if (tr[o][q]==0)
    {
        tot++;
        tr[o][q]=tot;
        tr[tot][0]=tr[tot][1]=tr[tot][2]=0;
    }
    insert(tr[o][q],p-1,i);
}

void find(int o,int p,int i)
{
    path[i][path[i][0]-p-1]=o;
    use[i][path[i][0]-p-1]=false;
    if (p==-1)
    {
        b[i]=1;
        return;
    }
    int s,t;s=-1;
    if (tr[o][0]!=0)
    {
        t=0;
        s=heap[pos[i]].val;
    }
    if ((tr[o][1]!=0)&&((s==-1)||(s>(heap[pos[i]].val^(pr[p])))))
    {
        t=1;
        s=(heap[pos[i]].val^(pr[p]));
    }
    heap[pos[i]].val=s;
    find(tr[o][t],p-1,i);
}

void raise(int o)
{
    int p=path[o][path[o][0]];
    if (tr[p][2]>b[o]) {b[o]++;return;}
    int k=path[o][0]-1;
    while ((use[o][k])||(tr[path[o][k]][0]*tr[path[o][k]][1]==0))
    {
        if ((heap[pos[o]].val&(pr[(path[o][0]-1-k)]))!=0)heap[pos[o]].val^=(pr[(path[o][0]-1-k)]);
        if ((a[o]&pr[(path[o][0]-1-k)])!=0) heap[pos[o]].val^=(pr[(path[o][0]-1-k)]);
        k--;
        if (k<=0) break;
    }
    if (k<=0)
    {

        heap[pos[o]].val=(1<<31)-1;
        return;
    }
    use[o][k]=true;
    heap[pos[o]].val^=pr[(path[o][0]-1-k)];
    p=0;
    if (path[o][k+1]==tr[path[o][k]][0]) p=1;

    //find(tr[path[o][k]][p],path[o][0]-k-2,o);
    int ii=o,oo=tr[path[o][k]][p],pp=path[o][0]-k-2;
    {
        int i=ii,o=oo,p=pp;
        while (true)
        {
            path[i][path[i][0]-p-1]=o;
            use[i][path[i][0]-p-1]=false;
            if (p==-1)
            {
              b[i]=1;
              break;
            }
            int s,t;s=-1;
            if (tr[o][0]!=0)
            {
               t=0;
               s=heap[pos[i]].val;
            }
            if ((tr[o][1]!=0)&&((s==-1)||(s>(heap[pos[i]].val^(pr[p])))))
            {
              t=1;
              s=(heap[pos[i]].val^(pr[p]));
            }
            heap[pos[i]].val=s;
            o=tr[o][t];p--;
        }
    }
}

void up(int o)
{
    if (o==1) return;
    int p=(o>>1);
    if (heap[o].val<heap[p].val)
    {
        point k=heap[o];
        heap[o]=heap[p];
        heap[p]=k;
        pos[heap[o].no]=o;
        pos[heap[p].no]=p;
        up(p);
    }
}

void down(int o)
{
    int p=(o<<1);
    if (p>n) return;
    if ((p+1<=n)&&(heap[p].val>heap[p+1].val)) {p++;}
    if (heap[o].val>heap[p].val)
    {
        point k=heap[o];
        heap[o]=heap[p];
        heap[p]=k;
        pos[heap[o].no]=o;
        pos[heap[p].no]=p;
        down(p);
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("11.txt","w",stdout);
    for (int i=0;i<31;i++) pr[i]=(1<<i);
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        insert(0,30,i);
        heap[i+1].no=i;
        heap[i+1].val=0;
        pos[i]=i+1;
    }

    for (int i=0;i<n;i++)
    {
        raise(i);
        down(pos[i]);
    }
    int ml=n*(n-1)/2;
    for (int i=0;i<k;i++)
    {
        printf("%d",heap[1].val);
        if (i+1==ml)
        {
            printf("\n");
            break;
        } else
        {
            printf(" ");
        }
        raise(heap[1].no);
        down(1);

        raise(heap[1].no);
        down(1);
    }

    return 0;
}

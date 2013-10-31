#include<stdio.h>
#include<string.h>

struct point
{
    int no,val;
};
int n,k,tot;
int tr[3500000][3],path[100000][33],a[100000],b[100000],pos[100000],pr[31],st[100000][35],cl[31],ul[31];
bool use[100000][33];
point heap[100001];
char s[10000000],t[50];

inline void insert(int o,int p,int i)
{
while (true)
{
    path[i][0]++;
    path[i][path[i][0]]=o;
    use[i][path[i][0]]=false;
    if (p==-1)
    {
        tr[o][2]++;
        b[i]=tr[o][2];
        return;
    }

    int q=(a[i]&(pr[p]));
    if (q>0) q=1;
    if (tr[o][q]==0)
    {
        tot++;
        tr[o][q]=tot;
    }
      o=tr[o][q];p--;
}
}

inline void raise(int o)
{
    int p=path[o][32];
    if (tr[p][2]>b[o]) {b[o]++;return;}
    int k=st[o][st[o][0]];
    st[o][0]--;
    if (k<=0)
    {
            heap[pos[o]].val=(1<<31)-1;
            return;
    }

    heap[pos[o]].val^=pr[(31-k)];
    heap[pos[o]].val&=cl[31-k];
    heap[pos[o]].val|=(a[o]&ul[31-k]);
    p=0;
    if (path[o][k+1]==tr[path[o][k]][0]) p=1;

    int ii=o,oo=tr[path[o][k]][p],pp=30-k;
    {
        int i=ii,o=oo,p=pp;
        while (true)
        {
            path[i][31-p]=o;
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
            if (tr[o][t^1]!=0)
            {
                st[i][0]++;
                st[i][st[i][0]]=31-p;
            }
            heap[pos[i]].val=s;
            o=tr[o][t];p--;
        }
    }
}

inline void down(int o)
{
    while (true)
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
        o=p;
    } else {return;}
    }
}

inline void build(int o)
{
    st[o][0]=0;
    for (int i=1;i<path[o][0];i++)
    if ((tr[path[o][i]][0]!=0)&&(tr[path[o][i]][1]!=0)&&(tr[path[o][i]][0]==path[o][i+1]))
    {
        st[o][0]++;
        st[o][st[o][0]]=i;
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("11.txt","w",stdout);
    for (int i=0;i<31;i++) pr[i]=(1<<i);
    cl[30]=pr[30];
    for (int i=29;i>=0;i--) cl[i]=cl[i+1]+pr[i];
    ul[0]=pr[0];
    for (int i=1;i<=30;i++) ul[i]=ul[i-1]+pr[i];
    scanf("%d%d",&n,&k);gets(t);
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
        build(i);
{   int o=i;
    int p=path[o][32];
    if (tr[p][2]>b[o]) {b[o]++;} else {
    int k=st[o][st[o][0]];
    st[o][0]--;
    if (k<=0)
    {
            heap[pos[o]].val=(1<<31)-1;

    } else {

    heap[pos[o]].val^=pr[(31-k)];
    heap[pos[o]].val&=cl[31-k];
    heap[pos[o]].val|=(a[o]&ul[31-k]);
    p=0;
    if (path[o][k+1]==tr[path[o][k]][0]) p=1;

    int ii=o,oo=tr[path[o][k]][p],pp=30-k;
    {
        int i=ii,o=oo,p=pp;
        while (true)
        {
            path[i][31-p]=o;
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
            if (tr[o][t^1]!=0)
            {
                st[i][0]++;
                st[i][st[i][0]]=31-p;
            }
            heap[pos[i]].val=s;
            o=tr[o][t];p--;
        }
    }
}}}
        down(pos[i]);
    }
    int h=0;
    for (int i=0;i<k;i++)
    {
        //printf("%d",heap[1].val);

        int u=(heap[1].val);
        if (u==0)
        {
            s[h]='0';h++;
        } else
        {
            int m=h;
            while (u!=0)
            {
                s[h]=(u%10)+'0';
                u/=10;
                h++;
            }
            int t=h-1;
            while (m<t)
            {
                char tmp=s[m];s[m]=s[t];s[t]=tmp;
                m++;t--;
            }
        }
        if (i+1==k)
        {
            s[h]='\n';
            h++;
            //printf("\n");
            break;
        } else
        {
            s[h]=' ';
            h++;
            //printf(" ");
        }
        if (heap[1].val!=(1<<31)-1)
        {
           //raise(heap[1].no);
           {int o=heap[1].no;
    int p=path[o][32];
    if (tr[p][2]>b[o]) {b[o]++;} else {
    int k=st[o][st[o][0]];
    st[o][0]--;
    if (k<=0)
    {
            heap[pos[o]].val=(1<<31)-1;

    } else {

    heap[pos[o]].val^=pr[(31-k)];
    heap[pos[o]].val&=cl[31-k];
    heap[pos[o]].val|=(a[o]&ul[31-k]);
    p=0;
    if (path[o][k+1]==tr[path[o][k]][0]) p=1;

    int ii=o,oo=tr[path[o][k]][p],pp=30-k;
    {
        int i=ii,o=oo,p=pp;
        while (true)
        {
            path[i][31-p]=o;
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
            if (tr[o][t^1]!=0)
            {
                st[i][0]++;
                st[i][st[i][0]]=31-p;
            }
            heap[pos[i]].val=s;
            o=tr[o][t];p--;
        }
    }
}}}
           down(1);
        }
    }
    printf("%s",s);

    return 0;
}

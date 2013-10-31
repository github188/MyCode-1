#include<string.h>
#include<stdio.h>
#define MAX_NODE 600000
using namespace std;
char s[510][210],st[1000010];
int sl[510];
bool virus[510];
int tot,kl;
struct node
{
    int lchild,rchild,num,pre;
    char ch;
} trie[MAX_NODE];

inline int trie_new(char ch)
{
    int tmp=tot;tot++;
    trie[tmp].lchild=trie[tmp].rchild=trie[tmp].num=0;
    trie[tmp].pre=0;
    trie[tmp].ch=ch;
    return tmp;
}

void trie_insert(int index,int o,int pos)
{
    if (pos>=sl[index])
    {
        //trie[o].num++;
        trie[o].num=index+1;
        return;
    }
    int next=trie[o].lchild;
    if (next==0) trie[o].lchild=next=trie_new(s[index][pos]);
    int pre=0;
    while ((next!=0)&&(trie[next].ch!=s[index][pos])) {pre=next;next=trie[next].rchild;}
    if (next==0) trie[pre].rchild=next=trie_new(s[index][pos]);
    trie_insert(index,next,pos+1);
}

int queue[2][MAX_NODE],q_size[2];

inline void find_trie(int o,int p)
{
    while (true){
    int j=trie[o].lchild,k=-1;
    while (j!=0)
    {
        if (trie[j].ch==trie[p].ch)
        {
            k=j;
            break;
        }
        j=trie[j].rchild;
    }
    if (k<0)
    {
        if (o==0)
        {
            trie[p].pre=0;
            //return;
            break;
        }
        o=trie[o].pre;
        continue;
    }
    trie[p].pre=k;break;}
    //trie[p].num+=trie[k].num;
}

inline void bfs_trie()
{
    int j=trie[0].lchild;
    q_size[0]=0;
    while (j!=0)
    {
        queue[0][q_size[0]++]=j;
        j=trie[j].rchild;
    }

    int l=0;
    while (q_size[l]>0)
    {
        int k=l;l^=1;
        q_size[l]=0;
        for (int i=0;i<q_size[k];i++)
        {
            j=trie[queue[k][i]].lchild;
            while (j!=0)
            {
                queue[l][q_size[l]++]=j;
                find_trie(trie[queue[k][i]].pre,j);
                j=trie[j].rchild;
            }
        }
    }
}

inline void work(int o,int p)//,int &ans)
{
    int q=-2,f=0;
    while (true) {
    if (q!=p)
    {
        q=p;
        int j=o;
        while (j>0)
        {
            if ((trie[j].num>0)&&(!virus[trie[j].num]))
            {
                virus[trie[j].num]=true;
                f++;
            }
            if (f==3) return;
            j=trie[j].pre;
        }
    }
    if (p+1>=kl) return;
    int j=trie[o].lchild;
    int k=-1;
    while (j!=0)
    {
        if (trie[j].ch==st[p+1]) {k=j;break;}
        j=trie[j].rchild;
    }
    if (k==-1)
    {
        if (o==0)
        {
            p++;
            continue;
        }
        o=trie[o].pre;
        continue;
    }
    o=k;p++;
    }
}

int main()
{
    int tt=1;
        int n;
    //scanf("%d",&tt);
    while (scanf("%d\n",&n)!=EOF)
    {
        //scanf("%d\n",&n);
        for (int i=0;i<n;i++)
        {
            gets(s[i]);
            //int k=strlen(s[i])-1;
            //while (s[i][k]==' ') k--;
            //s[i][k+1]=0;
            sl[i]=strlen(s[i]);
        }
        //sort(index,index+n,cmp);
        tot=0;
        trie_new('*');
        for (int i=0;i<n;i++) trie_insert(i,0,0);
        bfs_trie();

        int m=0,total=0;
        scanf("%d\n",&m);
        for (int i=1;i<=m;i++)
        {
            gets(st);
            //int k=strlen(st)-1;
            //while (st[k]==' ') k--;
            //st[k+1]=0;
            kl=strlen(st);
            int ans[4];ans[0]=0;
            //work(0,-1);
            for (int j=1;j<=n;j++)
            if (virus[j]) {ans[++ans[0]]=j;virus[j]=false;}
            if (ans[0]>0)
            {
                total++;
                printf("web %d:",i);
                for (int j=1;j<=ans[0];j++) printf(" %d",ans[j]);
                printf("\n");
            }
        }
        printf("total: %d\n",total);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<malloc.h>
using namespace std;
struct node
{
    int next[2];
    int pre,end,no;
} trie[61000];
char s[1024][61000];
int n,tot,m;
bool f[1024][61000];
int asize[2];
struct nq
{
    int s,v;
} a[2][2000000];

inline int new_trie()
{
    for (int i=0;i<2;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

inline void insert_trie(int o,int p,char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-'0']==0) trie[o].next[s[p]-'0']=new_trie();
        o=trie[o].next[s[p++]-'0'];
        if (p==len)
        {
            if (i<n) trie[o].no|=(1<<i);
            else trie[o].end++;
        }
    }
}

int queue[2][60000],size[2];
inline void bfs_trie()
{
    size[0]=0;
    for (int i=0;i<2;i++)
      if (trie[0].next[i]>0) queue[0][size[0]++]=trie[0].next[i];

    int l=0;
    while (size[l]>0)
    {
        int k=l;l^=1;size[l]=0;
        for (int i=0;i<size[k];i++)
          for (int j=0;j<2;j++)
          if (trie[queue[k][i]].next[j]>0)
          {
              int h=trie[queue[k][i]].pre;
              while (h!=0)
              {
                  if (trie[h].next[j]>0) break;
                  h=trie[h].pre;
              }
              if (trie[h].next[j]>0)
              {
                  trie[trie[queue[k][i]].next[j]].pre=trie[h].next[j];
                  trie[trie[queue[k][i]].next[j]].end+=trie[trie[h].next[j]].end;
                  trie[trie[queue[k][i]].next[j]].no|=trie[trie[h].next[j]].no;
              }
              queue[l][size[l]++]=trie[queue[k][i]].next[j];
          }
          else
          {
              int h=trie[queue[k][i]].pre;
              while (h!=0)
              {
                  if (trie[h].next[j]>0) break;
                  h=trie[h].pre;
              }
              if (trie[h].next[j]>0) trie[queue[k][i]].next[j]=trie[h].next[j];
          }
    }
}

char st[50000];

int main()
{
    int tt=0;
    while (true)
    {
        tt++;
        scanf("%d%d",&n,&m);
        if (n>0)
        {
            gets(st);
        }
        else break;
        tot=0;
        new_trie();
        for (int i=0;i<n;i++)
        {
            gets(s[i]);
            //s[i]=(char*)malloc(sizeof(char)*strlen(st));
            //int ff=strlen(s[i]);
            //for (int j=0;j<=strlen(st);j++) s[i][j]=st[j];
            insert_trie(0,0,s[i],i);
        }
        for (int i=0;i<m;i++)
        {
            gets(s[i+n]);
            //s[i+n]=(char*)malloc(sizeof(char)*strlen(st));
            //for (int j=0;j<=strlen(st);j++) s[i+n][j]=st[j];
            insert_trie(0,0,s[i+n],i+n);
        }
        bfs_trie();
        for (int i=0;i<(1<<n);i++) for (int j=0;j<tot;j++) f[i][j]=false;
        f[0][0]=true;
        asize[0]=1;
        a[0][0].s=a[0][0].v=0;
        int l=0,ans=-1,standard=(1<<n)-1;
        int an1=0;
        while (asize[l]>0)
        {
            int k=l;l^=1;asize[l]=0;
            an1++;
            for (int i=0;i<asize[k];i++)
            {
                for (int j=0;j<2;j++)
                if (trie[trie[a[k][i].s].next[j]].end==0)
                {
                    nq tmp=a[k][i];
                    tmp.s=trie[a[k][i].s].next[j];
                    tmp.v|=trie[trie[a[k][i].s].next[j]].no;
                    if (!f[tmp.v][trie[a[k][i].s].next[j]])
                    {
                        f[tmp.v][trie[a[k][i].s].next[j]]=true;
                        if (tmp.v==standard) ans=an1;
                        a[l][asize[l]++]=tmp;
                    }
                }
                if (ans>-1) break;
            }
            if (ans>-1) break;
        }

        printf("%d\n",ans);
    }
    return 0;
}

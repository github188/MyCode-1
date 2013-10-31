#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[27];
    int pre,end,no;
} trie[100000];
int ans[1000];
char s[1000][60],st[2000000];
int n,tot;

int new_trie()
{
    for (int i=0;i<27;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

void insert_trie(int o,int p,char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-'A']==0) trie[o].next[s[p]-'A']=new_trie();
        o=trie[o].next[s[p++]-'A'];
        if (p==len)
        {
            trie[o].end=1;
            trie[o].no=i+1;
        }
    }
}

int queue[2][60000],size[2];
void bfs_trie()
{
    size[0]=0;
    for (int i=0;i<26;i++)
      if (trie[0].next[i]>0) queue[0][size[0]++]=trie[0].next[i];

    int l=0;
    while (size[l]>0)
    {
        int k=l;l^=1;size[l]=0;
        for (int i=0;i<size[k];i++)
          for (int j=0;j<26;j++)
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
              }
              queue[l][size[l]++]=trie[queue[k][i]].next[j];
          }
    }
}

void work(int o,int p,char s[])
{
    int len=strlen(s);
    while (p<=len)
    {
        if (trie[o].end>0)
        {
            int h=o;
            while (h>0)
            {
                if (trie[h].no>0) {ans[trie[h].no-1]++;}
                h=trie[h].pre;
            }
        }
        if (p==len) break;
        if ((s[p]<'A')||(s[p]>'Z'))
        {
            o=0;p++;
            continue;
        }
        if (trie[o].next[s[p]-'A']==0)
        {
            while ((o>0)&&(trie[o].next[s[p]-'A']==0)) o=trie[o].pre;
            if (trie[o].next[s[p]-'A']==0)
            {
                o=0;p++;
                continue;
            }
        }
        o=trie[o].next[s[p++]-'A'];
    }
}

int main()
{
    while (scanf("%d\n",&n)!=EOF) {
    tot=0;
    new_trie();
    for (int i=0;i<n;i++)
    {
        gets(s[i]);
        insert_trie(0,0,s[i],i);
        ans[i]=0;
    }
    bfs_trie();
    gets(st);
    work(0,0,st);
    for (int i=0;i<n;i++) if (ans[i]>0) printf("%s: %d\n",s[i],ans[i]);}
    return 0;
}

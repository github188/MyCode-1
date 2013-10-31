#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[26];
    int pre,end,no,type;
} trie[610000];
char s[100010][6],st[100010];
int ans[100010],type[100010],last[100010],len_s[100010],num[2][600010],f[100010];
int n,tot;

inline int new_trie()
{
    memset(trie[tot].next,0,sizeof(trie[tot].next));
    trie[tot].pre=trie[tot].end=0;
    trie[tot].no=-1;
   // v[tot]=-1;
   num[0][tot]=num[1][tot]=0;
    int tmp=tot;tot++;
    return tmp;
}

inline void insert_trie(int o,int p,char s[],int i)
{
    int len=len_s[i];
    while (p<len)
    {
        if (trie[o].next[s[p]-'a']==0) trie[o].next[s[p]-'a']=new_trie();
        o=trie[o].next[s[p++]-'a'];
        if (p==len)
        {
            trie[o].end++;
            if (type[i]==1) trie[o].no=i;
            f[i]=o;
        }
    }
}

int queue[2][600000],size[2];
inline void bfs_trie()
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

inline void work(int o,int p,char s[])
{
    int len=strlen(s);
    while (p<=len)
    {
        if (trie[o].end>0)
        {
            int h=o;
            while (h>0)
            {
                if (trie[h].end==0) break;
                num[0][h]++;
                if (trie[h].no>-1)
                if (p-last[trie[h].no]>=len_s[trie[h].no])
                {
                    last[trie[h].no]=p;
                    num[1][h]++;
                }
                h=trie[h].pre;
            }
        }
        if (p==len) break;
        if (trie[o].next[s[p]-'a']==0)
        {
            while ((o>0)&&(trie[o].next[s[p]-'a']==0)) o=trie[o].pre;
            if (trie[o].next[s[p]-'a']==0)
            {
                o=0;p++;
                continue;
            }
        }
        o=trie[o].next[s[p++]-'a'];
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt=0;
    while (scanf("%s",st)!=EOF)
    {
      tt++;
      tot=0;
      new_trie();
      scanf("%d",&n);
      for (int i=0;i<n;i++)
      {
        scanf("%d %s",&type[i],s[i]);
        len_s[i]=strlen(s[i]);
        insert_trie(0,0,s[i],i);
        ans[i]=0;
        last[i]=-1;
      }
      bfs_trie();
      work(0,0,st);
      printf("Case %d\n",tt);
      for (int i=0;i<n;i++) printf("%d\n",num[type[i]][f[i]]);
      printf("\n");
    }
    return 0;
}

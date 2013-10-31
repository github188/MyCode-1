#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[26];
    int pre,end,no;
} trie[1000];
int ans[1000];
char s[1000][60];
int n,tot,m;
long long f[26][110][1024];
long long mod=20090717;

int new_trie()
{
    for (int i=0;i<26;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

void insert_trie(int o,int p,char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-'a']==0) trie[o].next[s[p]-'a']=new_trie();
        o=trie[o].next[s[p++]-'a'];
        if (p==len)
        {
            trie[o].end=1;
            trie[o].no=(1<<i);
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

inline int check(int o)
{
    int ans=0;
    while (o>0)
    {
        ans+=(o&1);
        o>>=1;
    }
    return ans;
}

int main()
{
    int k;
    while (scanf("%d%d%d",&m,&n,&k)!=EOF) {
    if (m+n+k>0) {gets(s[0]);} else break;
    tot=0;
    new_trie();
    for (int i=0;i<n;i++)
    {
        gets(s[i]);
        int len=strlen(s[i]);
        insert_trie(0,0,s[i],i);
        ans[i]=0;
    }
    bfs_trie();
    for (int i=0;i<=m;i++) for (int j=0;j<tot;j++) for (int l=0;l<(1<<n);l++) f[i][j][l]=0;
    f[0][0][0]=1;
    for (int i=0;i<m;i++)
     for (int j=0;j<tot;j++)
      for (int l=0;l<(1<<n);l++)
      if (f[i][j][l]>0)
      {
          for (int h=0;h<26;h++)
          {
              f[i+1][trie[j].next[h]][l|trie[trie[j].next[h]].no]+=f[i][j][l];
              if (f[i+1][trie[j].next[h]][l|trie[trie[j].next[h]].no]>=mod) f[i+1][trie[j].next[h]][l|trie[trie[j].next[h]].no]-=mod;
          }
      }

    long long ans=0;
    for (int i=0;i<(1<<n);i++)
    if (check(i)>=k)
    for (int j=0;j<tot;j++)
    {
        ans+=f[m][j][i];
        if (ans>=mod) ans-=mod;
    }
    int aans=ans;
    printf("%d\n",ans);

    }return 0;
}

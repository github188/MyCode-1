#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct node
{
    int next[26];
    int pre,end,no;
} trie[1100];
int a[1000];
char s[1000][60];
int n,tot,m;

struct ans_node
{
    string s;
    int v;
} f[60][1100];

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

int main()
{
    //freopen("in.txt","r",stdin);
    int k,tt;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d%d",&m,&n);
        gets(s[0]);
        tot=0;
        new_trie();
        for (int i=0;i<n;i++)
        {
            gets(s[i]);
            while (s[i][strlen(s[i])-1]==' ') s[i][strlen(s[i])-1]=0;
            int len=strlen(s[i]);
            insert_trie(0,0,s[i],i);
            //ans[i]=0;
        }
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        bfs_trie();
        ans_node ans;
        ans.v=0;ans.s="";
        for (int i=0;i<=m;i++)
          for (int j=0;j<tot;j++) f[i][j].v=-1;
        f[0][0].v=0;f[0][0].s="";
        for (int i=0;i<=m;i++)
          for (int j=0;j<tot;j++)
          if (f[i][j].v!=-1)
          {
              if (check(ans,f[i][j])) ans=f[i][j];
              if (i<m)
              {
                  for (int k=0;k<26;k++)
                  {
                      ans_node tmp;
                      tmp=f[i][j];
                      int l=trie[j].next[k];
                      while (trie[l].end>0)
                      {
                          if (trie[l].no>0) tmp.v+=a[trie[l].no];
                          l=trie[l].pre;
                      }
                      if ((i==5)&&(trie[j].next[k]==11))
                      {
                          int o=0;
                      }
                      if (check1(f[i+1][trie[j].next[k]],tmp,'a'+k))
                      {
                          f[i+1][trie[j].next[k]]=tmp;f[i+1][trie[j].next[k]].s+=char('a'+k);
                      }
                  }
              }
          }
        char aans[100];
        for (int i=0;i<ans.s.length();i++) aans[i]=ans.s[i];
        aans[ans.s.length()]=0;
        printf("%s\n",aans);
    }
    return 0;
}

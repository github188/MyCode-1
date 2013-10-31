#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct node
{
    int next[4];
    int pre,end,no;
} trie[1100];
int a[1000];
char s[1000][60],st[1100];
int n,tot,m;

int f[1100][1100];

int new_trie()
{
    for (int i=0;i<4;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

void insert_trie(int o,int p,char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-'1']==0) trie[o].next[s[p]-'1']=new_trie();
        o=trie[o].next[s[p++]-'1'];
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
    for (int i=0;i<4;i++)
      if (trie[0].next[i]>0) queue[0][size[0]++]=trie[0].next[i];

    int l=0;
    while (size[l]>0)
    {
        int k=l;l^=1;size[l]=0;
        for (int i=0;i<size[k];i++)
          for (int j=0;j<4;j++)
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
    tt=0;
    while (true)
    {
        scanf("%d",&n);
        if (n==0) break;
        tt++;
        gets(s[0]);
        tot=0;
        new_trie();
        for (int i=0;i<n;i++)
        {
            gets(s[i]);
            while (s[i][strlen(s[i])-1]==' ') s[i][strlen(s[i])-1]=0;
            int len=strlen(s[i]);
            for (int j=0;j<len;j++)
            {
                if (s[i][j]=='A') s[i][j]='1';
                if (s[i][j]=='C') s[i][j]='2';
                if (s[i][j]=='T') s[i][j]='3';
                if (s[i][j]=='G') s[i][j]='4';
            }
            insert_trie(0,0,s[i],i);
            //ans[i]=0;
        }
        bfs_trie();
        gets(st);
        m=strlen(st);
        while (st[strlen(st)-1]==' ') st[strlen(st)-1]=0;
        m=strlen(st);
        for (int j=0;j<m;j++)
            {
                if (st[j]=='A') st[j]='1';
                if (st[j]=='C') st[j]='2';
                if (st[j]=='T') st[j]='3';
                if (st[j]=='G') st[j]='4';
            }

        for (int i=0;i<=m;i++) for (int j=0;j<tot;j++) f[i][j]=-1;
        f[0][0]=0;
        for (int i=0;i<=m-1;i++)
         for (int j=0;j<tot;j++)
          if (f[i][j]!=-1)
          {
              for (int k=0;k<4;k++)
              {
                  int tmp=0;
                  if (st[i]!='1'+k) tmp=1;
                  if (trie[trie[j].next[k]].end==0)
                  {
                      tmp+=f[i][j];
                      if ((f[i+1][trie[j].next[k]]==-1)||(f[i+1][trie[j].next[k]]>tmp)) f[i+1][trie[j].next[k]]=tmp;
                  }
              }
          }
        int ans=-1;
        for (int i=0;i<tot;i++)
        if ((f[m][i]>-1)&&((ans==-1)||(ans>f[m][i]))) ans=f[m][i];
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}

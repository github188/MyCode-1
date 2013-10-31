#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[4];
    int pre,end,no;
} trie[100000];
int ans[1000];
char s[1000][60],st[2000000];
int n,tot,m;
long long f[200][200],g[200][200],tmp[200][200];
long long mod=100000;

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
        if (trie[o].next[s[p]-'1']==0)
        {
            while ((o>0)&&(trie[o].next[s[p]-'1']==0)) o=trie[o].pre;
            if (trie[o].next[s[p]-'1']==0)
            {
                o=0;p++;
                continue;
            }
        }
        o=trie[o].next[s[p++]-'1'];
    }
}

void mul_power(int m)
{
    if (m==1)
    {
        for (int i=0;i<tot;i++)
          for (int j=0;j<tot;j++) g[i][j]=f[i][j];
        return;
    }
    mul_power(m>>1);
    for (int i=0;i<tot;i++)
     for (int j=0;j<tot;j++)
     {
         tmp[i][j]=0;
         for (int k=0;k<tot;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*g[k][j])%mod;
     }
    for (int i=0;i<tot;i++)
     for (int j=0;j<tot;j++) g[i][j]=tmp[i][j];
    if ((m&1)>0)
    {
        for (int i=0;i<tot;i++)
         for (int j=0;j<tot;j++)
         {
             tmp[i][j]=0;
             for (int k=0;k<tot;k++) tmp[i][j]=(tmp[i][j]+g[i][k]*f[k][j])%mod;
         }
        for (int i=0;i<tot;i++)
         for (int j=0;j<tot;j++) g[i][j]=tmp[i][j];
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    if (n>0) gets(s[0]);
    tot=0;
    new_trie();
    for (int i=0;i<n;i++)
    {
        gets(s[i]);
        int len=strlen(s[i]);
        for (int j=0;j<len;j++)
        {
            if (s[i][j]=='A') s[i][j]='1';
            if (s[i][j]=='C') s[i][j]='2';
            if (s[i][j]=='T') s[i][j]='3';
            if (s[i][j]=='G') s[i][j]='4';
        }
        insert_trie(0,0,s[i],i);
        ans[i]=0;
    }
    bfs_trie();

    for (int i=0;i<tot;i++) if (trie[i].end==0)
    for (int j=0;j<4;j++) f[i][trie[i].next[j]]++;
    mul_power(m);
    long long ans=0;
    for (int i=0;i<tot;i++)
    if (trie[i].end==0) ans=(ans+g[0][i])%mod;
    int aans=ans;
    printf("%d\n",aans);
    //}
    return 0;
}
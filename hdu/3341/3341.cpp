#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[4];
    int pre,end,no;
} trie[510];
char s[50][15],st[50];
int n,tot,m;
int f[501][14700],type[4],status[14700][4],snext[14700][4];

inline int new_trie()
{
    for (int i=0;i<4;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

inline void insert_trie(int o,int p,char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-'1']==0) trie[o].next[s[p]-'1']=new_trie();
        o=trie[o].next[s[p++]-'1'];
        if (p==len)
        {
            trie[o].end++;
            trie[o].no=i+1;
        }
    }
}

int queue[2][600],size[2];
inline void bfs_trie()
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

inline void init(int lens)
{
    int tmp=0,a1=type[0]+1,a2=a1*(type[1]+1),a3=a2*(type[2]+1);
    for (int i=0;i<=type[0];i++)
      for (int j=0;j<=type[1];j++)
        for (int k=0;k<=type[2];k++)
         for (int l=0;l<=type[3];l++)
        {
            tmp=i+j*a1+k*a2+l*a3;
            status[tmp][0]=i;
            status[tmp][1]=j;
            status[tmp][2]=k;
            status[tmp][3]=l;
            snext[tmp][0]=tmp+1;
            snext[tmp][1]=tmp+a1;
            snext[tmp][2]=tmp+a2;
            snext[tmp][3]=tmp+a3;
        }
}

inline bool check(int p,int q)
{
    int aa[4];
    aa[0]=status[p][0];
    aa[1]=status[p][1];
    aa[2]=status[p][2];
    aa[3]=status[p][3];
    return (aa[q]+1<=type[q]);
}

int main()
{
    int tt=0;
    while (true)
    {
        tt++;
        scanf("%d",&n);
        if (n>0) gets(s[0]); else break;
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
        }
        bfs_trie();
        gets(st);
        int lens=strlen(st);
        type[0]=type[1]=type[2]=type[3]=0;
        for (int i=0;i<lens;i++)
        {
            int tmp;
            if (st[i]=='A') tmp=0;
            if (st[i]=='C') tmp=1;
            if (st[i]=='T') tmp=2;
            if (st[i]=='G') tmp=3;
            type[tmp]++;
        }
        int tmp=(type[0]+1)*(type[1]+1)*(type[2]+1)*(type[3]+1);
        for (int j=0;j<tot;j++) for (int k=0;k<tmp;k++) f[j][k]=-1;
        init(lens);
        int ans=0;
        f[0][0]=0;
            for (int k=0;k<tmp;k++)
          for (int j=0;j<tot;j++)
              if (f[j][k]>-1)
              {
                  ans=ans>f[j][k]?ans:f[j][k];
                  for (int l=0;l<4;l++)
                  if (check(k,l))
                  f[trie[j].next[l]][snext[k][l]]=f[trie[j].next[l]][snext[k][l]]>f[j][k]+trie[trie[j].next[l]].end?f[trie[j].next[l]][snext[k][l]]:f[j][k]+trie[trie[j].next[l]].end;
              }

        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}

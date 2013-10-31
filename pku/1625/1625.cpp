#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int next[60];
    int pre,end,no;
} trie[700];

const int maxlen=60;
class bigint;

class bigint {
public:
public:

	void writeln(){
		printf("%d",d[len]);
		int i;
		for(i=len-1;i>=1;i--)
			printf("%04d",d[i]);
		printf("\n");
	}
	int d[maxlen];
	int len;
};

void get_num(bigint *a,int b)
{
    a->len=0;
    while (b>0)
    {
        a->d[a->len++]=b%10000;
        b/=10000;
    }
}

void get_num(bigint *a,bigint *b)
{
}

void mul_num(bigint* a,bigint* b,bigint* c)
{
}

void add(bigint *a,int b)
{
    a->len=0;
    while (b>0)
    {
        a->d[a->len++]=b%10000;
        b/=10000;
    }
}
int ans[1000];
unsigned char s[1000][60],st[2000000];
int n,tot,m,n_alpha;
bigint f[110][110],g[110][110],tmp[110][110];

inline int strlen(unsigned char s[])
{
    int o=0;
    while (s[o]>0) o++;
    return o;
}
char tmp_s[1000];
inline void gets(unsigned char s[])
{
    gets(tmp_s);
    int l=strlen(tmp_s);
    for (int i=0;i<=l;i++) s[i]=tmp_s[i];
    s[l]=0;
}

inline int new_trie()
{
    for (int i=0;i<n_alpha;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

inline void insert_trie(int o,int p,unsigned char s[],int i)
{
    int len=strlen(s);
    while (p<len)
    {
        if (trie[o].next[s[p]-33]==0) trie[o].next[s[p]-33]=new_trie();
        o=trie[o].next[s[p++]-33];
        if (p==len)
        {
            trie[o].end=1;
            trie[o].no=i+1;
        }
    }
}

int queue[2][60000],size[2];
inline void bfs_trie()
{
    size[0]=0;
    for (int i=0;i<n_alpha;i++)
      if (trie[0].next[i]>0) queue[0][size[0]++]=trie[0].next[i];

    int l=0;
    while (size[l]>0)
    {
        int k=l;l^=1;size[l]=0;
        for (int i=0;i<size[k];i++)
          for (int j=0;j<n_alpha;j++)
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
         get_num(&tmp[i][j],0);
         for (int k=0;k<tot;k++)
           if ((g[i][k].len>0)&&(g[k][j].len>0)) mul_num(&tmp[i][j],&g[i][k],&g[k][j]);
     }
    for (int i=0;i<tot;i++)
     for (int j=0;j<tot;j++) get_num(&g[i][j],&tmp[i][j]);
    if ((m&1)>0)
    {
        for (int i=0;i<tot;i++)
         for (int j=0;j<tot;j++)
         {
             get_num(&tmp[i][j],0);
             for (int k=0;k<tot;k++)
               if ((g[i][k].len>0)&&(f[k][j].len>0)) mul_num(&tmp[i][j],&g[i][k],&f[k][j]);
         }
        for (int i=0;i<tot;i++)
         for (int j=0;j<tot;j++) get_num(&g[i][j],&tmp[i][j]);
    }
}

unsigned char al[100];
int ab[300];

int main()
{
    int p;
    scanf("%d%d%d",&p,&m,&n);
    n_alpha=p;
    if (n>0) gets(s[0]);
    gets(al);
    for (int i=0;i<p;i++) ab[al[i]]=i+1;
    tot=0;
    new_trie();
    for (int i=0;i<n;i++)
    {
        gets(s[i]);
        int len=strlen(s[i]);
        for (int j=0;j<len;j++) s[i][j]=32+ab[s[i][j]];
        insert_trie(0,0,s[i],i);
        ans[i]=0;
    }
    bfs_trie();

    for (int i=0;i<tot;i++) if (trie[i].end==0)
    for (int j=0;j<n_alpha;j++) add(&f[i][trie[i].next[j]],1);
    mul_power(m);
    bigint ans;
    get_num(ans,0);
    for (int i=0;i<tot;i++)
    if (trie[i].end==0) add(&ans,&g[0][i]);
    ans.writeln();
    //}
    return 0;
}

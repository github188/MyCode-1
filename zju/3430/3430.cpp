#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next[300];
    int pre,end,no;
} trie[50000];
int ans[1000],len_s[1000];
char s[1000][100],st[2000000];
int n,tot,len_st;

int new_trie()
{
    for (int i=0;i<300;i++) trie[tot].next[i]=0;
    trie[tot].pre=trie[tot].end=trie[tot].no=0;
    int tmp=tot;tot++;
    return tmp;
}

void insert_trie(int o,int p,char s[],int i)
{
    int len=len_s[i];
    while (p<len)
    {
        int tmp=(unsigned char)(s[p]);
        if (trie[o].next[int((unsigned char)(s[p]))+1]==0) trie[o].next[int((unsigned char)(s[p]))+1]=new_trie();
        o=trie[o].next[int((unsigned char)(s[p++]))+1];
        if (p==len)
        {
            trie[o].end=1;
            trie[o].no=i+1;
        }
    }
}

int queue[2][160000],size[2];
void bfs_trie()
{
    size[0]=0;
    for (int i=0;i<300;i++)
      if (trie[0].next[i]>0) queue[0][size[0]++]=trie[0].next[i];

    int l=0;
    while (size[l]>0)
    {
        int k=l;l^=1;size[l]=0;
        for (int i=0;i<size[k];i++)
          for (int j=0;j<300;j++)
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
    int len=len_st;
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
        if (trie[o].next[int((unsigned char)(s[p]))+1]==0)
        {
            while ((o>0)&&(trie[o].next[int((unsigned char)(s[p]))+1]==0)) o=trie[o].pre;
            if (trie[o].next[int((unsigned char)(s[p]))+1]==0)
            {
                o=0;p++;
                continue;
            }
        }
        o=trie[o].next[int((unsigned char)(s[p++]))+1];
    }
}

int tmp_s[100000];
int f[300];
void change(char s[],int &l)
{
    int tot=0,len=strlen(s);
    for (int i=0;i<len;i++)
    if (s[i]=='=') {break;} else
    {
        int k=f[s[i]];
        for (int j=5;j>=0;j--) {tmp_s[tot+j]=(k&1);k>>=1;}
        tot+=6;
    }
    if (s[len-1]=='=') {len--;tot-=2;}
    if (s[len-1]=='=') {len--;tot-=2;}
    len=0;
    for (int i=0;i<tot;i+=8)
    {
        int k=0;
        for (int j=7;j>=0;j--) k=(k<<1)+tmp_s[i+j];
        s[len++]=k;
    }
    s[len]=0;
    l=len;
}

int main()
{
    for (int i='A';i<='Z';i++) f[i]=i-'A';
    for (int i='a';i<='z';i++) f[i]=i-'a'+26;
    for (int i='0';i<='9';i++) f[i]=i-'0'+52;
    f['+']=62;f['/']+=63;
    while (scanf("%d\n",&n)!=EOF)
    {
        tot=0;
        new_trie();
        for (int i=0;i<n;i++)
        {
            gets(s[i]);
            int len=strlen(s[i]);
            while (s[i][len-1]==' ') len--;
            s[i][len]=0;
            change(s[i],len_s[i]);
            insert_trie(0,0,s[i],i);
            ans[i]=0;
        }
        bfs_trie();
        int m;
        scanf("%d\n",&m);
        while (m>0)
        {
            m--;
            gets(st);
            int len=strlen(st);
            while (st[len-1]==' ') len--;
            st[len]=0;
            change(st,len_st);
            work(0,0,st);
            int num=0;
            for (int i=0;i<n;i++) if (ans[i]>0) {num++;ans[i]=0;}
            printf("%d\n",num);
        }
        printf("\n");
    }
    return 0;
}

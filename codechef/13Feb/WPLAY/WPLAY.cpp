#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node
{
    bool ok;
    int next[26];
} trie[8000001];
int tot;
char s[20];
bool hash[70000];

void insert(int o,int p,int q)
{
    if (p==q) {trie[o].ok=true;return;}
    char ch=s[p]-'A';
    if (trie[o].next[ch]==0)
    {
        trie[o].next[ch]=++tot;
        trie[tot].ok=false;
    }
    insert(trie[o].next[ch],p+1,q);
}

void work(int o,int st,int pos,int r,int nst,bool ok)
{
    if (pos==r)
    {
        if (ok) hash[nst]=true;
        return;
    }
    if ((st&(1<<pos))!=0) work(o,st,pos+1,r,nst,ok);
    else
    {
        work(o,st,pos+1,r,nst,ok);
        char ch=s[pos]-'A';
        if (trie[o].next[ch]!=0)
        {
            int nextn=trie[o].next[ch];
            work(nextn,st,pos+1,r,nst|(1<<pos),trie[nextn].ok);
        }
    }
}

int main()
{
    tot=1;
    trie[tot].ok=false;
    int n;scanf("%d",&n);
    while (n--)
    {
        scanf("%s",s);
        sort(s,s+strlen(s));
        insert(1,0,strlen(s));
    }
    int r,c,t;
    scanf("%d%d%d\n",&r,&c,&t);int rc=r*c;
    while (t--)
    {
        char st[5];
        for (int i=0;i<r;i++)
        {
            scanf("%s",st);
            for (int j=0;j<c;j++)s[i*c+j]=st[j];
        }
        s[rc]=0;
        sort(s,s+rc);
        memset(hash,false,sizeof(hash));
        for (int i=0;i<(1<<rc);i++)
        if (!hash[i]) work(1,i,0,rc,i,false);
        if (hash[(1<<rc)-1]) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}

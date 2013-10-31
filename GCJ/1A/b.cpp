#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool h[10001][26],ab[26];
int f[10001][26],g[2][10001],len[10001];
char c[10001][20];
int tt,n,m;
char s[50];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&tt);int t=0;
    while (tt>0)
    {
          t++;tt--;
          printf("Case #%d:",t);
          scanf("%d%d",&n,&m);gets(s);
          for (int i=0;i<n;i++) for (int j=0;j<26;j++) {f[i][j]=0;h[i][j]=false;}
          for (int i=0;i<n;i++) 
          {
              gets(c[i]);
              len[i]=strlen(c[i]);
              for (int j=0;j<26;j++)
              {
                  int sum=0;
                  for (int k=0;k<len[i];k++)
                  if (c[i][k]==j+'a')
                  {
                     h[i][j]=true;
                     sum=(sum+(1<<k));
                  }
                  f[i][j]=sum;
              }
          }
          
          for (int i=0;i<m;i++)
          {
              gets(s);
              int ans0,ans1;ans0=ans1=-1;
              for (int j=0;j<n;j++)
              {
                  int sum=0;
                  g[0][0]=n;int l=0;
                        for (int uuu=0;uuu<26;uuu++) {ab[uuu]=false;}
                  for (int k=1;k<=n;k++) g[l][k]=k-1;
                  g[l^1][0]=0;
                  for (int k=1;k<=g[l][0];k++)
                  if (len[g[l][k]]==len[j]) 
                  {
                    g[l^1][0]++;g[l^1][g[l^1][0]]=g[l][k];
                    for (int kk=0;kk<len[g[l][k]];kk++) {ab[c[g[l][k]][kk]-'a']=true;}
                  }
                  l=(l^1);int u=0;
                  if (g[l][0]!=1)
                  for (int k=0;k<26;k++)
                  if (ab[s[k]-'a'])
                  {
                      if (!h[j][s[k]-'a'])
                      {
                        sum++;
                        for (int uuu=0;uuu<26;uuu++) {ab[uuu]=false;}
                        g[l^1][0]=0;
                        for (int kk=1;kk<=g[l][0];kk++)
                        if (!h[g[l][kk]][s[k]-'a'])
                        {
                           g[l^1][0]++;g[l^1][g[l^1][0]]=g[l][kk];
                           for (int ll=0;ll<len[g[l][kk]];ll++)
                           {
                               ab[c[g[l][kk]][ll]-'a']=true;
                           }                        
                        }
                        l=(l^1);
                      } else
                      {
                        for (int uuu=0;uuu<26;uuu++) {ab[uuu]=false;}
                        g[l^1][0]=0;
                        for (int kk=1;kk<=g[l][0];kk++)
                        if (f[g[l][kk]][s[k]-'a']==f[j][s[k]-'a'])
                        {
                           g[l^1][0]++;g[l^1][g[l^1][0]]=g[l][kk];
                           for (int ll=0;ll<len[g[l][kk]];ll++)
                           {
                               ab[c[g[l][kk]][ll]-'a']=true;
                           }                        
                        }
                        l=(l^1);
                      }
                      if (g[l][0]==1) {break;} 
                  }
                  if (ans0<sum) {ans0=sum;ans1=j;}
              }
              
              printf(" %s",c[ans1]);
          }
          printf("\n");
    }
    
    return 0;
}

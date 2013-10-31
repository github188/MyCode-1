#include<stdio.h>
#include<string.h>
using namespace std;
int f[30][30],g[30][30];
char s[2000];

int max(int o,int p)
{
    if (o>p) return o;return p;
}

int main()
{
    int tt;scanf("%d",&tt);gets(s);
    while (tt>0)
    {
        tt--;
        gets(s);
        if (strlen(s)==1) {printf("0\n");continue;}
        int len=strlen(s);
        memset(f,0,sizeof(f));
        f[s[0]-'a'][s[1]-'a']=2;
        f[s[1]-'a'][s[0]-'a']=2;
        f[s[0]-'a'][26]=1;
        f[26][s[0]-'a']=1;
        f[s[1]-'a'][26]=1;
        f[26][s[1]-'a']=1;
        if (s[0]<=s[1]) f[s[1]-'a'][26]++;
        if (s[0]>=s[1]) f[26][s[1]-'a']++;
        int l=0,ans=0;
        for (int i=2;i<len;i++)
        {
            for (int j=0;j<=26;j++)
              for (int k=0;k<=26;k++) g[j][k]=f[j][k];
            for (int j=0;j<=s[i]-'a';j++)
             for (int k=0;k<26;k++)
              if (f[j][k]!=0) g[s[i]-'a'][k]=max(g[s[i]-'a'][k],f[j][k]+1);
            for (int j=0;j<26;j++)
             for (int k=s[i]-'a';k<26;k++)
              if (f[j][k]!=0) g[j][s[i]-'a']=max(g[j][s[i]-'a'],f[j][k]+1);
            for (int j=0;j<26;j++)
              if (f[j][26]!=0) g[j][s[i]-'a']=max(f[j][26]+1,g[j][s[i]-'a']);
            for (int k=0;k<26;k++)
              if (f[26][k]!=0) g[s[i]-'a'][k]=max(f[26][k]+1,g[s[i]-'a'][k]);
            g[s[i]-'a'][26]=max(g[s[i]-'a'][26],1);
            g[26][s[i]-'a']=max(g[26][s[i]-'a'],1);
            for (int j=0;j<=s[i]-'a';j++)
              if (f[j][26]!=0) g[s[i]-'a'][26]=max(g[s[i]-'a'][26],f[j][26]+1);
            for (int k=s[i]-'a';k<26;k++)
              if (f[26][k]!=0) g[26][s[i]-'a']=max(g[26][s[i]-'a'],f[26][k]+1);
            for (int j=0;j<=26;j++)
              for (int k=0;k<=26;k++) f[j][k]=g[j][k];
        }
        for (int i=0;i<=26;i++)
         for (int j=0;j<=26;j++) ans=max(ans,f[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}

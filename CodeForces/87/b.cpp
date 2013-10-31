#include<stdio.h>
#include<string.h>
char s[200][200];
int a[200][2],f[200][200];
int n,m;

int max(int o,int p)
{
    if (o>p) {return o;}return p;
}
int min(int o,int p)
{
    if (o<p) {return o;}return p;
}

int main()
{
    int maxint=2000*2000;
    scanf("%d%d",&n,&m);gets(s[0]);
    for (int i=0;i<n;i++) {gets(s[i]);}
    a[0][0]=0;a[0][1]=0;f[0][0]=-1;
    for (int i=1;i<m;i++){
    if (s[0][i]=='W') {a[0][1]=i;}f[0][i]=-1;}
    for (int i=1;i<n;i++)
    {
        a[i][0]=m;a[i][1]=-1;
        for (int j=0;j<m;j++) {f[i][j]=-1;
        if (s[i][j]=='W')
        {
           if (j<a[i][0]) {a[i][0]=j;}
           if (j>a[i][1]) {a[i][1]=j;}
        }}
    }
    
    for (int i=a[0][1];i<m;i++) {f[0][i]=i;}
    for (int i=1;i<n;i++)
    {
      int u;
      if (a[i][1]==-1)
      {
        if ((i&1)==1)
        {
            for (int j=0;j<m;j++)
            {
                f[i][j]=maxint;
                for (int k=j;k<m;k++) if (f[i-1][k]!=-1) f[i][j]=min(f[i][j],f[i-1][k]+1+k-j);
                if (f[i][j]==maxint) {f[i][j]=-1;}
            }
              
        } else
        {
            for (int j=0;j<m;j++)
            {
                f[i][j]=maxint;
                for (int k=0;k<=j;k++) if (f[i-1][k]!=-1) f[i][j]=min(f[i][j],f[i-1][k]+1+j-k);
                if (f[i][j]==maxint) {f[i][j]=-1;}
            }
        }
      } else
      {
        if ((i&1)==1)
        {
          for (int j=0;j<=a[i][0];j++)
            {
                f[i][j]=maxint;
                for (int k=max(j,a[i][1]);k<m;k++) if (f[i-1][k]!=-1) f[i][j]=min(f[i][j],f[i-1][k]+1+k-j);
                if (f[i][j]==maxint) {f[i][j]=-1;}
            }
        } else
        {
            for (int j=a[i][1];j<m;j++)
            {
                f[i][j]=maxint;
                for (int k=0;k<=min(j,a[i][0]);k++) if (f[i-1][k]!=-1) f[i][j]=min(f[i][j],f[i-1][k]+1+j-k);
                if (f[i][j]==maxint) {f[i][j]=-1;}
            }
        }
      }
    }
    
    int k=n-1;
    while (a[k][1]==-1) {k--;}
    int ans=maxint;
    if ((k&1)==0) {for (int i=a[k][1];i<m;i++)if (f[k][i]!=-1) {ans=min(ans,f[k][i]);}}
    else
    {
        for (int i=0;i<=a[k][0];i++)if (f[k][i]!=-1) {ans=min(ans,f[k][i]);}
    }
    printf("%d\n",ans);
    
    return 0;
}

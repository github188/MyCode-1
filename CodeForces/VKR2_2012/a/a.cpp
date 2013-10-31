#include<stdio.h>
#include<string.h>
char s[10000],t[10000];
int a[5000][5000],b[5000][5000];
int n,m;

int main()
{
    int mod=1000000007;
    gets(s);gets(t);
    n=strlen(s);m=strlen(t);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        if ((s[i]==t[j]))
        {
            a[i][j]=1;
            if ((i>0)&&(j>0)) a[i][j]+=b[i-1][j-1];
        }
        b[i][0]=a[i][0];
        for (int j=1;j<m;j++) b[i][j]=(b[i][j-1]+a[i][j])%mod;;
    }
    int ans=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
     if (s[i]==t[j]) ans=(ans+a[i][j])%mod;
     printf("%d\n",ans);
    return 0;
}

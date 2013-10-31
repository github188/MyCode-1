#include<stdio.h>
#include<string.h>
char s[100];
bool f[101][101];

int main()
{
    freopen("2.out","w",stdout);
    int tt;scanf("%d",&tt);gets(s);
    for (int t=1;t<=tt;t++)
    {
        gets(s);
        int n=strlen(s);
        memset(f,false,sizeof(f));
        for (int i=0;i<n;i++)
        if (((s[i]>='a')&&(s[i]<='z'))||(s[i]==' ')||(s[i]==':')) f[i][i]=true;
        for (int i=0;i<n-1;i++)
        {
            if (f[i][i]&f[i+1][i+1]) f[i][i+1]=true;
            if ((s[i]=='(')&&(s[i+1]==')')) f[i][i+1]=true;
            if ((s[i]==':')&&(s[i+1]==')')) f[i][i+1]=true;
            if ((s[i]==':')&&(s[i+1]=='(')) f[i][i+1]=true;
        }
        for (int i=3;i<=n;i++)
         for (int j=0;j<=n-i;j++)
         {
             if ((s[j]=='(')&&(s[j+i-1]==')')) f[j][j+i-1]=true;
             else
             {
                 for (int k=j;k<j+i-1;k++)
                 if (f[j][k]&f[k+1][j+i-1])
                 {
                     f[j][j+i-1]=true;
                     break;
                 }
             }
         }
         if (f[0][n-1]) printf("Case #%d: YES\n",t);
         else printf("Case #%d: NO\n",t);
    }
    return 0;
}

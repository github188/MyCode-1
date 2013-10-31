#include<stdio.h>
#include<string.h>
char s[200][200];

int main()
{
    int tt;scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n,m;scanf("%d%d",&n,&m);gets(s[0]);
        for (int i=0;i<n;i++) gets(s[i]);
        for (int i=0;i<n;i++)
          for (int j=0;j<m;j++)
          if ((s[i][j]>='A')&&(s[i][j]<='Z')) s[i][j]=s[i][j]-'A'+'a';

        bool check=false;
        for (int i=0;i<=n-5;i++)
         for (int j=0;j<m;j++)
         if ((s[i][j]=='s')&&(s[i+1][j]=='p')&&(s[i+2][j]=='o')&&(s[i+3][j]=='o')&&(s[i+4][j]=='n')) check=true;
        for (int i=0;i<n;i++)
         for (int j=0;j<=m-5;j++)
         if ((s[i][j]=='s')&&(s[i][j+1]=='p')&&(s[i][j+2]=='o')&&(s[i][j+3]=='o')&&(s[i][j+4]=='n')) check=true;
        if (check)
        {
            printf("There is a spoon!\n");
        } else
        {
            printf("There is indeed no spoon!\n");
        }

    }
    return 0;
}

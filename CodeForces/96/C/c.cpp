#include<stdio.h>
#include<string.h>
char ch[100];
bool a[100][51][301][2];

int main()
{
    gets(ch);
    int n;
    scanf("%d",&n);
    if (ch[0]=='T')
    {
        if (n>0) a[0][1][151][0]=true;
        a[0][0][150][1]=true;
    } else
    {
        if (n>0) a[0][1][150][1]=true;
        a[0][0][151][0]=true;
    }
    int d[2];d[0]=1;d[1]=-1;
    for (int i=1;i<strlen(ch);i++)
     for (int j=0;j<=n;j++)
      for (int k=1;k<300;k++)
       for (int l=0;l<2;l++)
      {
          if (ch[i]=='T')
          {
              a[i][j][k][l]=(a[i][j][k][l]|a[i-1][j][k][l^1]);
              if (j>0) a[i][j][k][l]=(a[i][j][k][l]|a[i-1][j-1][k-d[l]][l]);
          } else
          {
              a[i][j][k][l]=(a[i][j][k][l]|a[i-1][j][k-d[l]][l]);
              if (j>0) a[i][j][k][l]=(a[i][j][k][l]|a[i-1][j-1][k][l^1]);
          }
      }

    int ans=100;
    while (ans>=0)
    {
        bool use=false;
        for (int i=n;i>=0;i-=2) if ((a[strlen(ch)-1][i][150-ans][0])||(a[strlen(ch)-1][i][150-ans][1])) {use=true;break;}
        for (int i=n;i>=0;i-=2) if ((a[strlen(ch)-1][i][150+ans][0])||(a[strlen(ch)-1][i][150+ans][1])) {use=true;break;}
        if (use) break;
        ans--;
    }
    printf("%d\n",ans);

    return 0;
}

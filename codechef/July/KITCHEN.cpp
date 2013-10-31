#include<stdio.h>
int n,m,t;
char s[1001][1001];

void work(int n)
{
     if (m==2)
     {
              for (int i=1;i<=n;i++) {s[i][1]='#';s[i][2]='.';}
              s[1][2]=s[n][2]='#';
              return;
     }
     if (n==1) {for (int i=2;i<=m;i++) {s[1][i]='#';} return;}
     for (int i=1;i<=m;i++)
     {
         if (i!=2) {s[1][i]='#';} else {s[1][i]='.';} 
         s[n][i]='#';
     }
     for (int i=2;i<n;i++)
     {
         s[i][1]=s[i][m]='#';
         if ((i&1)==1)
         {
           for (int j=2;j<m-1;j++) {s[i][j]='#';}
           s[i][m-1]='.';
         } else {for (int j=2;j<m;j++) {s[i][j]='.';}}
     }
}

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
          t--;
          scanf("%d%d",&n,&m);
          if ((n&1)==1) {work(n);}
          else
          {
              work(n-1);
              for (int i=1;i<=m;i++)
              {
                  if ((i&1)==1)
                   {s[n][i]='#';} else {s[n][i]='.';}
              }
          }
          
          for (int i=1;i<=n;i++) { for (int j=1;j<=m;j++) {printf("%c",s[i][j]);} printf("\n");}
          if (t!=0) {printf("\n");}
    }
    return 0;
}

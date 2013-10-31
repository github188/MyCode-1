#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[3][50];
long long f[50][50][50];
int l[3];
int tt;

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%s%s%s",&s[0],&s[1],&s[2]);
        for (int i=0;i<3;i++) l[i]=strlen(s[i]);
        memset(f,0,sizeof(f));
        for (int i=0;i<l[0];i++)
         for (int j=0;j<l[1];j++)
          for (int k=0;k<l[2];k++)
          {
              if (i!=0) f[i][j][k]+=f[i-1][j][k];
              if (j!=0) f[i][j][k]+=f[i][j-1][k];
              if (k!=0) f[i][j][k]+=f[i][j][k-1];
              if ((i!=0)&&(j!=0)) f[i][j][k]-=f[i-1][j-1][k];
              if ((i!=0)&&(k!=0)) f[i][j][k]-=f[i-1][j][k-1];
              if ((k!=0)&&(j!=0)) f[i][j][k]-=f[i][j-1][k-1];
              if ((i!=0)&&(j!=0)&&(k!=0)) f[i][j][k]+=f[i-1][j-1][k-1];
              if ((s[0][i]==s[1][j])&&(s[0][i]==s[2][k]))
              {
                 if ((i!=0)&&(j!=0)&&(k!=0)) {f[i][j][k]+=f[i-1][j-1][k-1];} else {f[i][j][k]++;}
              }
          }
        cout<<f[l[0]][l[1]][l[2]]<<endl;
    }
    return 0;
}

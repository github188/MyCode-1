#include<stdio.h>
#include<string.h>
#define MAXN 43046721
char s[4][4];
char* ans[4];

int check()
{
    int num=0;
    for (int i=0;i<4;i++)
     for (int j=0;j<4;j++) if (s[i][j]!='.') num++;
    for (int i=0;i<4;i++)
    {
        bool c=true;
        for (int j=0;j<4;j++) if ((s[i][j]!='X')&&(s[i][j]!='T')) c=false;
        if (c) return 0;c=true;
        for (int j=0;j<4;j++) if ((s[j][i]!='X')&&(s[j][i]!='T')) c=false;
        if (c) return 0;c=true;
        for (int j=0;j<4;j++) if ((s[j][j]!='X')&&(s[j][j]!='T')) c=false;
        if (c) return 0;c=true;
        for (int j=0;j<4;j++) if ((s[j][3-j]!='X')&&(s[j][3-j]!='T')) c=false;
        if (c) return 0;
    }
    for (int i=0;i<4;i++)
    {
        bool c=true;
        for (int j=0;j<4;j++) if ((s[i][j]!='O')&&(s[i][j]!='T')) c=false;
        if (c) return 1;c=true;
        for (int j=0;j<4;j++) if ((s[j][i]!='O')&&(s[j][i]!='T')) c=false;
        if (c) return 1;c=true;
        for (int j=0;j<4;j++) if ((s[j][j]!='O')&&(s[j][j]!='T')) c=false;
        if (c) return 1;c=true;
        for (int j=0;j<4;j++) if ((s[j][3-j]!='O')&&(s[j][3-j]!='T')) c=false;
        if (c) return 1;
    }
    if (num==16) return 2;
    return 3;
}
char ss[1000];
int main()
{
    int n;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&n);
    ans[0]="X won";
    ans[1]="O won";
    ans[2]="Draw";
    ans[3]="Game has not completed";
    for (int t=1;t<=n;t++)
    {
        for (int i=0;i<4;i++)
        {
            scanf("%s",ss);
            for (int j=0;j<4;j++) s[i][j]=ss[j];
        }
        printf("Case #%d: %s\n",t,ans[check()]);
    }
    return 0;
}

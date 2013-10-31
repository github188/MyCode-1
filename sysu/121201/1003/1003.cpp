#include<string.h>
#include<stdio.h>

char s[100];
int n,m;

int main()
{
    int tt=0;
    while (scanf("%d %s %d",&n,s,&m)!=EOF)
    {
        if (s[0]=='E') break;
        printf("Case %d: ",++tt);
        if (s[0]=='!')
        {
            if (n==m) printf("false\n");
            else printf("true\n");
            continue;
        }
        if (s[0]=='=')
        {
            if (n!=m) printf("false\n");
            else printf("true\n");
            continue;
        }
        if (s[0]=='<')
        {
            if (strlen(s)==1)
            {
                if (n>=m) printf("false\n");
                else printf("true\n");
                continue;
            } else
            {
                if (n>m) printf("false\n");
                else printf("true\n");
                continue;
            }
        }
        if (s[0]=='>')
        {
            if (strlen(s)==1)
            {
                if (n<=m) printf("false\n");
                else printf("true\n");
                continue;
            } else
            {
                if (n<m) printf("false\n");
                else printf("true\n");
                continue;
            }
        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
char s[100];
int n;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%s",&n,s);
    for (int i=0;i<n/2;i++)
    {
        if ((s[i]=='R')&&(s[i+n/2]=='L')) printf("%d %d\n",i+1+n/2,i+1);
        else printf("%d %d\n",i+1,i+n/2+1);
    }
    return 0;
}

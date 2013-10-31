#include<stdio.h>
#include<string.h>
char s[10000],a[100];

int main()
{
    int t;
    scanf("%d%s",&t,a);
    while (t--)
    {
        scanf("%s",&s);
        for (int i=0;i<strlen(s);i++)
        {
            if ((s[i]>='A')&&(s[i]<='Z'))
            {
                printf("%c",a[s[i]-'A']-'a'+'A');
            } else
            if ((s[i]>='a')&&(s[i]<='z'))
            {
                printf("%c",a[s[i]-'a']);
            } else
            if (s[i]=='_') printf(" ");
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}

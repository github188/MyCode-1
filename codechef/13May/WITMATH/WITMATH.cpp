#include<stdio.h>
#include<string.h>
int a[26];
char s[100000];
int tt,n;

int main()
{
    scanf("%d",&tt);
    while (tt--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        n=strlen(s);
        for (int i=0;i<n;i++) a[s[i]-'a']++;
        scanf("%s",s);
        n=strlen(s);
        for (int i=0;i<n;i++) a[s[i]-'a']++;
        int m;scanf("%d",&m);
        bool ans=true;
        while (m--)
        {
            scanf("%s",s);
            n=strlen(s);
            for (int i=0;i<n;i++)
            {
                a[s[i]-'a']--;
                if (a[s[i]-'a']<0) ans=false;
            }
        }
        if (ans) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

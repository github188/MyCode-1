#include<stdio.h>
#include<string.h>

int a[500];
char s[300];

int main()
{
    int tt;scanf("%d",&tt);gets(s);
    while (tt--)
    {
        memset(a,0,sizeof(a));
        gets(s);
        for (int i=0;i<strlen(s);i++) a[s[i]]++;
        int ans=0;
        for (int i=0;i<500;i++) ans+=a[i]/2+a[i]%2;
        printf("%d\n",ans);
    }
    return 0;
}

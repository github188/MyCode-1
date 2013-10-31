#include<stdio.h>
#include<string.h>
char s[2000];
int a[100],b[100];

int  main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s",s);
        for (int i=0;i<strlen(s);i++) a[s[i]-'a']++;
        scanf("%s",s);
        for (int i=0;i<strlen(s);i++) b[s[i]-'a']++;
        bool low=false,up=false;
        for (int i=0;i<26;i++)
        if ((a[i]+b[i]>0)&&(a[i]*b[i]==0)) low=true;
        else if (a[i]!=b[i]) up=true;
        if (low|((!low)&(!up))) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

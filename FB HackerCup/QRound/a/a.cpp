#include<string.h>
#include<stdio.h>
#include<algorithm>
int a[26];
char s[1000];

int main()
{
    //freopen("1.out","w",stdout);
    int tt;scanf("%d",&tt);gets(s);
    for (int t=1;t<=tt;t++)
    {
        gets(s);
        memset(a,0,sizeof(a));
        int size=strlen(s);
        for (int i=0;i<size;i++)
        {
            if ((s[i]>='A')&&(s[i]<='Z')) a[s[i]-'A']++;
            if ((s[i]>='a')&&(s[i]<='z')) a[s[i]-'a']++;
        }
        std::sort(a,a+26);
        int ans=0;
        for (int i=1;i<=26;i++) ans+=a[i-1]*i;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

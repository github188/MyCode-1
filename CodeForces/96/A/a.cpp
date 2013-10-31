#include<string.h>
#include<stdio.h>

int main()
{
    char ch[200];
    gets(ch);
    int ans=0;
    for (int i=0;i<strlen(ch);i++)
    {
        int u=ch[i],v=0;
        for (int j=0;j<8;j++)
        {
            v=(v<<1);
            v+=(u&1);
            u=(u>>1);
        }
        ans-=v;
        if (ans<0) ans+=256;
        if (ans>256) ans-=256;
        printf("%d\n",ans);
        ans=v;

    }
    return 0;
}

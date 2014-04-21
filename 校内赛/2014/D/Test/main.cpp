#include<stdio.h>
#include<string.h>
char c[1000];
char* task = "fbiwarning";

int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",c);
        int m=strlen(c);
        bool ans=false;
        for (int j=0;j<=m-10;j++)
        {
            ans=true;
            for (int k=0;k<10;k++)
            if (task[k]!=c[j+k]) {ans=false;break;}
            if (ans) break;
        }
        if (ans) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}

#include<string.h>
#include<stdio.h>

int main()
{
    int const *a;
    int n,m;scanf("%d%d",&n,&m);
    if (m>n) {printf("-1\n");}
    else
    {
        if (m==1)
        {
            if (n==1) printf("a\n");
            else printf("-1\n");
        } else
        if (m==2)
        {
            for (int i=0;i<n;i++) printf("%c",'a'+(i&1));
            printf("\n");
        } else
        {
            for (int i=0;i<n-(m-2);i++) printf("%c",'a'+(i&1));
            for (int i=2;i<m;i++) printf("%c",'a'+i);
            printf("\n");
        }
    }
    return 0;
}

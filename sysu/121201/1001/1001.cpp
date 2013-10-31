#include<stdio.h>
#include<string.h>
char s[1000];
int n;

void work(int n)
{
    if (n==1) {s[strlen(s)]='0';return;}
    int ans=0;
    while (n>0)
    {
        ans++;
        s[strlen(s)]='0'+(n&1);
        n>>=1;
    }
    work(ans-1);
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        memset(s,0,sizeof(s));
        work(n);
        for (int i=strlen(s)-1;i>=0;i--) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

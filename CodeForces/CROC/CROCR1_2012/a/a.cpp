#include<stdio.h>
#include<string.h>
char s[1000],t[1000];
int n,a,b;

int gcd(int o,int p)
{
    if (o>p) {int q=o;o=p;p=q;}
    if (o==0) return p;
    return gcd(p%o,o);
}

void work(int n)
{
    int ls=strlen(s),lt=strlen(t);
    if (n==0) return;
    int k=0,hs=0,ht=0;
    while (k<n)
    {
        if ((s[hs]=='R')&&(t[ht]=='S')) b++;
        if ((s[hs]=='S')&&(t[ht]=='P')) b++;
        if ((s[hs]=='P')&&(t[ht]=='R')) b++;
        if ((s[hs]=='S')&&(t[ht]=='R')) a++;
        if ((s[hs]=='P')&&(t[ht]=='S')) a++;
        if ((s[hs]=='R')&&(t[ht]=='P')) a++;

        k++;
        hs++;if (hs>=ls) hs=0;
        ht++;if (ht>=lt) ht=0;
    }
}

int main()
{
    scanf("%d",&n);gets(s);
    gets(s);gets(t);
    int g=strlen(s)*strlen(t)/gcd(strlen(s),strlen(t));
    a=b=0;
    work(g);
    a=(n/g)*a;
    b=(n/g)*b;
    work(n%g);
    printf("%d %d\n",a,b);
    return 0;
}

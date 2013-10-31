#include<stdio.h>
#include<string.h>

char c[100000];
int a[100000];
int n;

int main()
{
    gets(c);n=0;int ans=0;int len=strlen(c);
    for (int i=0;i<len;i++)
    {
        if (c[i]=='(') {a[n++]=0;ans++;}
        if (c[i]==')') {a[n++]=1;ans++;}
        if ((c[i]=='-')||(c[i]==':')||(c[i]==',')||(c[i]==';')) a[n++]=2;
    }
    for (int i=0;i<n-1;i++)
    if ((a[i]==0)&&(a[i+1]==1)) {ans-=2;}
    printf("%d\n",ans);
    return 0;
}

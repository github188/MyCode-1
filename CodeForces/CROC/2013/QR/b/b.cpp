#include<stdio.h>
#include<string.h>
char s[500000];
int len,h;

void work1()
{
    h++;printf("<");
    while (s[h]!='"') printf("%c",s[h++]);
    printf(">\n");h++;
}

void work2()
{
    printf("<");
    while ((h<len)&&(s[h]!=' ')&&(s[h]!='"')) printf("%c",s[h++]);
    printf(">\n");h++;
}

int main()
{
    gets(s);
    len=strlen(s);h=0;
    while (h<len)
    {
        if (s[h]=='"') {work1();continue;}
        if (s[h]!=' ') {work2();continue;}
        h++;
    }
    return 0;
}

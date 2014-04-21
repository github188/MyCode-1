#include<string.h>
#include<stdio.h>
char s[1000000];
int a[300];

int main()
{
    while(gets(s))
    {
        int n=strlen(s);
        for (int i=0;i<300;i++) a[i]=0;
        bool check=true;
        for (int i=0;i<n;i++)
        if (((s[i]>='0')&&(s[i]<='9'))||((s[i]>='a')&&(s[i]<='z'))) a[s[i]]++; else {check=false;break;}
        if (!check) printf("<invalid input string>\n"); else
        {
            while (n>0)
            {
                for (int i='0';i<='z';i++)
                if (a[i]) {printf("%c",i);a[i]--;n--;}
            }
            printf("\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
using namespace std;

char s[100000],p[100000];
int n;

int main()
{
    scanf("%d",&n);p[0]='/';
    gets(s);
    while (n>0)
    {
        n--;
        gets(s);
        if ((strlen(s)==3)&&(s[0]=='p'))
        {
            printf("%s\n",p);
            continue;
        }
        int k=3;if (s[k]=='/') k++;
        int len=strlen(s);
        while (k<len)
        {
            if (s[k]=='.')
            {
                int l=strlen(p)-2;
                while (p[l]!='/') l--;
                p[l+1]=0;
                k+=3;
                continue;
            }
            int l=strlen(p);
            while ((s[k]!='/')&&(k<len))
            {
                p[l]=s[k];
                l++;k++;
            }
            p[l]='/';
            p[l+1]=0;
            k++;
        }
    }
    return 0;
}

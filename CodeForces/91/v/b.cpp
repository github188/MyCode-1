#include<stdio.h>
#include<string.h>

char ch[100000];
int n,k;

int main()
{
    scanf("%d%d",&n,&k);gets(ch);gets(ch);
    int i=0,len=strlen(ch);
    while ((i<n)&&(k>0))
    {
        while ((i+1<n)&&((ch[i]!='4')||(ch[i+1]!='7'))) {i++;}
        if (i+1>=n) {break;}
        if ((i&1)==0) {k--;ch[i+1]='4';}
        else
        {
            if (ch[i-1]=='4')
            {
                if ((k&1)==1) ch[i]='7';
                break;
            } else {ch[i]='7';k--;}
        }
     }

     printf("%s\n",ch);
    return 0;
}

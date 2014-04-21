#include<string.h>
#include<stdio.h>
int main()
{
	int t;scanf("%d\n",&t);
	while (t--)
	{
		int n=0;
		char s1='1',s2='2',s3='3',s;
		bool mark=false;
		scanf("%c",&s);
		while (s!='\n')
        {
            if (n==0) s1=s; else
            if (n==1) s2=s; else
            if (n==2) s3=s; else
            {
                s1=s2;s2=s3;s3=s;
            }
            if ((s1==s3)&&(s1!=s2)) mark=true;
            scanf("%c",&s);n++;
        }
		if (mark) printf("Good\n"); else printf("Bad\n");
	}
	return 0;
}

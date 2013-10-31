#include<stdio.h>
#include<string.h>
char s[200000];
int a[200000],b[200000];

int main()
{
    gets(s);
    int n=strlen(s);
    int ans,t;ans=0;
    for (int i=0;i<n;i++)
    {
        if ((s[i]=='(')||(s[i]=='[')) {a[i]=-1;continue;}
        if (i==0) {a[i]=-1;continue;}
        if (s[i]==')')
        {
            int j=i-1,tmp=0;
            while (a[j]>=0)
            {
                tmp+=b[j];
                j=a[j]-1;
            }
            if (s[j]=='(')
            {
                a[i]=j;
                b[i]=tmp;
            } else {a[i]=-1;}
        }
        if (s[i]==']')
        {
            int j=i-1,tmp=1;
            while (a[j]>=0)
            {
                tmp+=b[j];
                j=a[j]-1;
            }
            if (s[j]=='[')
            {
                a[i]=j;
                b[i]=tmp;
            } else {a[i]=-1;}
        }
        //if (tmp>ans) {ans=tmp;t=i;}
    }

    int j=n-1;
    while (j>=0)
    {
        int tmp=0;
        int k=j;
        if (a[j]>=0)
        {
            while ((j>=0)&&(a[j]>=0))
            {
                tmp+=b[j];
                j=a[j]-1;
            }
            if (tmp>ans) {ans=tmp;t=k;}
        } else j--;
    }

    printf("%d\n",ans);
    if (ans>0)
    {
        int j=t;
        while ((j>=0)&&(a[j]>=0)) j=a[j]-1;
        j++;
        for (int i=j;i<=t;i++) printf("%c",s[i]);
        printf("\n");
    } else {printf("\n");}
    return 0;
}

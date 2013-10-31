#include<stdio.h>
#include<string.h>
int n;
char a[300000],b[300000];
long long lnum[26],rnum[26];

int main()
{
    scanf("%d",&n);gets(a);
    gets(a);gets(b);
    long long ans=0,nn=0;
    for (int i=0;i<n;i++)
    {
        long long ii=i+1;nn+=ii*ii;
        if (a[i]==b[i])
        {
            long long l=i+1,r=(n-i);
            ans+=l*r;
        }
        //if (i!=0)
        {
            long long tmp=n-i;
            rnum[b[i]-'A']+=tmp;
        }
    }
    double sum=0;
    double aa=ans,na=nn;
    aa/=na;
    sum+=aa;
    for (int i=0;i<n;i++)
    {
        long long nl=i+1,nr=n-i;
        rnum[b[i]-'A']-=nr;
        ans=nr*lnum[a[i]-'A']+nl*rnum[a[i]-'A'];
        lnum[b[i]-'A']+=nl;
        double aa=ans,na=nn;
        aa/=na;
        sum+=aa;
    }
    printf("%.6f\n",sum);
    return 0;
}

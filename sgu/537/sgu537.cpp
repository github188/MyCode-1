#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

char c[20];
long long que[20],q[20000];
int nque,n,na,nq,first;
long long ans;
long long ans1[10000];

long long gcd(long long a,long long b)
{
    if (a<b) {long long c=a;a=b;b=c;}
    if (b==0) {return a;} else return gcd(b,a%b);
}

void work(int h,long long num,long long sum)
{
    if (h==nque)
    {
        if (ans==0) {ans=sum;} else {ans=gcd(ans,sum);}
        return;
    }
    long long dl=nque-1-h;
    if ((h==0)&&(dl==0)) dl=1;
    for (long long i=num;i>=dl;i--) work(h+1,i-1,sum+que[h]*i);
}

int main()
{
    scanf("%d",&n);gets(c);
    for (int tt=1;tt<=n;tt++)
    {
        gets(c);nque=0;nq=0;
        for (int i='a';i<='z';i++)
        {
            long long num=0;
            long long ten,mi;mi=1;ten=10;
            for (int j=strlen(c)-1;j>=0;j--)
            {
                if (c[j]==i) {num+=mi;if (j==0) {first=nque;}}
                mi=mi*ten;
            }
            if (num!=0) {que[nque]=num;nque++;}
        }
        for (int i=0;i<nque;i++)
          for (int j=i+1;j<nque;j++)
           {
               int ul1=0,ul2=0;
               if ((i==first)||(j==first)) {ul2=1;ul1=1;}
               for (int k=ul1;k<=9;k++)
                for (int l=ul2;l<=9;l++)
                if (k!=l)
                {
                   long long kk=k,ll=l;
                   q[nq]=(kk*que[i]+ll*que[j])-(ll*que[i]+kk*que[j]);
                   if (q[nq]<0) q[nq]=-q[nq];
                   nq++;
                }
           }

        ans=que[0];que[0]=que[first];que[first]=ans;
        ans=0;
        work(0,9,0);

        for (int i=0;i<nq;i++) ans=gcd(ans,q[i]);
        long long ul=sqrt(ans);ul++;
        na=0;
        for (long long i=1;i<=ul;i+=2)
        if ((ans%i==0)&&(i<=ans/i))
        {
            ans1[na]=i;na++;
            long long v=ans/i;
            if (v!=i)
            {
                ans1[na]=v;na++;
            }
        }
        sort(ans1,ans1+na);
        printf("Case %d:",tt);
        for (int i=0;i<na;i++) cout<<" "<<ans1[i];cout<<endl;
    }
    return 0;
}

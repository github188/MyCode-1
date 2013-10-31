#include<stdio.h>
#include<string.h>
#define mod 1000000007

char s[1000000];
int query[2][1000000],sum[2],l[2],r[2],tmp[2];
int n,k,ans,b;

int main()
{
    scanf("%d%d",&n,&k);
    if (k+k>n) {printf("0\n");return 0;}
    ans=0;
    gets(s);gets(s);
    b=0;r[0]=r[1]=-1;
    tmp[0]=1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='W')
        {
            query[1][++r[1]]=tmp[1];
            if (r[1]-l[1]+1==k) {sum[1]-=query[1][l[1]];ans=(ans+query[1][l[1]++])%mod;}
            if (sum[1]<0) sum[1]+=mod;
            sum[1]=(sum[1]+tmp[1])%mod;
            tmp[1]=0;
            tmp[0]=(tmp[0]+sum[0])%mod;
            sum[0]=0;
            l[0]=r[0]+1;
        }

        if (s[i]=='B')
        {
            query[0][++r[0]]=tmp[0];
            if (r[0]-l[0]+1==k) {sum[0]-=query[0][l[0]];tmp[1]=(tmp[1]+query[0][l[0]++])%mod;}
            if (sum[0]<0) sum[0]+=mod;
            sum[0]=(sum[0]+tmp[0])%mod;
            tmp[0]=0;
            tmp[1]=(tmp[1]+sum[1])%mod;
            sum[1]=0;
            l[1]=r[1]+1;
        }

        if (s[i]=='X')
        {
            int sum0=sum[0],sum1=sum[1];

            ans=(ans+ans)%mod;
            query[1][++r[1]]=tmp[1];
            if (r[1]-l[1]+1==k) {sum[1]-=query[1][l[1]];ans=(ans+query[1][l[1]++])%mod;}
            if (sum[1]<0) sum[1]+=mod;
            sum[1]=(sum[1]+tmp[1])%mod;

            query[0][++r[0]]=tmp[0];
            int u=(tmp[0]+sum[0])%mod;
            if (r[0]-l[0]+1==k) {sum[0]-=query[0][l[0]];tmp[1]=(tmp[1]+query[0][l[0]++])%mod;}
            if (sum[0]<0) sum[0]+=mod;
            sum[0]=(sum[0]+tmp[0])%mod;
            tmp[0]=u;

            tmp[1]=(tmp[1]+sum1)%mod;
        }
    }

    printf("%d\n",ans);
    return 0;
}

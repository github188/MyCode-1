#include<stdio.h>
#include<string.h>
long long a[10],c[10001][5],b[4];
char s[100000];
int mod=1000000007;
long long ans;

void work(int o,int p,int q)
{
    if (o>0)
    {
        if ((p>0)&&((p%9)==0))
        {
            int d[10];
            for (int i=0;i<10;i++) d[i]=0;
            for (int i=0;i<o;i++) d[b[i]]++;
            bool check=true;
            for (int i=0;i<10;i++)
            if (d[i]>a[i]) {check=false;break;}
            if (check)
            {
                long long sum=1;
                for (int i=0;i<10;i++) sum=(sum*c[a[i]][d[i]])%mod;
                ans=(ans+sum)%mod;
            }
        }
    }
    if (o<4)
    {
        for (int i=q;i<10;i++)
        {
            b[o]=i;
            work(o+1,p+i,i);
        }
    }
}

int main()
{
    int n;scanf("%d",&n);
    c[0][0]=1;
    for (int i=1;i<=10001;i++)
     for (int j=0;j<5;j++)
     {
        c[i][j]=c[i-1][j];
        if (j!=0) c[i][j]=(c[i][j]+c[i-1][j-1])%mod;
     }
    while (n>0)
    {
        n--;
        scanf("%s",&s);
        int len=strlen(s);
        int z=0;
        ans=0;
        for (int i=0;i<10;i++) a[i]=0;
        for (int i=0;i<len;i++) a[s[i]-'0']++;

        work(0,0,0);
        int ans1=ans;
        printf("%d\n",ans1);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
long long a[100001],f[101][101],g[2][101];
int c[100001],b[100];
long long mod = 1000000009;

long long ext_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){  x=1,y=0;  return a;  }
	long long d=ext_gcd(b,a%b,x,y) , temp=x;
	x=y,y=temp-a/b*y;  return d;
}


long long get_ni(long long a,long long p){ //∑µªÿx,ax=1 (mod p) apª•÷ 
	long long x,y;
	ext_gcd(a,p,x,y);
	return x;
}

int main()
{
    for (int i=1;i<=100000;i++)
    {
        a[i]=get_ni(i,mod);
        if (a[i]<0) a[i]+=mod;
    }
    int n,m,q,tt;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d%d",&n,&q);
        for (int i=0;i<n;i++) scanf("%d",&c[i]);
        while (q--)
        {
            scanf("%d",&m);
            for (int i=0;i<m;i++)b[i]=0;
            for (int i=0;i<n;i++)
            {
                int x=c[i];x%=m;if (x<0) x+=m;
                b[x]++;
            }
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<m;j++) f[i][j]=0;
                f[i][0]=1;
                int k=0;
                long long c=1;
                for (int j=1;j<=b[i];j++)
                {
                    k+=i;if (k>=m) k-=m;
                    c=(c*(long long)(b[i]-j+1)%mod*a[j])%mod;
                    f[i][k]=(f[i][k]+c);
                    if (f[i][k]>=mod) f[i][k]-=mod;
                }
            }
            for (int i=0;i<m;i++) g[0][i]=f[0][i];
            for (int i=1;i<m;i++)
            {
                for (int j=0;j<m;j++) g[1][j]=0;
                for (int j=0;j<m;j++)
                    for (int k=0;k<m;k++)
                    {
                        int t=(j+k);
                        if (t>=m) t-=m;
                        g[1][t]=(g[1][t]+g[0][j]*f[i][k])%mod;
                    }
                for (int j=0;j<m;j++) g[0][j]=g[1][j];
            }
            int ans=g[0][0];printf("%d\n",ans);
        }
    }
    return 0;
}

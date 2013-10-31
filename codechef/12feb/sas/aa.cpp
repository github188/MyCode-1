#include<iostream>
using namespace std;
long long a[50][50][256],d[50][256];

bool check(int o,int p,int q)
{
if (q>p) return true;
p=p-q;
while (p>0)
{
p--;
if ((o&1)==1) return false;
o/=2;
}
return true;
}

class DengklekBuildingRoads
{
public:
int numWays(int N, int M, int K)
{
long long mod=1000000007;
d[0][0]=1;
for (int i=0;i<M;i++)
for (int j=0;j<(1<<K);j++)
if (d[i][j]!=0)
{
for (int l=0;l<K;l++)
{
d[i+1][j^(1<<l)]+=d[i][j];
d[i+1][j^(1<<l)]%=mod;
}
}

a[1][0][0]=1;
for (int i=1;i<N;i++)
for (int j=0;j<=M;j++)
for (int k=0;k<(1<<K);k++)
if (a[i][j][k]!=0)
{
for (int x=0;x<=M-j;x++)
for (int y=0;y<(1<<K);y++)
if ((((k^y)&1)==0)
    &&(d[x][y]!=0)
    &&(check(y,K,i)))
{
int s=(k^y)/2;
if ((x&1)==1) s+=(1<<(K-1));
a[i+1][j+x][s]+=a[i][j][k]*d[x][y];
a[i+1][j+k][s]%=mod;
}

}

int ans=a[N][M][0];return ans;
}



} aa;

int  main()
{
    aa.numWays(4,3,3);
    return 0;
}

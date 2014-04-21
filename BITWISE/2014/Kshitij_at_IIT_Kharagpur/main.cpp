#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long mod=1000000007,ten=10;
long long f[10][10][5][5],g[100][5][5];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  	for (int i=0;i<10;i++)
      for (int j=0;j<10;j++)
      	for (int k=0;k<10;k++)
      		for (int l=0;l<10;l++)
      		{
      			int t=i;
      			t=(t+j)%10;
      			t=(t+k)%10;
      			t=(t+l)%10;
      			int s=i+j+k+l;
      			for (int h=0;h<5;h++) f[(s+h)%10][t][(s+h)/10][h]++;
    		}
  	long long u,v;cin>>u>>v;
  	for (int i=0;i<5;i++) g[0][i][0]=f[u%ten][v%ten][i][0];
  	u/=ten;v/=ten;int p=0;
  	while (u>0)
    {
      long long u1=u%ten,v1=v%ten;u/=ten;v/=ten;
      for (int i=0;i<5;i++) for (int j=0;j<5;j++) for (int k=0;k<5;k++) g[p+1][i][j]=(g[p+1][i][j]+g[p][j][k]*f[u1][v1][i][j]%mod)%mod;
      p++;
    }
  	long long ans=0;
  	for (int i=0;i<5;i++) ans+=g[p][0][i];
  	cout<<ans<<endl;
    return 0;
}

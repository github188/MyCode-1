#include<fstream>
using namespace std;

long long n,m,k,ans;
long long mod=1000000007;
long long stir[1001][1001];

int main()
{
    stir[1][1]=1;
    for (int i=2;i<=1000;i++)
     for (int j=1;j<=i;j++)
     {
         long long k=j;
         stir[i][j]=(stir[i-1][j-1]+stir[i-1][j]*k)%mod;
     }

    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int tt;
    fin>>tt;
    while (tt>0)
    {
        tt--;
        fin>>n>>m>>k;
        ans=0;
        if (k>n) k=n;
        if (k>m) k=m;
        long long p=1;
        for (int i=1;i<=k;i++)
        {
            p=(p*m)%mod;m--;
            ans=(ans+p*stir[n][i])%mod;
        }

        fout<<ans<<endl;
    }
    return 0;
}

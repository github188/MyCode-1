#include<string.h>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
int n,k,c;

inline int work(int n,int k,int c)
{
    for (int a1=1;a1<=n;a1++)
    {
        int a2=n-a1;
        int b2=k/a2;
        int b1=(k-a2*b2)/a1;
        if (((k-a2*b2)%a1)!=0) b1++;
        if (b1<b2) return a1;
    }
}

int main()
{
    fin.open("coins_game.txt");
    fout.open("out.txt");
    int tt;
    fin>>tt;
    for (int t=1;t<=tt;t++)
    {
        fin>>n>>k>>c;
        fout<<"Case #"<<t<<": ";
        if (c<=k/n*n) {fout<<c<<endl;}
        else {fout<<c+work(n,k,c)<<endl;}
    }
    return 0;
}

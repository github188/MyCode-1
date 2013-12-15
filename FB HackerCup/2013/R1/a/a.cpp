#include<string.h>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;

long long n;
long long a[100];
string s;

void work(long long o,long long p)
{
    if (p==1) {fout<<s[o];return;}
    int q=0;
    while (o>=a[p]) {q++;o-=a[p];}
    fout<<s[q];work(o,p-1);
}

int main()
{
    fin.open("labelmaker.txt");
    fout.open("out.txt");
    int tt;
    fin>>tt;
    for (int t=1;t<=tt;t++)
    {
        fin>>s>>n;n--;
        long long u=1,v=1,l=s.length();
        while (u<=n/l)
        {
            u*=l;v++;n-=u;
        }
        a[1]=1;
        for (int i=2;i<=v;i++) a[i]=a[i-1]*l;
        fout<<"Case #"<<t<<": ";
        work(n,v);fout<<endl;
    }
    return 0;
}

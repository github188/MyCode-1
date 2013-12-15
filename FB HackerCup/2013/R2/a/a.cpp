#include<iostream>
#include<fstream>
#include<set>
using namespace std;
set<long long> s1,s2;
ifstream fin;
ofstream fout;
long long n,m,a1,a2,b1,b2,c1,c2,x1,x2,y1,y2,r1,r2,k1,k2;
long long p1[1000000],p2[1000000];

inline long long getNext(long long x1,long long x2,long long a,long long b,long long c,long long r)
{
    return (a*x1%r+b*x2%r+c)%r;
}

int main()
{
    fin.open("_magic_pairs.txt");
    fout.open("output.txt");
    int tt;fin>>tt;
    for (int t=1;t<=tt;t++)
    {
        fin>>n>>m;
        fin>>x1>>a1>>b1>>c1>>r1;
        fin>>x2>>a2>>b2>>c2>>r2;
        p1[0]=x1;p2[0]=x2;
        for (int i=1;(i<n)||(i<m);i++)
        {
            if (i<n) p1[i]=getNext(p1[i-1],p2[(i-1)%m],a1,b1,c1,r1);
            if (i<m) p2[i]=getNext(p1[(i-1)%n],p2[i-1],a2,b2,c2,r2);
        }
        s1.clear();
        s2.clear();
        long long h1,h2;h1=h2=0;
        long long one=1,ans=0;k1=k2=0;
        while ((h1<n)||(h2<m))
        {
            long long u=1,v=1;
            if (h1<n)
            {
                s1.insert(p1[h1]);
                if (s2.find(p1[h1])==s2.end()) {k1++;} else {k2--;}
                h1++;
                while ((h1<n)&&(s1.find(p1[h1])!=s1.end()))
                {
                    h1++;u++;
                }
            }
            if (h2<m)
            {
                s2.insert(p2[h2]);
                if (s1.find(p2[h2])==s1.end()) k2++; else k1--;
                h2++;
                while ((h2<m)&&(s2.find(p2[h2])!=s2.end()))
                {
                    h2++;v++;
                }
            }
            if ((k1==0)&&(k2==0)) ans=ans+u*v;
        }
        fout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

#include<iostream>
#include<math.h>
using namespace std;

class FoxAndGCDLCM
{
public:
long long get(long long G, long long L)
{
long long a,b,ans,q,v;
if ((L%G)!=0) return -1;
ans=-1;v=L/G;q=sqrt(v);q++;
for (long long i=1;i<=q;i++)
if ((v%i)==0)
{
long long t=v/i;t+=i;
long long hh=G*t;
if (hh<6200000)
{
    int p=0;
}
if ((ans<0)||(hh<ans)) ans=hh;
}
return ans;
}

} aa;
int main()
{
    aa.get(10,950863963000);
    return 0;
}

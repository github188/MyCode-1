#include<stdio.h>
#include<set>
using namespace std;
unsigned int a[100000];
int n,k;
unsigned int one=1,ans=0;
set<unsigned int> s;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        unsigned int u,v,w,x;
        scanf("%d.%d.%d.%d",&u,&v,&w,&x);
        a[i]=((u<<24)|(v<<16)|(w<<8)|x);
    }
    unsigned int f=0;bool ok=false;
    for (int i=31;i>=0;i--)
    {
        if (i!=32) f|=(one<<i);
        s.clear();
        for (int j=0;j<n;j++) s.insert(f&a[j]);
        if (s.size()==k) {ok=true;break;}
    }
    if (!ok) printf("-1\n");
    else
    {
        int b[4];
        for (int i=3;i>=0;i--) {b[i]=(f&((one<<8)-1));f>>=8;}
        for (int i=0;i<3;i++) printf("%d.",b[i]);printf("%d\n",b[3]);
    }
    return 0;
}

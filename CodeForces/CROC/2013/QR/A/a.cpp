#include<stdio.h>
#include<map>
using namespace std;
map<int,int> a;
int ans,n;

int main()
{
    scanf("%d",&n);ans=0;
    a.clear();
    while (n--)
    {
        int x;scanf("%d",&x);
        if (x==0) continue;
        a[x]++;
    }
    for (map<int,int>::iterator i=a.begin();i!=a.end();i++)
    {
        if (i->second>2) {ans=-1;break;}
        if (i->second==2) {ans++;}
    }
    printf("%d\n",ans);
    return 0;
}

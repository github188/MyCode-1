#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

set<int> a[1000001];
map<set<int>,int> b;
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) a[i].clear();
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].insert(y);
        a[y].insert(x);
    }
    b.clear();

    for (int i=1;i<=n;i++)
    {
        map<set<int>,int>::iterator it=b.find(a[i]);
        if (it==b.end())
        {
            b.insert(make_pair(a[i],1));
        } else
        {
            it->second++;
        }
        a[i].insert(i);
        it=b.find(a[i]);
        if (it==b.end())
        {
            b.insert(make_pair(a[i],1));
        } else
        {
            it->second++;
        }
        a[i].erase(i);
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        long long sum=0;
        map<set<int>,int>::iterator it=b.find(a[i]);
        sum+=it->second;
        a[i].insert(i);
        it=b.find(a[i]);
        sum+=it->second;
        sum-=2;
        ans+=sum;
    }
    long long u=2;ans/=u;

    printf("%I64d\n",ans);
    return 0;
}

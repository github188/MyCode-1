#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

struct node
{
    int x,y,z;
    bool operator<(const node b) const
    {
        if (x<b.x) return true;
        if (x>b.x) return false;
        if (y<b.y) return true;
        return false;
    }
} customer[200000];

int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        int n,k;scanf("%d%d",&n,&k);
        for (int i=0;i<n;i++)
        {
            int s,t,p;
            scanf("%d%d%d",&s,&t,&p);
            customer[i].x=t;customer[i].y=p;customer[i].z=s;
        }
        sort(customer,customer+n);
        map<int,int> used;used.clear();
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (used[customer[i].y]<=customer[i].z)
            {
                ans++;
                used[customer[i].y]=customer[i].x;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>
#include<map>
using namespace std;

struct st
{
    int f,b,c;
};

map<int,st> a;

int main()
{
    a.clear();
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        map<int,st>::iterator it=a.find(x);
        if (x==y)
        {
                if (it!=a.end())
                {
                     it->second.c++;
                } else
                {
                     st s;s.f=0;s.b=0;s.c=1;
                     a.insert(make_pair<int,st>(x,s));
                }
        }
        if (it!=a.end())
        {
            it->second.f++;
        } else
        {
            st s;s.f=1;s.b=0;s.c=0;
            a.insert(make_pair<int,st>(x,s));
        }
        it=a.find(y);
        if (it!=a.end())
        {
            it->second.b++;
        } else
        {
            st s;s.f=0;s.b=1;s.c=0;
            a.insert(make_pair<int,st>(y,s));
        }
    }

    int ans=-1;
    int n2=n/2+(n&1);
    for (map<int,st>::iterator i=a.begin();i!=a.end();i++)
    {
        int x=i->second.f,y=i->second.b,z=y=i->second.c;
        if (i->second.f+i->second.b>=n2)
        {
            if (x+z>=n2) y=0;
            else {y=n2-x-z;}
            if ((ans==-1)||(y<ans)) ans=y;
        }
    }
    printf("%d\n",ans);
    return 0;
}

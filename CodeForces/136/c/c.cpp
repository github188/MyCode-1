#include<stdio.h>
#include<map>
using namespace std;
int a[100001],b[100001],posa[100001],posb[100001],tot[2],belong[100001];
int n;
map<int,int> t[2];

int min(int o,int p)
{
    return (o<p?o:p);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        posa[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        posb[b[i]]=i;
    }
    for (int i=1;i<=n;i++)
    if (posa[i]<=posb[i])
    {
        t[0].insert(make_pair(i,posb[i]-posa[i]));
        belong[i]=0;
    } else
    {
        t[1].insert(make_pair(i,posa[i]-posb[i]));
        belong[i]=1;
    }
    for (int i=1;i<=n;i++)
    {
        map<int,int>::iterator it1=t[0].begin(),it2=t[1].begin();
        int o=it1->second,p=it1->second;
        printf("%d\n",min(it1->second-i+1,it2->second+i-1));
        while (t[0].begin()->second-i+1==0)
        {
            map<int,int>::iterator it=t[0].begin();
            t[1].insert(make_pair(it->first,1-i));
            t[0].erase(it);
        }
        it1=t[1].find(b[i]);
        if (it1!=t[1].end())
        {
            t[0].insert(make_pair(it1->first,n-posa[it1->first]+i));
            t[1].erase(it1);
        }
    }

    return 0;
}

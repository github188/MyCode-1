#include<stdio.h>
#include<map>
using namespace std;
long long a[100001];
map<int,int> data;

int calc(int o)
{
    int ans=0;
    while (o>0)
    {
        if ((o%10)==4) ans++;
        if ((o%10)==7) ans--;
        o/=10;
    }
    return ans;
}

int main()
{
    data.clear();
    data.insert(make_pair(0,1));
    int sum=0;a[0]=0;
    for (int i=1;i<=100000;i++)
    {
        int tmp=calc(i);
        sum+=tmp;
        map<int,int>::iterator it=data.find(sum);
        if (it==data.end())
        {
            data.insert(make_pair(sum,1));
            a[i]=a[i-1];
        } else
        {
            long long tmp=it->second;
            a[i]=a[i-1]+tmp;
            it->second++;
        }
    }

    int tt;scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int m;scanf("%d",&m);
        printf("%I64d\n",a[m]);
    }

    return 0;
}

#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#include<functional>
using namespace std;
long long f[2000000];
int n,k;
long long a,b,c,r;
priority_queue< int,vector<int>,greater<int> > heap;
int hash[100010];

int main()
{
    freopen("3.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&k);n--;
        scanf("%d%d%d%d",&a,&b,&c,&r);
        printf("Case #%d:",t);
        while (!heap.empty()) heap.pop();
        memset(hash,0,sizeof(hash));
        f[0]=a;if (a<=k) hash[a]++;
        for (int i=1;i<k;i++)
        {
            f[i]=(b*f[i-1]+c)%r;
            if (f[i]<=k) hash[f[i]]++;
        }
        for (int i=0;i<=k;i++)
        if (hash[i]==0) heap.push(i);
        for (int i=k;i<=(k+1)*13;i++)
        {
            f[i]=heap.top();
            heap.pop();
            if (f[i]<=k) hash[f[i]]++;
            if (f[i-k]<=k)
            {
                hash[f[i-k]]--;
                if (hash[f[i-k]]==0) heap.push(f[i-k]);
            }
        }

        if (n<=(k+1)*13) printf("%d\n",f[n]);
        else
        {
            n-=13*(k+1);n%=(k+1);
            printf("%d\n",f[12*(k+1)+n]);
        }

        //for (int i=0;i<=13*k;i++) printf("%d %d\n",i,f[i]);
    }
    return 0;
}

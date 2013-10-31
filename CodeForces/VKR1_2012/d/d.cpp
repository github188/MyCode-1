#include<stdio.h>
#include<iostream>
using namespace std;
long long a[50001][501];
int v[50001],e[200000][2];
int n,k,tot;
long long ans;

void work(int o,int p)
{
    int j=v[o];
    while (j!=0)
    {
        if (e[j][0]!=p)
        {
            int q=e[j][0];
            work(q,o);
            for (int i=1;i<=k;i++) a[o][i]+=a[q][i-1];
        }
        j=e[j][1];
    }
    ans+=a[o][k];
    j=v[o];long long sum=0,two=2;
    while (j!=0)
    {
        if (e[j][0]!=p)
        {
            int q=e[j][0];
            for (int i=1;i<k;i++)
            if (a[q][i-1]!=0)
            {
                long long h=(a[o][k-i]-a[q][k-i-1]);
                sum+=a[q][i-1]*h;
            }
        }
        j=e[j][1];
    }
    sum/=two;ans+=sum;
    a[o][0]=1;
}

int main()
{
    scanf("%d%d",&n,&k);tot=1;
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[tot][0]=y;
        e[tot][1]=v[x];
        v[x]=tot;
        tot++;

        e[tot][0]=x;
        e[tot][1]=v[y];
        v[y]=tot;
        tot++;
    }

    work(1,0);
    cout<<ans<<endl;
    return 0;
}

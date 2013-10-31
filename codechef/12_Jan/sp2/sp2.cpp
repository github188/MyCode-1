#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

long long f[100];
bool use[100000];

int main()
{
    /*
    freopen("1.txt","w",stdout);
    for (int i=3;i<=10000;i+=2)
    {
        int x=2,y=1;
        while (x!=1)
        {
            x=(x*2)%i;
            y++;
        }
        printf("%d %d\n",i,y);
    }*/
    /*
    long long ans=0;
    long long up=100;up*=up;
    long long ff=1;
    while (ff<up)
    {
        memset(f,0,sizeof(f));
        ff++;
        long long hh;
        hh=1;int gg=0;
        while (hh<=ff)
        {
            hh=hh+hh;
            gg++;
        }
        hh=(hh>>1);
        gg--;
        f[gg]=1;
        for (int i=gg-1;i>=0;i--)
        {
          hh=(hh>>1);
          f[i]=ff/hh;
          for (int j=gg;j>i;j--)
          {
              long long k=1+j-i;
              f[i]-=f[j]*k;
          }
        }
        long long sum=0;
        for (int i=gg;i>=0;i--) sum+=f[i];
        if (sum>ans)
        ans=sum;
    }

    cout<<ans<<endl;
    */
    freopen("1.txt","w",stdout);
    for (int i=1;i<=10000;i++)
    {
        memset(use,false,sizeof(use));
        int m=i*2+1,ans=0;
        for (int j=1;j<m;j++)
        if (!use[j])
        {
            int k=j;ans++;
            while (!use[k])
            {
                use[k]=true;
                k=(k<<1);
                if (k>=m) k-=m;
            }
        }
        printf("%d %d\n",i,ans);
    }
    return 0;
}

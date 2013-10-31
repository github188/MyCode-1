#include<stdio.h>
#include<iostream>
using namespace std;
int t,n,m,k;
long long mod=1000000007;

int main()
{
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d%d%d",&n,&k,&m);
        if (n==1)
        {
            long long ans=m,mm=m-1;
            for (int i=1;i<k;i++)
            {
                ans=(ans*mm)%mod;
            }
            cout<<ans<<endl;
        } else
        {
            if (m<2) {printf("0\n");continue;}
            long long ans=m*(m-1),mm=(m-2)*(m-2)+(m-1);
            for (int i=1;i<k;i++)
            {
                ans=(ans*mm)%mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

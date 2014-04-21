#include<iostream>
using namespace std;

int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n;long long ans=0;
        cin>>n;
        for (int i=1;i<=n/2;i++)
        {
            int temp=i*(n-i)-1;
            long long sum=0;
            for (int j=1;j*j<=temp;j++) sum+=(long long)(2*(temp/j-j)+1);
            ans+=sum;
            if (i<n-i) ans+=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}

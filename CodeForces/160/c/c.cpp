#include<iostream>
using namespace std;
long long a[52][52];
long long n,t;
long long len[100];

int main()
{
    long long ans=0;
    cin>>n>>t;
    long long aa=1,b=0;
    while (aa!=t) {aa+=aa;b++;if (aa>t) break;}
    if (aa!=t)
    {
        cout<<ans<<endl;
        return 0;
    }
    len[0]=2;a[0][0]=a[0][1]=1;ans=a[0][b];n-=2;
    int m;
    for (int i=1;i<52;i++)
    {
        if (len[i-1]+len[i-1]>n) break;
        m=i;
        for (int j=0;j<52;j++) a[i][j]=a[i-1][j];
        for (int j=1;j<52;j++) a[i][j]+=a[i-1][j-1];
        len[i]=len[i-1]+len[i-1];
        n-=len[i];
        ans+=a[i][b];
    }int u=0;
    while (n>0)
    {
        if (n==1)
        {
            n=0;
            if (b+u==0) ans++;
            break;
        }
        while (len[m]>n) m--;
        ans+=a[m][b+u];n-=len[m];u++;
    }

    cout<<ans<<endl;
    return 0;
}

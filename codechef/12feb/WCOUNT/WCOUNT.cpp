#include<iostream>
#include<string.h>
using namespace std;
long long b[500],c[501][500],d[500];
string s;
int a[52];

long long gcd(long long a,long long b)
{
    if (a<b) {long long c=a;a=b;b=c;}
    if (b==0) return a;return gcd(b,a%b);
}

int main()
{
    int tt;cin>>tt;
    int num=0;
    for (int i=2;i<=500;i++)
    {
        bool check=true;
        for (int j=2;j<=i-1;j++)
        if ((i%j)==0) {check=false;break;}
        if (check) {b[num]=i;num++;}
    }
    c[2][0]=1;
    for (int i=3;i<=500;i++)
    {
        for (int j=0;j<num;j++)c[i][j]=c[i-1][j];
        int k=i;
        for (int j=0;j<num;j++)
        {
            while ((k%b[j])==0)
            {
                c[i][j]++;
                k/=b[j];
            }
            if (k==1) break;
        }
    }

    while (tt>0)
    {
        tt--;
        cin>>s;long long len=s.length();
        int m=len;for (int i=0;i<num;i++) d[i]=c[m][i];
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++)
        {
            if ((s[i]>='A')&&(s[i]<='Z'))
            {
                a[s[i]-'A']++;
            } else {a[26+s[i]-'a']++;}
        }
        for (int i=0;i<52;i++)
        if (a[i]>1)
        {
            for (int j=0;j<num;j++) d[j]-=c[a[i]][j];
        }
        long long mod=1000000007,ans=1;
        for (int i=0;i<num;i++)
        {
            long long tmp=b[i];
            for (int j=0;j<d[i];j++) ans=(ans*tmp)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

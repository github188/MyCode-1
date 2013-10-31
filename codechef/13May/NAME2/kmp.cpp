#include<iostream>
#include<string.h>
#define N 30000
using namespace std;
struct KMP
{
    int kmp(string s,string t)
    {
        int n=s.length(),m=t.length(),o=0;
        for (int i=0;i<m;i++)
        {
            if (s[o]==t[i])
            {
                o++;if (o==n) return 1;
            }
        }
        return -1;
    }
} g;

int main()
{
    int tt;cin>>tt;
    while (tt--)
    {
        string s,t;
        cin>>s>>t;
        int ans;
        if (s.length()<t.length()) ans=g.kmp(s,t); else ans=g.kmp(t,s);
        if (ans<0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
    return 0;
}

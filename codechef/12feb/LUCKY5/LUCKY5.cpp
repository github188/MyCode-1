#include<string.h>
#include<iostream>
using namespace std;
int n;
string s;

int main()
{
    cin>>n;
    while (n>0)
    {
        n--;
        cin>>s;int len=s.length();
        int ans=0;
        for (int i=0;i<len;i++)
        if ((s[i]!='4')&&(s[i]!='7')) ans++;
        cout<<ans<<endl;
    }
    return 0;
}

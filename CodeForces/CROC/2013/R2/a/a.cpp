#include<string.h>
#include<iostream>
using namespace std;
string ss,t;
int a[4];

int main()
{
    int n;cin>>n>>ss>>t;
        int f=0,s=0;
    for (int i=0;i<n+n;i++)
    {
        if (ss[i]==t[i])
        {
            if (ss[i]=='0') a[0]++; else {a[3]++;}
        } else
        {
            if (ss[i]=='0') a[2]++; else {a[1]++;}
        }
    }
        if (a[3]&1)
        {
            f++;
            if (a[2]>0) {s++;a[2]--;} else {a[1]--;}
        }
        while ((a[1]>0)||(a[2]>0))
        {
            if (a[1]>0) {a[1]--;f++;} else a[2]--;
            if (a[1]+a[2]==0) break;
            if (a[2]>0) {a[2]--;s++;} else a[1]--;
        }
        if (f>s) cout<<"First"<<endl; else
        if (f<s) cout<<"Second"<<endl; else cout<<"Draw"<<endl;

    return 0;
}

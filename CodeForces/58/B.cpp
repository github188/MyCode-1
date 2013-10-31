#include<iostream>
#include<string.h>
using namespace std;
int a[200],b[900000];
int n,k;
string s,t;

int min(int o,int p)
{
    if (o<p) {return o;} return p;
}

int main()
{
    cin>>n>>k;
    cin>>s;int l=s.length();
    while (n>0)
    {
          n--;
          long long ans = 0;
          cin>>t;int len=t.length();int oo=1000000;
          for (int i=0;i<200;i++) {a[i]=-1;}
          for (int i=0;i<len;i++)
          {
              if (i<l) {a[s[i]]=i;}
              if (a[t[i]]==-1) {b[i]=oo;} else {b[i]=i-a[t[i]];}
          }
          for (int i=0;i<200;i++) {a[i]=-1;}
          for (int i=l-1;i>=0;i--)
          {
              a[s[i]]=i;
              if (i<len) if (a[t[i]]==-1) {b[i]=min(b[i],oo);} else {b[i]=min(b[i],a[t[i]]-i);}
          }
          for (int i=0;i<len;i++) {long long u=b[i];if (u==oo) {u=len;} ans+=u;}
          
          cout<<ans<<endl;
    }
    
    return 0;
}

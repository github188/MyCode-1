#include<iostream>
using namespace std;
long long n,m,a,b,x,y,x1,y1,x2,y2;

long long gcd(long long o,long long p)
{
    if (o<p) {long long q=o;o=p;p=q;}
    if (p==0) return o;
    return gcd(p,o%p);
}
long long two=2;
int main()
{
    cin>>n>>m>>x>>y>>a>>b;
    long long c=gcd(a,b);
    a/=c;b/=c;
    long long k=n/a;
    k=k<m/b?k:m/b;
    if (x-(a*k/two+(a*k%two))+a*k<=n) x1=x-(a*k/two+(a*k%two)); else x1=n-a*k;
    if (y-(b*k/two+(b*k%two))+b*k<=m) y1=y-(b*k/two+(b*k%two)); else y1=m-b*k;
    if (x1<0) x1=0;if (y1<0) y1=0;
    cout<<x1<<" "<<y1<<" "<<x1+a*k<<" "<<y1+b*k<<endl;
    return 0;
}

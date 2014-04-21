#include<iostream>
using namespace std;
long long one=1;
long long work(long long a,long long b)
{
    if (a==0) if (b==0) return 0; else return -1;
    if ((b>a)&&(a>0)) return -1;
    if (b==0) return -1;
    return (b-one)+(a-b+one)*(a-b+one);
}
long long work_min(long long a,long long b)
{
    if (a==0) if (b==0) return 0; else return -1;
    if ((b>a)&&(a>0)) return -1;
    if (b==0) return -1;
    return (a/b)*(a/b)*(b-a%b)+(a/b+one)*(a/b+one)*(a%b);
}

int main()
{
    long long a,b,x,y;cin>>a>>b;
    long long ans=100000;ans=ans*ans;ans=-ans;
    for (int i=0;i<=a+1;i++)
    {
        long long a1=work(a,i),b1=work_min(b,i);
        if ((a1>=0)&&(b1>=0)&&(a1-b1>ans)) {ans=a1-b1;x=i;y=i;}
        a1=work(a,i+1),b1=work_min(b,i);
        if ((a1>=0)&&(b1>=0)&&(a1-b1>ans)) {ans=a1-b1;x=i+1;y=i;}
        a1=work(a,i),b1=work_min(b,i+1);
        if ((a1>=0)&&(b1>=0)&&(a1-b1>ans)) {ans=a1-b1;x=i;y=i+1;}
    }
    cout<<ans<<endl;
    long long a1=0,b1=0;
    while ((a1<x)||(b1<y))
    {
        if (y-b1>x-a1)
        {
            if (b%y>b1) cout<<"x";
            b1++;
            for (int i=0;i<b/y;i++) cout<<"x";
        } else
        {
            if (a1==0)
            {
                for (int i=0;i<a-x+one;i++) cout<<"o";
            } else cout<<"o";
            a1++;
        }
    }
    cout<<endl;
    return 0;
}

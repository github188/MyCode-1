#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
string s;

bool check(int l,int r)
{
    int a,b,c;a=b=c=0;
    for (int i=l;i<=r;i++)
    if (s[i]=='8') {a++;}
    else if (s[i]=='5') {b++;}
         else if (s[i]=='3') {c++;} else {return false;}
    if ((a>=b)&&(b>=c)) return true;
    return false;
}

int main()
{
    int n,x;
    cin>>n;
    getline(cin,s);x=0;
    for (int i=0;i<n;i++)
    {
        getline(cin,s);
        int len=s.length();int l=len-1;
        while ((s[l]<'0')||(s[l]>'9')) l--;int r=l;
        while (s[l]!=' ') l--;l++;
        if (check(l,r)) x++;
    }
    cout<<x<<endl;

    return 0;
}

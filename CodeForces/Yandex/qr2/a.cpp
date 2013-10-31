#include<stdio.h>
#include<iostream>
using namespace std;
long long a[40];
long long n;

int f(int i)
{
    if (n<=a[i]) {cout<<"Sheldon"<<endl;return 0;}n-=a[i];
    if (n<=a[i]) {cout<<"Leonard"<<endl;return 0;}n-=a[i];
    if (n<=a[i]) {cout<<"Penny"<<endl;return 0;}n-=a[i];
    if (n<=a[i]) {cout<<"Rajesh"<<endl;return 0;}n-=a[i];
    if (n<=a[i]) {cout<<"Howard"<<endl;return 0;}n-=a[i];
}

int main()
{
    a[0]=1;
    long long one=1;
    long long two=2;
    long long five=5;
    for (int i=1;i<=40;i++) {a[i]=a[i-1]*two;}
    cin>>n;
    int i=1;
    while (five*(a[i]-one)<n) {i++;}
    i--;n-=five*(a[i]-one);
    f(i);
    return 0;
}

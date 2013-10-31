#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int a[1001],b[1001];
double ans;
int n,tt;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&tt);
    for (int ttt=1;ttt<=tt;ttt++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) {scanf("%d",&a[i]);b[i]=a[i];}
        sort(b,b+n);
        int m=0
    }
    return 0;
}

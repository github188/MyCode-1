#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int ans,n,s;
int a[20001];

int main()
{
    scanf("%d%d",&n,&s);
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);}
    sort(a,a+n);
    ans=0;int k=n-1;
    for (int i=0;i<n;i++)
    {
        while ((k>=0)&&(a[k]+a[i]>s)) {k--;}
        ans+=k+1;
        if (k>=i) {ans--;}
    }
    ans/=2;
    printf("%d\n",ans);
    return 0;
}

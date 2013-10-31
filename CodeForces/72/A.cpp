#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int a[100001],b[100001];


int main()
{
    scanf("%d",&n);b[0]=0;
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);b[i]=1;if ((i>0)&&(a[i]==a[i-1])) {b[i]=b[i-1]+1;} }
    long long ans,q;ans=0;
    for(int i=0;i<n;i++) {q=b[i];ans+=q;}
    cout<<ans<<endl;
    return 0;
}

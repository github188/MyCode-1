#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);if (a[n-1]!=1) {a[n-1]=1;} else {a[n-1]=2;}
    sort(a,a+n);
    for (int i=0;i<n-1;i++) printf("%d ",a[i]);printf("%d\n",a[n-1]);
    return 0;
}
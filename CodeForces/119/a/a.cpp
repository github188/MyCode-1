#include<stdio.h>

int a[200000],b[200000],c[200000];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);a[i]--;}
    for (int i=0;i<n;i++) {scanf("%d",&b[i]);c[b[i]-1]=i;}
    for (int i=0;i<n;i++) a[i]=c[a[i]];

    int ans=1;
    for (int i=1;i<n;i++)
    if (a[i]>a[i-1]) {ans++;} else {break;}


    printf("%d\n",n-ans);
    return 0;
}

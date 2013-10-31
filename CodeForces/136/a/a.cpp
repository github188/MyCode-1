#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000],b[100000];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    bool check=true;
    int k=0;
    for (int i=1;i<n;i++) if (a[i]<a[i-1]) {check=false;k=i;break;}
    if (!check)
    {
        for (int i=0;i<n;i++) b[i]=a[i];
        sort(a,a+n);
        int l=0,h=0;
        for (int i=0;i<n;i++) if (a[i]!=b[i]) {l++;h=i;}
        if (l>2) {check=false;}
        else  check=true;
    }
    if (check) {printf("YES\n");}
    else printf("NO\n");
    return 0;
}

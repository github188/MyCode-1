#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct st
{
    int del;
    double x;
};
int n;
double l,v1,v2;
double a[100000],ans[100001];
st b[200001];

int main()
{
    scanf("%d%lf%lf%lf",&n,&l,&v1,&v2);
    int m=0;
    for (int i=0;i<n;i++) scanf("%lf",a[i]);
    sort(a,a+m);
    double te=2*l/v1,tb=0;


    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
int a[5000001],stack[5000001];
int n,top;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) a[i]=i;
    int h=1;top=0;int m=n;
    for (int i=2;i<=n;i++)
    {
        int u=n%i;
        int j=h,uu=a[j];
        while (j+i<=m)
        {
            int v=a[j+i];a[j+i]=uu;j+=i;uu=v;
        }
        a[++m]=uu;
        h++;
    }
    while (top>0) a[++m]=stack[--top];
    for (int i=h;i<m;i++) printf("%d ",a[i]);printf("%d\n",a[m]);
    //cout<<m<<endl;
    return 0;
}

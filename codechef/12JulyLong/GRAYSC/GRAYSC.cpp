#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
    unsigned long long v;
    int p;
} f[100000];
unsigned long long a[100000],b[100000];
bool c[100000];
int n;

bool cmp(node a,node b)
{
    return (a.v<b.v)|((a.v==b.v)&&(a.p<b.p));
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        //scanf("%d",&a[i]);
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for (int i=1;i<n;i++)
    {
        f[i].v=(a[i-1]^a[i]);
        f[i].p=i;
    }
    sort(f+1,f+n,cmp);

    bool check=false;
    //for (int i=0;i<=n-4;i++) if ((b[i]==b[i+1])&&(b[i]==b[i+2])&&(b[i]==b[i+3])) check=true;
    int tmp=0;
    for (int i=1;i<n;i++)
    if ((b[i]==b[i-1])&&(!c[i-1]))
    {
        tmp++;
        c[i]=true;
    }
    if (tmp>1) check=true;
    for (int i=1;i<n-1;i++)
    if ((f[i].v==f[i+1].v)&&(f[i].p+1!=f[i+1].p)&&(f[i].p-1!=f[i+1].p)) check=true;
    if (check) {printf("Yes\n");} else {printf("No\n");}
    return 0;
}

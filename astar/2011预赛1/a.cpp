#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
long long ans,x,y;

int main()
{
    scanf("%d%d",&n,&m);ans=x=y=0;
    for (int i=0;i<m;i++)
    {
        int k;scanf("%d",&k);
        if (k>1) {x++;k-=2;}
        y+=k;
    }
    y=x+y;
    ans=x*y;
    cout<<ans<<endl;
    return 0;
}

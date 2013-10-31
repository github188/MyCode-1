#include<stdio.h>
#include<iostream>
using namespace std;
int n;

int main()
{
    int tt,cc,n;
    long long lt=0,size=0,ans=0;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d%d",&tt,&cc);long long t=tt,c=cc;
        if (t-lt>=size) size=0; else size-=t-lt;
        lt=t;size+=c;
        ans=ans>size?ans:size;
    }
    lt+=size;cout<<lt<<" "<<ans<<endl;
    return 0;
}

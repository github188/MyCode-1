#include<stdio.h>
#include<iostream>
using namespace std;
long long p=1000000007;
long long a[100001],b[100001],c[100001];
int n,bn,cn;
long long ans;

long long mul(long long o,long long pp)
{
    if (pp==1) return o;
    long long ans=mul(o,pp>>1);
    ans=ans*ans%p;
    if (pp&1) ans=ans*o%p;
    return ans;
}

void work(int n)
{
    long long max=a[c[1]],min=a[b[1]],pos=1;
    int bh=1,ch=1;
    while ((bh<=bn)||(ch<=cn))
    {
        long long x,y;
        if (bh>bn) x=n+1; else x=b[bh];
        if (ch>cn) y=n+1; else y=c[ch];
        if (x<y)
        {
            ans=ans*mul(max-min,x-pos+1)%p;
            pos=x+1;bh++;
            if (bh<=bn) min=a[b[bh]]; else min=a[b[bn]];

        } else
        {
            ans=ans*mul(max-min,y-pos+1)%p;
            pos=y+1;ch++;
            if (ch<=cn) max=a[c[ch]]; else min=a[c[cn]];
        }
        if (pos>=n) break;
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    bool mark=false;
    for (int i=2;i<=n;i++) if (a[i]==a[i-1]) mark=true;
    if (!mark)
    {
        bn=cn=1;ans=1;
        b[1]=c[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (a[i]<a[i-1]) while ((bn>0)&&(a[b[bn]]>a[i])) bn--;
            else while ((cn>0)&&(a[c[cn]]<a[i])) cn--;
            if (a[i]<a[i-1]) b[++bn]=i; else c[++cn]=i;
            //long long tmp=bn+cn;ans+=tmp;
            work(i);
            if (ans==0)
            {
                int o=1;
            }
            if (a[i]>a[i-1]) b[++bn]=i; else c[++cn]=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
